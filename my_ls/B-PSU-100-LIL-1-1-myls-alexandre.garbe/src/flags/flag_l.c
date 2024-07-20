/*
** EPITECH PROJECT, 2023
** B-PSU-100-LIL-1-1-myls-alexandre.garbe
** File description:
** flag_l
*/

#include "../../lib/my/my.h"

static void print_rights(struct stat *statfile)
{
    my_putchar((S_ISDIR(statfile->st_mode)) ? 'd' : '-');
    my_putchar((statfile->st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((statfile->st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((statfile->st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((statfile->st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((statfile->st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((statfile->st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((statfile->st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((statfile->st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((statfile->st_mode & S_IXOTH) ? 'x' : '-');
    my_putchar('.');
    my_putchar(' ');
}

static void time_getter(struct stat *statfile)
{
    char *time = ctime(&statfile->st_mtime);
    int i = 4;

    while (i < 14) {
        my_putchar(time[i]);
        i++;
    }
}

static void link_getter(struct stat *statfile)
{
    my_put_nbr(statfile->st_nlink );
    my_putchar(' ');
}

static void print_size(struct stat *statfile)
{
    my_put_nbr(statfile->st_size);
    my_putchar(' ');
}

void get_uid(struct stat *statfile)
{
    struct passwd *pwd;

    pwd = getpwuid(statfile->st_uid);
    mini_printf("%s", pwd->pw_name);
    my_putchar(' ');
}

void get_gid(struct stat *statfile)
{
    struct group *grp;

    grp = getgrgid(statfile->st_gid);
    mini_printf("%s", grp->gr_name);
    my_putchar(' ');
}

void get_size_file(struct stat *statfile)
{
    my_put_nbr(statfile->st_size);
    my_putchar(' ');
}

static void flag_l_printer(struct dirent *dirent, struct stat *statfile)
{
    stat(dirent->d_name, statfile);
    print_rights(statfile);
    link_getter(statfile);
    get_uid(statfile);
    get_gid(statfile);
    get_size_file(statfile);
    time_getter(statfile);
    print_size(statfile);
    mini_printf("%s\n", dirent->d_name);
}

int flag_l(char const *path)
{
    DIR *dir;
    struct dirent *dirent;
    struct stat statfile;

    dir = opendir(path);
    if (dir == NULL)
        return 84;
    dirent = readdir(dir);
    stat(dirent->d_name, &statfile);
    while (dirent) {
        if (dirent->d_name[0] == '.'){
            dirent = readdir(dir);
            continue;
        }
        flag_l_printer(dirent, &statfile);
        dirent = readdir(dir);
    }
    closedir(dir);
    return 0;
}

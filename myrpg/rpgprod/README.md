# Projet My RPG en CSFML

Ce projet est un jeu RPG développé en C en utilisant la librairie graphique CSFML.

## Prérequis

- Linux, Windows ou macOS 
- Compilateur C (gcc, clang, etc)
- CSFML

## Installation de la CSFML

### Linux

Sur la plupart des distributions, vous pouvez installer la CSFML depuis les dépôts officiels. Par exemple sur Ubuntu/Debian :

```bash
sudo apt install libcsfml-dev
```

### macOS 

Vous pouvez installer la CSFML via le gestionnaire de paquets Homebrew :

```bash
brew install csfml
```

### Windows

Téléchargez la dernière version de la CSFML sur le site officiel : https://www.sfml-dev.org/download/csfml/

Dézippez l'archive et placez les fichiers dans un répertoire de votre choix, par exemple `C:\csfml`.

Ajoutez le chemin `C:\csfml\bin` à votre variable d'environnement PATH.

## Compiler le projet

Ouvrez un terminal dans le répertoire du projet et exécutez la commande :

```bash 
make
```

Cela va compiler tous les fichiers sources C et générer l'exécutable `my_rpg`.

## Lancer le jeu

Une fois la compilation terminée, vous pouvez lancer le jeu avec :

```bash
./my_rpg
```

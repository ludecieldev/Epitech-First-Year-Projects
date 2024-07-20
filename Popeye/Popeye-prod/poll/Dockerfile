FROM python:3.9
WORKDIR /app
COPY requirements.txt /app
RUN pip3 install -r requirements.txt
COPY . /app
EXPOSE 80
CMD ["flask", "run", "--host=0.0.0.0", "--port=80"]
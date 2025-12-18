# лабораторная №1
Перед сборкой выполнить: apt-get -y install libcurl4-gnutls-dev gcc\
сборка: build.sh\
Для корректной работы приложения ip задать переменную TYPE:\
export TYPE=http://ip-api.com/json/ \
или\
export TYPE=https://jsonip.com/
<img width="811" height="113" alt="Screenshot from 2025-12-18 17-40-31" src="https://github.com/user-attachments/assets/876883ba-0513-4693-baa9-022672580f1d" />


# лабораторная №2
создать образ \
docker build -t ip .

проверить образ ip \
docker run -e TYPE=http://ip-api.com/json/ ip

поднять сервер nginx (вывод по адресу http://localhost:8080/ip.json) \
docker compose up


# лабораторная №3
добавлены файлы:\
nginx-config.yaml,\
secret.yaml для env переменных,\
deployment.yaml,\
service.yaml,\
ingress.yaml

bash.sh содержит команды для запуска

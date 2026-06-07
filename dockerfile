FROM ubuntu:22.04

RUN apt update && apt install -y \
	gcc \
	make \
	valgrind \
	check \
	pkg-config \
	clang-format \
	cppcheck \
	lcov \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /project

CMD ["make"]

# Этот файл создает образ со всеми установленными приложениями для тестирования проекта
# Образ собирается один раз и в дальнейшем может использоваться для запуска контейнеров

# Сборка образа из dockerfile, если раньше еще не собирался:
# docker build -t <имя образа> . (точка в конце обязательна)

# Посмотреть список всех собранных образов можно с помощью команды:
# docker images


# Запуск контейнера:
# docker run -it --rm --name <имя контейнера> -v $(pwd)/..:/project <имя образа> /bin/bash

# Эта команда (благодаря флагу -v) подмонтирует наш диск в папку /project, находящуюся внутри контейнера
# После запуска мы окажемся в корне своего физического диска, поэтому для тестирования проекта вначале нужно пройти в папку где он находится 

# Проверка на cppcheck:
	# Покажет результат в консоли
		# cppcheck --enable=all --inconclusive --std=c11 --suppress=missingIncludeSystem --error-exitcode=1 .

	# Создаст файл cppcheck.log и перенаправит в него поток с ошибками
		# cppcheck --enable=all --inconclusive --std=c11 --suppress=missingIncludeSystem --error-exitcode=1 . 2> cppcheck.log

# Проверка на утечки памяти:
	# Покажет результат в консоли
		# valgrind --tool=memcheck --leak-check=yes -s ./test

	# Создаст файл memtest.log с основным выводом и файл memerror.log, в который перенаправит поток с ошибками
#valgrind --tool=memcheck --leak-check=yes -s ./test > memtest.log 2>memerror.log

# Остановить контейнер
# exit - находясь внутри контейнера
	# или 
#docker stop <имя контейнера> - находясь снаружи контейнера

# Принудительная остановка, если не сработали предыдущие команды
# docker kill <имя контейнера>
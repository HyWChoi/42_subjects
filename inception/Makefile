NAME = inception

all: prepare $(NAME)

prepare:
	@mkdir -p /home/$(USER)/data/wordpress
	@mkdir -p /home/$(USER)/data/mariadb

$(NAME):
	@docker-compose -f srcs/docker-compose.yml up --build -d

clean:
	@docker-compose -f srcs/docker-compose.yml down

fclean: clean
	@docker system prune -a --force
	@rm -rf /home/$(USER)/data/wordpress/*
	@rm -rf /home/$(USER)/data/mariadb/*

re: fclean all

.PHONY: all prepare clean fclean re
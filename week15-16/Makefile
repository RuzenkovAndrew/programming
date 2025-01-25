# sudo lsof -i :8080

SERVER_DIR = server
CLIENT_DIR = client

all: server client

server:
	@echo "Building server..."
	cd $(SERVER_DIR) && make all

client:
	@echo "Building client..."
	cd $(CLIENT_DIR) && make all

run_server: server
	@echo "Running server..."
	cd $(SERVER_DIR) && make run

run_client: client
	@echo "Running client..."
	cd $(CLIENT_DIR) && make run

run_workers_3: client
	@echo "Running 3 clients..."
	cd $(CLIENT_DIR) && make run &
	cd $(CLIENT_DIR) && make run &
	cd $(CLIENT_DIR) && make run

clean:
	@echo "Cleaning..."
	cd $(SERVER_DIR) && make clean
	cd $(CLIENT_DIR) && make clean

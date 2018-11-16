### Setup docker on Debian 8.1

Install notes: https://docs.docker.com/install/linux/docker-ce/debian/#install-using-the-repository

Docker CLI: https://docs.docker.com/engine/reference/run/

Script that installs docker-ce: `setup_docker_debian.sh`

### Build&Run TUNEZ docker container

Build container: `sudo docker build --no-cache --tag tunez .`

Run container: `sudo docker run -d --name tunez.cont tunez`

Start container: `sudo docker start tunez.cont`

See if it is up: `sudo docker ps -a`

Shell in the container: `sudo docker exec -it tunez.cont /bin/bash`

Test RPC (shell inside container): `tunez-cli help` or `tunez-cli getinfo`

Stop container: `sudo docker stop tunez.cont`

Delete container: `sudo docker rm tunez.cont`
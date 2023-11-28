# CPP Web development with CROW


# Docker container 

* Using ubuntu 
* Installing crow on the container  


# Run the container with the exported files 

``` bash
docker run -v ~/apps/cpp2023/webcpp:/usr/src/webcpp -p 8080:8080 -e PORT=8080 -ti cppbox /usr/src/webcpp/web/build/web 

```

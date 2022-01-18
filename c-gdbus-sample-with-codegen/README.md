### Instructions 

<br>
1)Open a terminal to generate required files from xml run in terminal 
<br>
<br>

```
gdbus-codegen --generate-c-code sample-generated --interface-prefix com.github.redoc. interface.xml
```

<br>
2)Then run 
<br>
<br>

```
gcc `pkg-config --cflags --libs gio-2.0 gio-unix-2.0 glib-2.0` server.c sample-generated.c -o server && ./server
```

<br>
3)Then open another instance and in it run
<br>
<br>

```
gcc `pkg-config --cflags --libs gio-2.0 gio-unix-2.0 glib-2.0` client.c sample-generated.c -o client && ./client
```


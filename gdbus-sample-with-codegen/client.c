#include "sample-generated.h"
#include <stdio.h>
Sample *proxy = NULL;

void quit_loop(Sample *proxy ,
              GAsyncResult *res,
              gpointer user_data){
  GMainLoop *loop = (GMainLoop *)user_data;
  g_main_loop_quit(loop);
  printf("quited \n");
}

void proxy_got(Sample *client,
              GAsyncResult *res,
              gpointer user_data){
  
  printf("Method called on server look at server side \n");
  GError *error = NULL;
  proxy = sample_proxy_new_for_bus_finish(res, &error) ;
  if(error != NULL){
    printf("error happened - %s",error->message);
  }
  sample_call_say_hello(proxy, "afshan ",NULL, (GAsyncReadyCallback) quit_loop, user_data );
  error = NULL;
  if(error != NULL){
    printf("error happened - %s",error->message);
  }
  printf("Please wait ! gracefully quiting ...\n");
}

int main(){
  GError *error = NULL;
  GMainLoop *loop = g_main_loop_new(NULL,FALSE);
  sample_proxy_new_for_bus(G_BUS_TYPE_SESSION,
                          G_DBUS_PROXY_FLAGS_NONE,
                          "com.github.redoc.Sample",
                          "/com/github/redoc/Sample",
                          NULL,
                          (GAsyncReadyCallback)proxy_got,
                          loop);

  /*
  *following code does the sampe thing as above but in synchronous way;
  *To use following code comment the sample_proxy_new_for_bus method;
  proxy = sample_proxy_new_for_bus_sync(G_BUS_TYPE_SESSION, 
                                                G_DBUS_PROXY_FLAGS_NONE, 
                                                "com.github.redoc.Sample", 
                                                "/com/github/redoc/Sample", 
                                                NULL, 
                                                NULL) ;
  
  sample_call_say_hello_sync(proxy , "afshan", NULL,NULL):
  */

  g_main_loop_run(loop) ;
  return 0;
}

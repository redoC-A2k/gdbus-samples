#include <stdio.h>
#include "sample-generated.h"

static gboolean on_handle_say_hello(Sample *skeleton,
                                    GDBusMethodInvocation *invocation,
                                    gchar *your_name){
  printf("handling the signal \n");
  fprintf(stdout,"Hello - %s , how are you ? I hope you are fine \n",your_name);
  return TRUE; //returning true so that the sample_complete_say_hello gets called by itself
}
static void on_name_acquired(GDBusConnection *connnection ,
                            const gchar *name ,
                            gpointer loop) {
  Sample *skeleton = sample_skeleton_new();
  g_signal_connect(skeleton,"handle-say-hello",G_CALLBACK(on_handle_say_hello),loop);
  GError *error = NULL;
  g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(skeleton),
                                  connnection,
                                  "/com/github/redoc/Sample",
                                  &error);
  if(error != NULL){
    printf("error happened - %s\n",error->message);
  }
}

int main(){
  GMainLoop *loop = g_main_loop_new(NULL,FALSE);
  g_bus_own_name(G_BUS_TYPE_SESSION, 
                "com.github.redoc.Sample",
                 G_BUS_NAME_OWNER_FLAGS_NONE, 
                 NULL, 
                 on_name_acquired, 
                 NULL,
                 loop,
                 NULL);
  printf("main loop starts\n");
  g_main_loop_run(loop);
  return 0;
}

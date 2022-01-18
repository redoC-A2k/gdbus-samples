[DBus (name = "com.github.redoc.ValaSample")]
interface Client : Object{
  public abstract void sayHello(string name) throws Error;
}

int main(){
  try {
    Client client = Bus.get_proxy_sync(BusType.SESSION,
                                      "com.github.redoc.ValaSample",
                                      "/com/github/redoc/ValaSample",
                                      DBusProxyFlags.NONE);
    client.sayHello("afshan");
  } catch (Error e) {
    stdout.printf("error happened %s", e.message)  ;
  }
  //new MainLoop().run();
  return 0;
}

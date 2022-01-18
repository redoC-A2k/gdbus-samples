
[DBus (name="com.github.redoc.ValaSample")]
public class Server : Object{
  public void sayHello(string name) throws Error {
    stdout.printf("saying hello \n");
    stdout.printf("Hello - %s , how are you ? I hope you are fine \n", name);
  }
}

void on_bus_acquired(DBusConnection conn ){
  try {
    conn.register_object("/com/github/redoc/ValaSample",new Server());
  } catch (IOError e) {
    stderr.printf("COuld not register service :%s\n", e.message);
  }
}

int main(){
  Bus.own_name(BusType.SESSION ,
               "com.github.redoc.ValaSample",
               BusNameOwnerFlags.NONE ,
               on_bus_acquired ,
               null,
               null);
  
  new MainLoop().run();
  return 0;
}


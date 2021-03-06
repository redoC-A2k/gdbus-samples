/* server.c generated by valac 0.54.5, the Vala compiler
 * generated from server.vala, do not modify */

#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <stdio.h>

#if !defined(VALA_EXTERN)
#if defined(_MSC_VER)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

#define TYPE_SERVER (server_get_type ())
#define SERVER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SERVER, Server))
#define SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SERVER, ServerClass))
#define IS_SERVER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SERVER))
#define IS_SERVER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SERVER))
#define SERVER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SERVER, ServerClass))

typedef struct _Server Server;
typedef struct _ServerClass ServerClass;
typedef struct _ServerPrivate ServerPrivate;
enum  {
	SERVER_0_PROPERTY,
	SERVER_NUM_PROPERTIES
};
static GParamSpec* server_properties[SERVER_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))

struct _Server {
	GObject parent_instance;
	ServerPrivate * priv;
};

struct _ServerClass {
	GObjectClass parent_class;
};

static gpointer server_parent_class = NULL;

VALA_EXTERN GType server_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (Server, g_object_unref)
VALA_EXTERN guint server_register_object (void* object,
                              GDBusConnection* connection,
                              const gchar* path,
                              GError** error);
VALA_EXTERN void server_sayHello (Server* self,
                      const gchar* name,
                      GError** error);
VALA_EXTERN Server* server_new (void);
VALA_EXTERN Server* server_construct (GType object_type);
static GType server_get_type_once (void);
static void _dbus_server_sayHello (Server* self,
                            GVariant* _parameters_,
                            GDBusMethodInvocation* invocation);
static void server_dbus_interface_method_call (GDBusConnection* connection,
                                        const gchar* sender,
                                        const gchar* object_path,
                                        const gchar* interface_name,
                                        const gchar* method_name,
                                        GVariant* parameters,
                                        GDBusMethodInvocation* invocation,
                                        gpointer user_data);
static GVariant* server_dbus_interface_get_property (GDBusConnection* connection,
                                              const gchar* sender,
                                              const gchar* object_path,
                                              const gchar* interface_name,
                                              const gchar* property_name,
                                              GError** error,
                                              gpointer user_data);
static gboolean server_dbus_interface_set_property (GDBusConnection* connection,
                                             const gchar* sender,
                                             const gchar* object_path,
                                             const gchar* interface_name,
                                             const gchar* property_name,
                                             GVariant* value,
                                             GError** error,
                                             gpointer user_data);
static void _server_unregister_object (gpointer user_data);
VALA_EXTERN void on_bus_acquired (GDBusConnection* conn);
static gint _vala_main (void);
static void _on_bus_acquired_gbus_acquired_callback (GDBusConnection* connection,
                                              const gchar* name,
                                              gpointer self);

static const GDBusArgInfo _server_dbus_arg_info_sayHello_name = {-1, "name", "s", NULL};
static const GDBusArgInfo * const _server_dbus_arg_info_sayHello_in[] = {&_server_dbus_arg_info_sayHello_name, NULL};
static const GDBusArgInfo * const _server_dbus_arg_info_sayHello_out[] = {NULL};
static const GDBusMethodInfo _server_dbus_method_info_sayHello = {-1, "sayHello", (GDBusArgInfo **) (&_server_dbus_arg_info_sayHello_in), (GDBusArgInfo **) (&_server_dbus_arg_info_sayHello_out), NULL};
static const GDBusMethodInfo * const _server_dbus_method_info[] = {&_server_dbus_method_info_sayHello, NULL};
static const GDBusSignalInfo * const _server_dbus_signal_info[] = {NULL};
static const GDBusPropertyInfo * const _server_dbus_property_info[] = {NULL};
static const GDBusInterfaceInfo _server_dbus_interface_info = {-1, "com.github.redoc.ValaSample", (GDBusMethodInfo **) (&_server_dbus_method_info), (GDBusSignalInfo **) (&_server_dbus_signal_info), (GDBusPropertyInfo **) (&_server_dbus_property_info), NULL};
static const GDBusInterfaceVTable _server_dbus_interface_vtable = {server_dbus_interface_method_call, server_dbus_interface_get_property, server_dbus_interface_set_property};

void
server_sayHello (Server* self,
                 const gchar* name,
                 GError** error)
{
	FILE* _tmp0_;
	FILE* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	_tmp0_ = stdout;
	fprintf (_tmp0_, "saying hello");
	_tmp1_ = stdout;
	fprintf (_tmp1_, "Hello - %s , how are you ? I hope you are fine ", name);
}

Server*
server_construct (GType object_type)
{
	Server * self = NULL;
	self = (Server*) g_object_new (object_type, NULL);
	return self;
}

Server*
server_new (void)
{
	return server_construct (TYPE_SERVER);
}

static void
server_class_init (ServerClass * klass,
                   gpointer klass_data)
{
	server_parent_class = g_type_class_peek_parent (klass);
}

static void
server_instance_init (Server * self,
                      gpointer klass)
{
}

static GType
server_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ServerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) server_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Server), 0, (GInstanceInitFunc) server_instance_init, NULL };
	GType server_type_id;
	server_type_id = g_type_register_static (G_TYPE_OBJECT, "Server", &g_define_type_info, 0);
	g_type_set_qdata (server_type_id, g_quark_from_static_string ("vala-dbus-register-object"), (void*) server_register_object);
	return server_type_id;
}

GType
server_get_type (void)
{
	static volatile gsize server_type_id__volatile = 0;
	if (g_once_init_enter (&server_type_id__volatile)) {
		GType server_type_id;
		server_type_id = server_get_type_once ();
		g_once_init_leave (&server_type_id__volatile, server_type_id);
	}
	return server_type_id__volatile;
}

static void
_dbus_server_sayHello (Server* self,
                       GVariant* _parameters_,
                       GDBusMethodInvocation* invocation)
{
	GError* error = NULL;
	GVariantIter _arguments_iter;
	gchar* name = NULL;
	GVariant* _tmp0_;
	GDBusMessage* _reply_message = NULL;
	GVariant* _reply;
	GVariantBuilder _reply_builder;
	g_variant_iter_init (&_arguments_iter, _parameters_);
	_tmp0_ = g_variant_iter_next_value (&_arguments_iter);
	name = g_variant_dup_string (_tmp0_, NULL);
	g_variant_unref (_tmp0_);
	server_sayHello (self, name, &error);
	if (error) {
		g_dbus_method_invocation_return_gerror (invocation, error);
		g_error_free (error);
		goto _error;
	}
	_reply_message = g_dbus_message_new_method_reply (g_dbus_method_invocation_get_message (invocation));
	g_variant_builder_init (&_reply_builder, G_VARIANT_TYPE_TUPLE);
	_reply = g_variant_builder_end (&_reply_builder);
	g_dbus_message_set_body (_reply_message, _reply);
	g_dbus_connection_send_message (g_dbus_method_invocation_get_connection (invocation), _reply_message, G_DBUS_SEND_MESSAGE_FLAGS_NONE, NULL, NULL);
	g_object_unref (invocation);
	g_object_unref (_reply_message);
	_error:
	_g_free0 (name);
	;
}

static void
server_dbus_interface_method_call (GDBusConnection* connection,
                                   const gchar* sender,
                                   const gchar* object_path,
                                   const gchar* interface_name,
                                   const gchar* method_name,
                                   GVariant* parameters,
                                   GDBusMethodInvocation* invocation,
                                   gpointer user_data)
{
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	if (strcmp (method_name, "sayHello") == 0) {
		_dbus_server_sayHello (object, parameters, invocation);
	} else {
		g_object_unref (invocation);
	}
}

static GVariant*
server_dbus_interface_get_property (GDBusConnection* connection,
                                    const gchar* sender,
                                    const gchar* object_path,
                                    const gchar* interface_name,
                                    const gchar* property_name,
                                    GError** error,
                                    gpointer user_data)
{
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	return NULL;
}

static gboolean
server_dbus_interface_set_property (GDBusConnection* connection,
                                    const gchar* sender,
                                    const gchar* object_path,
                                    const gchar* interface_name,
                                    const gchar* property_name,
                                    GVariant* value,
                                    GError** error,
                                    gpointer user_data)
{
	gpointer* data;
	gpointer object;
	data = user_data;
	object = data[0];
	return FALSE;
}

guint
server_register_object (gpointer object,
                        GDBusConnection* connection,
                        const gchar* path,
                        GError** error)
{
	guint result;
	gpointer *data;
	data = g_new (gpointer, 3);
	data[0] = g_object_ref (object);
	data[1] = g_object_ref (connection);
	data[2] = g_strdup (path);
	result = g_dbus_connection_register_object (connection, path, (GDBusInterfaceInfo *) (&_server_dbus_interface_info), &_server_dbus_interface_vtable, data, _server_unregister_object, error);
	if (!result) {
		return 0;
	}
	return result;
}

static void
_server_unregister_object (gpointer user_data)
{
	gpointer* data;
	data = user_data;
	g_object_unref (data[0]);
	g_object_unref (data[1]);
	g_free (data[2]);
	g_free (data);
}

void
on_bus_acquired (GDBusConnection* conn)
{
	GError* _inner_error0_ = NULL;
	g_return_if_fail (conn != NULL);
	{
		Server* server = NULL;
		Server* _tmp0_;
		_tmp0_ = server_new ();
		server = _tmp0_;
		server_register_object (server, conn, "/com/github/redoc/ValaSample", &_inner_error0_);
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			_g_object_unref0 (server);
			if (_inner_error0_->domain == G_IO_ERROR) {
				goto __catch0_g_io_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return;
		}
		_g_object_unref0 (server);
	}
	goto __finally0;
	__catch0_g_io_error:
	{
		GError* e = NULL;
		FILE* _tmp1_;
		GError* _tmp2_;
		const gchar* _tmp3_;
		e = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp1_ = stderr;
		_tmp2_ = e;
		_tmp3_ = _tmp2_->message;
		fprintf (_tmp1_, "COuld not register service :%s\n", _tmp3_);
		_g_error_free0 (e);
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return;
	}
}

static void
_on_bus_acquired_gbus_acquired_callback (GDBusConnection* connection,
                                         const gchar* name,
                                         gpointer self)
{
	on_bus_acquired (connection);
}

static gint
_vala_main (void)
{
	GMainLoop* _tmp0_;
	GMainLoop* _tmp1_;
	gint result = 0;
	g_bus_own_name_with_closures (G_BUS_TYPE_SESSION, "com.github.redoc.ValaSample", G_BUS_NAME_OWNER_FLAGS_NONE, (GClosure*) ((_on_bus_acquired_gbus_acquired_callback == NULL) ? NULL : g_cclosure_new ((GCallback) _on_bus_acquired_gbus_acquired_callback, NULL, (GClosureNotify) NULL)), (GClosure*) ((NULL == NULL) ? NULL : g_cclosure_new ((GCallback) NULL, NULL, (GClosureNotify) NULL)), (GClosure*) ((NULL == NULL) ? NULL : g_cclosure_new ((GCallback) NULL, NULL, (GClosureNotify) NULL)));
	_tmp0_ = g_main_loop_new (NULL, FALSE);
	_tmp1_ = _tmp0_;
	g_main_loop_run (_tmp1_);
	_g_main_loop_unref0 (_tmp1_);
	result = 0;
	return result;
}

int
main (int argc,
      char ** argv)
{
	return _vala_main ();
}


/* math-variables.c generated by valac 0.30.0.14-c43a, the Vala compiler
 * generated from math-variables.vala, do not modify */

/*
 * Copyright (C) 2008-2012 Robert Ancell
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version. See http://www.gnu.org/copyleft/gpl.html the full text of the
 * license.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gstdio.h>


#define TYPE_MATH_VARIABLES (math_variables_get_type ())
#define MATH_VARIABLES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MATH_VARIABLES, MathVariables))
#define MATH_VARIABLES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MATH_VARIABLES, MathVariablesClass))
#define IS_MATH_VARIABLES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MATH_VARIABLES))
#define IS_MATH_VARIABLES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MATH_VARIABLES))
#define MATH_VARIABLES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MATH_VARIABLES, MathVariablesClass))

typedef struct _MathVariables MathVariables;
typedef struct _MathVariablesClass MathVariablesClass;
typedef struct _MathVariablesPrivate MathVariablesPrivate;

#define TYPE_NUMBER (number_get_type ())
#define NUMBER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_NUMBER, Number))
#define NUMBER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_NUMBER, NumberClass))
#define IS_NUMBER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_NUMBER))
#define IS_NUMBER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_NUMBER))
#define NUMBER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_NUMBER, NumberClass))

typedef struct _Number Number;
typedef struct _NumberClass NumberClass;

#define TYPE_SERIALIZER (serializer_get_type ())
#define SERIALIZER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SERIALIZER, Serializer))
#define SERIALIZER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SERIALIZER, SerializerClass))
#define IS_SERIALIZER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SERIALIZER))
#define IS_SERIALIZER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SERIALIZER))
#define SERIALIZER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SERIALIZER, SerializerClass))

typedef struct _Serializer Serializer;
typedef struct _SerializerClass SerializerClass;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define TYPE_DISPLAY_FORMAT (display_format_get_type ())
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _MathVariables {
	GObject parent_instance;
	MathVariablesPrivate * priv;
};

struct _MathVariablesClass {
	GObjectClass parent_class;
};

struct _MathVariablesPrivate {
	gchar* file_name;
	GHashTable* registers;
	Serializer* serializer;
};

typedef enum  {
	DISPLAY_FORMAT_AUTOMATIC,
	DISPLAY_FORMAT_FIXED,
	DISPLAY_FORMAT_SCIENTIFIC,
	DISPLAY_FORMAT_ENGINEERING
} DisplayFormat;


static gpointer math_variables_parent_class = NULL;

GType math_variables_get_type (void) G_GNUC_CONST;
GType number_get_type (void) G_GNUC_CONST;
GType serializer_get_type (void) G_GNUC_CONST;
#define MATH_VARIABLES_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_MATH_VARIABLES, MathVariablesPrivate))
enum  {
	MATH_VARIABLES_DUMMY_PROPERTY
};
MathVariables* math_variables_new (void);
MathVariables* math_variables_construct (GType object_type);
static void _g_free0_ (gpointer var);
static void _g_object_unref0_ (gpointer var);
GType display_format_get_type (void) G_GNUC_CONST;
Serializer* serializer_new (DisplayFormat format, gint number_base, gint trailing_digits);
Serializer* serializer_construct (GType object_type, DisplayFormat format, gint number_base, gint trailing_digits);
void serializer_set_radix (Serializer* self, gunichar radix);
static void math_variables_registers_load (MathVariables* self);
Number* mp_set_from_string (const gchar* str, gint default_base);
static void math_variables_save (MathVariables* self);
gchar* serializer_to_string (Serializer* self, Number* x);
static gchar** math_variables_array_sort_string (MathVariables* self, gchar** array, int array_length1, int* result_length1);
static gchar** _vala_array_dup8 (gchar** self, int length);
gchar** math_variables_get_names (MathVariables* self, int* result_length1);
gchar** math_variables_variables_eligible_for_autocompletion (MathVariables* self, const gchar* text, int* result_length1);
static void _vala_array_add5 (gchar*** array, int* length, int* size, gchar* value);
void math_variables_set (MathVariables* self, const gchar* name, Number* value);
Number* math_variables_get (MathVariables* self, const gchar* name);
void math_variables_delete (MathVariables* self, const gchar* name);
static void math_variables_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


MathVariables* math_variables_construct (GType object_type) {
	MathVariables * self = NULL;
	GHashFunc _tmp0_ = NULL;
	GEqualFunc _tmp1_ = NULL;
	GHashTable* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	Serializer* _tmp5_ = NULL;
	Serializer* _tmp6_ = NULL;
	self = (MathVariables*) g_object_new (object_type, NULL);
	_tmp0_ = g_str_hash;
	_tmp1_ = g_str_equal;
	_tmp2_ = g_hash_table_new_full (_tmp0_, _tmp1_, _g_free0_, _g_object_unref0_);
	_g_hash_table_unref0 (self->priv->registers);
	self->priv->registers = _tmp2_;
	_tmp3_ = g_get_user_data_dir ();
	_tmp4_ = g_build_filename (_tmp3_, "gnome-calculator", "registers", NULL);
	_g_free0 (self->priv->file_name);
	self->priv->file_name = _tmp4_;
	_tmp5_ = serializer_new (DISPLAY_FORMAT_SCIENTIFIC, 10, 50);
	_g_object_unref0 (self->priv->serializer);
	self->priv->serializer = _tmp5_;
	_tmp6_ = self->priv->serializer;
	serializer_set_radix (_tmp6_, (gunichar) '.');
	math_variables_registers_load (self);
	return self;
}


MathVariables* math_variables_new (void) {
	return math_variables_construct (TYPE_MATH_VARIABLES);
}


static gint string_index_of_char (const gchar* self, gunichar c, gint start_index) {
	gint result = 0;
	gchar* _result_ = NULL;
	gint _tmp0_ = 0;
	gunichar _tmp1_ = 0U;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = c;
	_tmp2_ = g_utf8_strchr (((gchar*) self) + _tmp0_, (gssize) -1, _tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	if (_tmp3_ != NULL) {
		gchar* _tmp4_ = NULL;
		_tmp4_ = _result_;
		result = (gint) (_tmp4_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}


static glong string_strnlen (gchar* str, glong maxlen) {
	glong result = 0L;
	gchar* end = NULL;
	gchar* _tmp0_ = NULL;
	glong _tmp1_ = 0L;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	_tmp0_ = str;
	_tmp1_ = maxlen;
	_tmp2_ = memchr (_tmp0_, 0, (gsize) _tmp1_);
	end = _tmp2_;
	_tmp3_ = end;
	if (_tmp3_ == NULL) {
		glong _tmp4_ = 0L;
		_tmp4_ = maxlen;
		result = _tmp4_;
		return result;
	} else {
		gchar* _tmp5_ = NULL;
		gchar* _tmp6_ = NULL;
		_tmp5_ = end;
		_tmp6_ = str;
		result = (glong) (_tmp5_ - _tmp6_);
		return result;
	}
}


static gchar* string_substring (const gchar* self, glong offset, glong len) {
	gchar* result = NULL;
	glong string_length = 0L;
	gboolean _tmp0_ = FALSE;
	glong _tmp1_ = 0L;
	glong _tmp8_ = 0L;
	glong _tmp14_ = 0L;
	glong _tmp17_ = 0L;
	glong _tmp18_ = 0L;
	glong _tmp19_ = 0L;
	glong _tmp20_ = 0L;
	glong _tmp21_ = 0L;
	gchar* _tmp22_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = offset;
	if (_tmp1_ >= ((glong) 0)) {
		glong _tmp2_ = 0L;
		_tmp2_ = len;
		_tmp0_ = _tmp2_ >= ((glong) 0);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		glong _tmp3_ = 0L;
		glong _tmp4_ = 0L;
		glong _tmp5_ = 0L;
		_tmp3_ = offset;
		_tmp4_ = len;
		_tmp5_ = string_strnlen ((gchar*) self, _tmp3_ + _tmp4_);
		string_length = _tmp5_;
	} else {
		gint _tmp6_ = 0;
		gint _tmp7_ = 0;
		_tmp6_ = strlen (self);
		_tmp7_ = _tmp6_;
		string_length = (glong) _tmp7_;
	}
	_tmp8_ = offset;
	if (_tmp8_ < ((glong) 0)) {
		glong _tmp9_ = 0L;
		glong _tmp10_ = 0L;
		glong _tmp11_ = 0L;
		_tmp9_ = string_length;
		_tmp10_ = offset;
		offset = _tmp9_ + _tmp10_;
		_tmp11_ = offset;
		g_return_val_if_fail (_tmp11_ >= ((glong) 0), NULL);
	} else {
		glong _tmp12_ = 0L;
		glong _tmp13_ = 0L;
		_tmp12_ = offset;
		_tmp13_ = string_length;
		g_return_val_if_fail (_tmp12_ <= _tmp13_, NULL);
	}
	_tmp14_ = len;
	if (_tmp14_ < ((glong) 0)) {
		glong _tmp15_ = 0L;
		glong _tmp16_ = 0L;
		_tmp15_ = string_length;
		_tmp16_ = offset;
		len = _tmp15_ - _tmp16_;
	}
	_tmp17_ = offset;
	_tmp18_ = len;
	_tmp19_ = string_length;
	g_return_val_if_fail ((_tmp17_ + _tmp18_) <= _tmp19_, NULL);
	_tmp20_ = offset;
	_tmp21_ = len;
	_tmp22_ = g_strndup (((gchar*) self) + _tmp20_, (gsize) _tmp21_);
	result = _tmp22_;
	return result;
}


static gchar* string_strip (const gchar* self) {
	gchar* result = NULL;
	gchar* _result_ = NULL;
	gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	_tmp1_ = _result_;
	g_strstrip (_tmp1_);
	result = _result_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void math_variables_registers_load (MathVariables* self) {
	gchar* data = NULL;
	GHashTable* _tmp2_ = NULL;
	gchar** lines = NULL;
	const gchar* _tmp3_ = NULL;
	gchar** _tmp4_ = NULL;
	gchar** _tmp5_ = NULL;
	gint lines_length1 = 0;
	gint _lines_size_ = 0;
	gchar** _tmp6_ = NULL;
	gint _tmp6__length1 = 0;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	{
		const gchar* _tmp0_ = NULL;
		gchar* _tmp1_ = NULL;
		_tmp0_ = self->priv->file_name;
		g_file_get_contents (_tmp0_, &_tmp1_, NULL, &_inner_error_);
		_g_free0 (data);
		data = _tmp1_;
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch8_g_file_error;
			}
			_g_free0 (data);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	goto __finally8;
	__catch8_g_file_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_error_free0 (e);
		_g_free0 (data);
		return;
	}
	__finally8:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		_g_free0 (data);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_tmp2_ = self->priv->registers;
	g_hash_table_remove_all (_tmp2_);
	_tmp3_ = data;
	_tmp5_ = _tmp4_ = g_strsplit (_tmp3_, "\n", 0);
	lines = _tmp5_;
	lines_length1 = _vala_array_length (_tmp4_);
	_lines_size_ = lines_length1;
	_tmp6_ = lines;
	_tmp6__length1 = lines_length1;
	{
		gchar** line_collection = NULL;
		gint line_collection_length1 = 0;
		gint _line_collection_size_ = 0;
		gint line_it = 0;
		line_collection = _tmp6_;
		line_collection_length1 = _tmp6__length1;
		for (line_it = 0; line_it < _tmp6__length1; line_it = line_it + 1) {
			gchar* _tmp7_ = NULL;
			gchar* line = NULL;
			_tmp7_ = g_strdup (line_collection[line_it]);
			line = _tmp7_;
			{
				gint i = 0;
				const gchar* _tmp8_ = NULL;
				gint _tmp9_ = 0;
				gint _tmp10_ = 0;
				gchar* name = NULL;
				const gchar* _tmp11_ = NULL;
				gint _tmp12_ = 0;
				gchar* _tmp13_ = NULL;
				gchar* _tmp14_ = NULL;
				gchar* _tmp15_ = NULL;
				gchar* _tmp16_ = NULL;
				gchar* value = NULL;
				const gchar* _tmp17_ = NULL;
				gint _tmp18_ = 0;
				gchar* _tmp19_ = NULL;
				gchar* _tmp20_ = NULL;
				gchar* _tmp21_ = NULL;
				gchar* _tmp22_ = NULL;
				Number* t = NULL;
				const gchar* _tmp23_ = NULL;
				Number* _tmp24_ = NULL;
				Number* _tmp25_ = NULL;
				_tmp8_ = line;
				_tmp9_ = string_index_of_char (_tmp8_, (gunichar) '=', 0);
				i = _tmp9_;
				_tmp10_ = i;
				if (_tmp10_ < 0) {
					_g_free0 (line);
					continue;
				}
				_tmp11_ = line;
				_tmp12_ = i;
				_tmp13_ = string_substring (_tmp11_, (glong) 0, (glong) _tmp12_);
				_tmp14_ = _tmp13_;
				_tmp15_ = string_strip (_tmp14_);
				_tmp16_ = _tmp15_;
				_g_free0 (_tmp14_);
				name = _tmp16_;
				_tmp17_ = line;
				_tmp18_ = i;
				_tmp19_ = string_substring (_tmp17_, (glong) (_tmp18_ + 1), (glong) -1);
				_tmp20_ = _tmp19_;
				_tmp21_ = string_strip (_tmp20_);
				_tmp22_ = _tmp21_;
				_g_free0 (_tmp20_);
				value = _tmp22_;
				_tmp23_ = value;
				_tmp24_ = mp_set_from_string (_tmp23_, 10);
				t = _tmp24_;
				_tmp25_ = t;
				if (_tmp25_ != NULL) {
					GHashTable* _tmp26_ = NULL;
					const gchar* _tmp27_ = NULL;
					gchar* _tmp28_ = NULL;
					Number* _tmp29_ = NULL;
					Number* _tmp30_ = NULL;
					_tmp26_ = self->priv->registers;
					_tmp27_ = name;
					_tmp28_ = g_strdup (_tmp27_);
					_tmp29_ = t;
					_tmp30_ = _g_object_ref0 (_tmp29_);
					g_hash_table_insert (_tmp26_, _tmp28_, _tmp30_);
				}
				_g_object_unref0 (t);
				_g_free0 (value);
				_g_free0 (name);
				_g_free0 (line);
			}
		}
	}
	lines = (_vala_array_free (lines, lines_length1, (GDestroyNotify) g_free), NULL);
	_g_free0 (data);
}


static void math_variables_save (MathVariables* self) {
	gchar* data = NULL;
	gchar* _tmp0_ = NULL;
	GHashTableIter iter = {0};
	GHashTable* _tmp1_ = NULL;
	gchar* name = NULL;
	Number* value = NULL;
	gchar* dir = NULL;
	const gchar* _tmp16_ = NULL;
	gchar* _tmp17_ = NULL;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup ("");
	data = _tmp0_;
	_tmp1_ = self->priv->registers;
	g_hash_table_iter_init (&iter, _tmp1_);
	while (TRUE) {
		gconstpointer _tmp2_ = NULL;
		gconstpointer _tmp3_ = NULL;
		gboolean _tmp4_ = FALSE;
		gchar* _tmp5_ = NULL;
		Number* _tmp6_ = NULL;
		gchar* number = NULL;
		Serializer* _tmp7_ = NULL;
		Number* _tmp8_ = NULL;
		gchar* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		const gchar* _tmp11_ = NULL;
		const gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_ = NULL;
		gchar* _tmp15_ = NULL;
		_tmp4_ = g_hash_table_iter_next (&iter, (gpointer*) (&_tmp2_), (gpointer*) (&_tmp3_));
		_g_free0 (name);
		_tmp5_ = g_strdup (_tmp2_);
		name = _tmp5_;
		_g_object_unref0 (value);
		_tmp6_ = _g_object_ref0 (_tmp3_);
		value = _tmp6_;
		if (!_tmp4_) {
			break;
		}
		_tmp7_ = self->priv->serializer;
		_tmp8_ = value;
		_tmp9_ = serializer_to_string (_tmp7_, _tmp8_);
		number = _tmp9_;
		_tmp10_ = data;
		_tmp11_ = name;
		_tmp12_ = number;
		_tmp13_ = g_strdup_printf ("%s=%s\n", _tmp11_, _tmp12_);
		_tmp14_ = _tmp13_;
		_tmp15_ = g_strconcat (_tmp10_, _tmp14_, NULL);
		_g_free0 (data);
		data = _tmp15_;
		_g_free0 (_tmp14_);
		_g_free0 (number);
	}
	_tmp16_ = self->priv->file_name;
	_tmp17_ = g_path_get_dirname (_tmp16_);
	dir = _tmp17_;
	g_mkdir_with_parents (dir, 0700);
	{
		const gchar* _tmp18_ = NULL;
		const gchar* _tmp19_ = NULL;
		_tmp18_ = self->priv->file_name;
		_tmp19_ = data;
		g_file_set_contents (_tmp18_, _tmp19_, (gssize) -1, &_inner_error_);
		if (G_UNLIKELY (_inner_error_ != NULL)) {
			if (_inner_error_->domain == G_FILE_ERROR) {
				goto __catch9_g_file_error;
			}
			_g_free0 (dir);
			_g_object_unref0 (value);
			_g_free0 (name);
			_g_free0 (data);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
	}
	goto __finally9;
	__catch9_g_file_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		_g_error_free0 (e);
	}
	__finally9:
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		_g_free0 (dir);
		_g_object_unref0 (value);
		_g_free0 (name);
		_g_free0 (data);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_free0 (dir);
	_g_object_unref0 (value);
	_g_free0 (name);
	_g_free0 (data);
}


static gchar** _vala_array_dup8 (gchar** self, int length) {
	gchar** result;
	int i;
	result = g_new0 (gchar*, length + 1);
	for (i = 0; i < length; i++) {
		gchar* _tmp0_ = NULL;
		_tmp0_ = g_strdup (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


static gchar** math_variables_array_sort_string (MathVariables* self, gchar** array, int array_length1, int* result_length1) {
	gchar** result = NULL;
	gboolean swapped = FALSE;
	gint _tmp0_ = 0;
	gchar** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	gchar** _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	const gchar* _tmp3_ = NULL;
	gint j = 0;
	gchar* tmp = NULL;
	gchar** _tmp33_ = NULL;
	gint _tmp33__length1 = 0;
	gchar** _tmp34_ = NULL;
	gint _tmp34__length1 = 0;
	gchar** _tmp35_ = NULL;
	gint _tmp35__length1 = 0;
	g_return_val_if_fail (self != NULL, NULL);
	swapped = TRUE;
	_tmp1_ = array;
	_tmp1__length1 = array_length1;
	_tmp2_ = array;
	_tmp2__length1 = array_length1;
	_tmp3_ = _tmp1_[_tmp2__length1 - 1];
	if (_tmp3_ == NULL) {
		_tmp0_ = 1;
	} else {
		_tmp0_ = 0;
	}
	j = _tmp0_;
	while (TRUE) {
		gboolean _tmp4_ = FALSE;
		gint _tmp5_ = 0;
		_tmp4_ = swapped;
		if (!_tmp4_) {
			break;
		}
		swapped = FALSE;
		_tmp5_ = j;
		j = _tmp5_ + 1;
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp6_ = FALSE;
				_tmp6_ = TRUE;
				while (TRUE) {
					gint _tmp8_ = 0;
					gchar** _tmp9_ = NULL;
					gint _tmp9__length1 = 0;
					gint _tmp10_ = 0;
					gchar** _tmp11_ = NULL;
					gint _tmp11__length1 = 0;
					gint _tmp12_ = 0;
					const gchar* _tmp13_ = NULL;
					gchar** _tmp14_ = NULL;
					gint _tmp14__length1 = 0;
					gint _tmp15_ = 0;
					const gchar* _tmp16_ = NULL;
					if (!_tmp6_) {
						gint _tmp7_ = 0;
						_tmp7_ = i;
						i = _tmp7_ + 1;
					}
					_tmp6_ = FALSE;
					_tmp8_ = i;
					_tmp9_ = array;
					_tmp9__length1 = array_length1;
					_tmp10_ = j;
					if (!(_tmp8_ < (_tmp9__length1 - _tmp10_))) {
						break;
					}
					_tmp11_ = array;
					_tmp11__length1 = array_length1;
					_tmp12_ = i;
					_tmp13_ = _tmp11_[_tmp12_];
					_tmp14_ = array;
					_tmp14__length1 = array_length1;
					_tmp15_ = i;
					_tmp16_ = _tmp14_[_tmp15_ + 1];
					if (g_strcmp0 (_tmp13_, _tmp16_) < 0) {
						gchar** _tmp17_ = NULL;
						gint _tmp17__length1 = 0;
						gint _tmp18_ = 0;
						const gchar* _tmp19_ = NULL;
						gchar* _tmp20_ = NULL;
						gchar** _tmp21_ = NULL;
						gint _tmp21__length1 = 0;
						gint _tmp22_ = 0;
						gchar** _tmp23_ = NULL;
						gint _tmp23__length1 = 0;
						gint _tmp24_ = 0;
						const gchar* _tmp25_ = NULL;
						gchar* _tmp26_ = NULL;
						gchar* _tmp27_ = NULL;
						gchar** _tmp28_ = NULL;
						gint _tmp28__length1 = 0;
						gint _tmp29_ = 0;
						const gchar* _tmp30_ = NULL;
						gchar* _tmp31_ = NULL;
						gchar* _tmp32_ = NULL;
						_tmp17_ = array;
						_tmp17__length1 = array_length1;
						_tmp18_ = i;
						_tmp19_ = _tmp17_[_tmp18_];
						_tmp20_ = g_strdup (_tmp19_);
						_g_free0 (tmp);
						tmp = _tmp20_;
						_tmp21_ = array;
						_tmp21__length1 = array_length1;
						_tmp22_ = i;
						_tmp23_ = array;
						_tmp23__length1 = array_length1;
						_tmp24_ = i;
						_tmp25_ = _tmp23_[_tmp24_ + 1];
						_tmp26_ = g_strdup (_tmp25_);
						_g_free0 (_tmp21_[_tmp22_]);
						_tmp21_[_tmp22_] = _tmp26_;
						_tmp27_ = _tmp21_[_tmp22_];
						_tmp28_ = array;
						_tmp28__length1 = array_length1;
						_tmp29_ = i;
						_tmp30_ = tmp;
						_tmp31_ = g_strdup (_tmp30_);
						_g_free0 (_tmp28_[_tmp29_ + 1]);
						_tmp28_[_tmp29_ + 1] = _tmp31_;
						_tmp32_ = _tmp28_[_tmp29_ + 1];
						swapped = TRUE;
					}
				}
			}
		}
	}
	_tmp33_ = array;
	_tmp33__length1 = array_length1;
	_tmp34_ = (_tmp33_ != NULL) ? _vala_array_dup8 (_tmp33_, _tmp33__length1) : ((gpointer) _tmp33_);
	_tmp34__length1 = _tmp33__length1;
	_tmp35_ = _tmp34_;
	_tmp35__length1 = _tmp34__length1;
	if (result_length1) {
		*result_length1 = _tmp35__length1;
	}
	result = _tmp35_;
	_g_free0 (tmp);
	return result;
}


gchar** math_variables_get_names (MathVariables* self, int* result_length1) {
	gchar** result = NULL;
	gchar** names = NULL;
	GHashTable* _tmp0_ = NULL;
	guint _tmp1_ = 0U;
	gchar** _tmp2_ = NULL;
	gint names_length1 = 0;
	gint _names_size_ = 0;
	GHashTableIter iter = {0};
	GHashTable* _tmp3_ = NULL;
	gint i = 0;
	gchar* name = NULL;
	Number* value = NULL;
	gchar** _tmp15_ = NULL;
	gint _tmp15__length1 = 0;
	gint _tmp16_ = 0;
	gchar* _tmp17_ = NULL;
	gchar** _tmp18_ = NULL;
	gint _tmp18__length1 = 0;
	gint _tmp19_ = 0;
	gchar** _tmp20_ = NULL;
	gchar** _tmp21_ = NULL;
	gint _tmp21__length1 = 0;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->registers;
	_tmp1_ = g_hash_table_size (_tmp0_);
	_tmp2_ = g_new0 (gchar*, (_tmp1_ + 1) + 1);
	names = _tmp2_;
	names_length1 = _tmp1_ + 1;
	_names_size_ = names_length1;
	_tmp3_ = self->priv->registers;
	g_hash_table_iter_init (&iter, _tmp3_);
	i = 0;
	while (TRUE) {
		gconstpointer _tmp4_ = NULL;
		gconstpointer _tmp5_ = NULL;
		gboolean _tmp6_ = FALSE;
		gchar* _tmp7_ = NULL;
		Number* _tmp8_ = NULL;
		gchar** _tmp9_ = NULL;
		gint _tmp9__length1 = 0;
		gint _tmp10_ = 0;
		const gchar* _tmp11_ = NULL;
		gchar* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		gint _tmp14_ = 0;
		_tmp6_ = g_hash_table_iter_next (&iter, (gpointer*) (&_tmp4_), (gpointer*) (&_tmp5_));
		_g_free0 (name);
		_tmp7_ = g_strdup (_tmp4_);
		name = _tmp7_;
		_g_object_unref0 (value);
		_tmp8_ = _g_object_ref0 (_tmp5_);
		value = _tmp8_;
		if (!_tmp6_) {
			break;
		}
		_tmp9_ = names;
		_tmp9__length1 = names_length1;
		_tmp10_ = i;
		_tmp11_ = name;
		_tmp12_ = g_strdup (_tmp11_);
		_g_free0 (_tmp9_[_tmp10_]);
		_tmp9_[_tmp10_] = _tmp12_;
		_tmp13_ = _tmp9_[_tmp10_];
		_tmp14_ = i;
		i = _tmp14_ + 1;
	}
	_tmp15_ = names;
	_tmp15__length1 = names_length1;
	_tmp16_ = i;
	_g_free0 (_tmp15_[_tmp16_]);
	_tmp15_[_tmp16_] = NULL;
	_tmp17_ = _tmp15_[_tmp16_];
	_tmp18_ = names;
	_tmp18__length1 = names_length1;
	_tmp20_ = math_variables_array_sort_string (self, _tmp18_, _tmp18__length1, &_tmp19_);
	_tmp21_ = _tmp20_;
	_tmp21__length1 = _tmp19_;
	if (result_length1) {
		*result_length1 = _tmp21__length1;
	}
	result = _tmp21_;
	_g_object_unref0 (value);
	_g_free0 (name);
	names = (_vala_array_free (names, names_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


static void _vala_array_add5 (gchar*** array, int* length, int* size, gchar* value) {
	if ((*length) == (*size)) {
		*size = (*size) ? (2 * (*size)) : 4;
		*array = g_renew (gchar*, *array, (*size) + 1);
	}
	(*array)[(*length)++] = value;
	(*array)[*length] = NULL;
}


gchar** math_variables_variables_eligible_for_autocompletion (MathVariables* self, const gchar* text, int* result_length1) {
	gchar** result = NULL;
	gchar** eligible_variables = NULL;
	gchar** _tmp0_ = NULL;
	gint eligible_variables_length1 = 0;
	gint _eligible_variables_size_ = 0;
	const gchar* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	gint _tmp3_ = 0;
	gchar** variables = NULL;
	gint _tmp5_ = 0;
	gchar** _tmp6_ = NULL;
	gint variables_length1 = 0;
	gint _variables_size_ = 0;
	gchar** _tmp7_ = NULL;
	gint _tmp7__length1 = 0;
	gchar** _tmp15_ = NULL;
	gint _tmp15__length1 = 0;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (text != NULL, NULL);
	_tmp0_ = g_new0 (gchar*, 0 + 1);
	eligible_variables = _tmp0_;
	eligible_variables_length1 = 0;
	_eligible_variables_size_ = eligible_variables_length1;
	_tmp1_ = text;
	_tmp2_ = strlen (_tmp1_);
	_tmp3_ = _tmp2_;
	if (_tmp3_ <= 1) {
		gchar** _tmp4_ = NULL;
		gint _tmp4__length1 = 0;
		_tmp4_ = eligible_variables;
		_tmp4__length1 = eligible_variables_length1;
		if (result_length1) {
			*result_length1 = _tmp4__length1;
		}
		result = _tmp4_;
		return result;
	}
	_tmp6_ = math_variables_get_names (self, &_tmp5_);
	variables = _tmp6_;
	variables_length1 = _tmp5_;
	_variables_size_ = variables_length1;
	_tmp7_ = variables;
	_tmp7__length1 = variables_length1;
	{
		gchar** variable_collection = NULL;
		gint variable_collection_length1 = 0;
		gint _variable_collection_size_ = 0;
		gint variable_it = 0;
		variable_collection = _tmp7_;
		variable_collection_length1 = _tmp7__length1;
		for (variable_it = 0; variable_it < _tmp7__length1; variable_it = variable_it + 1) {
			gchar* _tmp8_ = NULL;
			gchar* variable = NULL;
			_tmp8_ = g_strdup (variable_collection[variable_it]);
			variable = _tmp8_;
			{
				const gchar* _tmp9_ = NULL;
				const gchar* _tmp10_ = NULL;
				gboolean _tmp11_ = FALSE;
				_tmp9_ = variable;
				_tmp10_ = text;
				_tmp11_ = g_str_has_prefix (_tmp9_, _tmp10_);
				if (_tmp11_) {
					gchar** _tmp12_ = NULL;
					gint _tmp12__length1 = 0;
					const gchar* _tmp13_ = NULL;
					gchar* _tmp14_ = NULL;
					_tmp12_ = eligible_variables;
					_tmp12__length1 = eligible_variables_length1;
					_tmp13_ = variable;
					_tmp14_ = g_strdup (_tmp13_);
					_vala_array_add5 (&eligible_variables, &eligible_variables_length1, &_eligible_variables_size_, _tmp14_);
				}
				_g_free0 (variable);
			}
		}
	}
	_tmp15_ = eligible_variables;
	_tmp15__length1 = eligible_variables_length1;
	if (result_length1) {
		*result_length1 = _tmp15__length1;
	}
	result = _tmp15_;
	variables = (_vala_array_free (variables, variables_length1, (GDestroyNotify) g_free), NULL);
	return result;
}


void math_variables_set (MathVariables* self, const gchar* name, Number* value) {
	GHashTable* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	Number* _tmp3_ = NULL;
	Number* _tmp4_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	g_return_if_fail (value != NULL);
	_tmp0_ = self->priv->registers;
	_tmp1_ = name;
	_tmp2_ = g_strdup (_tmp1_);
	_tmp3_ = value;
	_tmp4_ = _g_object_ref0 (_tmp3_);
	g_hash_table_insert (_tmp0_, _tmp2_, _tmp4_);
	math_variables_save (self);
}


Number* math_variables_get (MathVariables* self, const gchar* name) {
	Number* result = NULL;
	GHashTable* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gconstpointer _tmp2_ = NULL;
	Number* _tmp3_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = self->priv->registers;
	_tmp1_ = name;
	_tmp2_ = g_hash_table_lookup (_tmp0_, _tmp1_);
	_tmp3_ = _g_object_ref0 ((Number*) _tmp2_);
	result = _tmp3_;
	return result;
}


void math_variables_delete (MathVariables* self, const gchar* name) {
	GHashTable* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (name != NULL);
	_tmp0_ = self->priv->registers;
	_tmp1_ = name;
	g_hash_table_remove (_tmp0_, _tmp1_);
	math_variables_save (self);
}


static void math_variables_class_init (MathVariablesClass * klass) {
	math_variables_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (MathVariablesPrivate));
	G_OBJECT_CLASS (klass)->finalize = math_variables_finalize;
}


static void math_variables_instance_init (MathVariables * self) {
	self->priv = MATH_VARIABLES_GET_PRIVATE (self);
}


static void math_variables_finalize (GObject* obj) {
	MathVariables * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_MATH_VARIABLES, MathVariables);
	_g_free0 (self->priv->file_name);
	_g_hash_table_unref0 (self->priv->registers);
	_g_object_unref0 (self->priv->serializer);
	G_OBJECT_CLASS (math_variables_parent_class)->finalize (obj);
}


GType math_variables_get_type (void) {
	static volatile gsize math_variables_type_id__volatile = 0;
	if (g_once_init_enter (&math_variables_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MathVariablesClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) math_variables_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MathVariables), 0, (GInstanceInitFunc) math_variables_instance_init, NULL };
		GType math_variables_type_id;
		math_variables_type_id = g_type_register_static (G_TYPE_OBJECT, "MathVariables", &g_define_type_info, 0);
		g_once_init_leave (&math_variables_type_id__volatile, math_variables_type_id);
	}
	return math_variables_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}




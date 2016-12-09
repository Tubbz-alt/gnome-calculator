/* math-converter.c generated by valac 0.30.0.14-c43a, the Vala compiler
 * generated from math-converter.vala, do not modify */

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
#include <gtk/gtk.h>
#include "libcalculator.h"
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>


#define TYPE_MATH_CONVERTER (math_converter_get_type ())
#define MATH_CONVERTER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MATH_CONVERTER, MathConverter))
#define MATH_CONVERTER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MATH_CONVERTER, MathConverterClass))
#define IS_MATH_CONVERTER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MATH_CONVERTER))
#define IS_MATH_CONVERTER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MATH_CONVERTER))
#define MATH_CONVERTER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MATH_CONVERTER, MathConverterClass))

typedef struct _MathConverter MathConverter;
typedef struct _MathConverterClass MathConverterClass;
typedef struct _MathConverterPrivate MathConverterPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))

struct _MathConverter {
	GtkBox parent_instance;
	MathConverterPrivate * priv;
};

struct _MathConverterClass {
	GtkBoxClass parent_class;
};

struct _MathConverterPrivate {
	MathEquation* equation;
	gchar* category;
	GtkComboBox* from_combo;
	GtkComboBox* to_combo;
	GtkLabel* result_label;
};


static gpointer math_converter_parent_class = NULL;

GType math_converter_get_type (void) G_GNUC_CONST;
#define MATH_CONVERTER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_MATH_CONVERTER, MathConverterPrivate))
enum  {
	MATH_CONVERTER_DUMMY_PROPERTY
};
MathConverter* math_converter_new (MathEquation* equation);
MathConverter* math_converter_construct (GType object_type, MathEquation* equation);
static void math_converter_from_cell_data_func (MathConverter* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter);
static void _math_converter_from_cell_data_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self);
static void math_converter_from_combobox_changed_cb (MathConverter* self);
static void _math_converter_from_combobox_changed_cb_gtk_combo_box_changed (GtkComboBox* _sender, gpointer self);
static void math_converter_to_combobox_changed_cb (MathConverter* self);
static void _math_converter_to_combobox_changed_cb_gtk_combo_box_changed (GtkComboBox* _sender, gpointer self);
static void math_converter_swap_button_clicked_cb (MathConverter* self);
static void _math_converter_swap_button_clicked_cb_gtk_button_clicked (GtkButton* _sender, gpointer self);
static void __lambda6_ (MathConverter* self);
static void math_converter_update_result_label (MathConverter* self);
static void ___lambda6__currency_manager_updated (CurrencyManager* _sender, gpointer self);
static void __lambda7_ (MathConverter* self, GParamSpec* pspec);
static void ___lambda7__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
static void math_converter_update_from_model (MathConverter* self);
void math_converter_set_category (MathConverter* self, const gchar* category);
gchar* math_converter_get_category (MathConverter* self);
void math_converter_set_conversion (MathConverter* self, const gchar* unit_a, const gchar* unit_b);
static gboolean math_converter_set_active_unit (MathConverter* self, GtkComboBox* combo, GtkTreeIter* iter, Unit* unit);
void math_converter_get_conversion (MathConverter* self, Unit** from_unit, Unit** to_unit);
static Number* math_converter_convert_equation (MathConverter* self, Number* x);
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
static gboolean math_converter_iter_is_unit (MathConverter* self, GtkTreeModel* model, GtkTreeIter* iter, Unit* unit);
static void math_converter_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _math_converter_from_cell_data_func_gtk_cell_layout_data_func (GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter, gpointer self) {
	math_converter_from_cell_data_func ((MathConverter*) self, cell_layout, cell, tree_model, iter);
}


static void _math_converter_from_combobox_changed_cb_gtk_combo_box_changed (GtkComboBox* _sender, gpointer self) {
	math_converter_from_combobox_changed_cb ((MathConverter*) self);
}


static void _math_converter_to_combobox_changed_cb_gtk_combo_box_changed (GtkComboBox* _sender, gpointer self) {
	math_converter_to_combobox_changed_cb ((MathConverter*) self);
}


static void _math_converter_swap_button_clicked_cb_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	math_converter_swap_button_clicked_cb ((MathConverter*) self);
}


static void __lambda6_ (MathConverter* self) {
	math_converter_update_result_label (self);
}


static void ___lambda6__currency_manager_updated (CurrencyManager* _sender, gpointer self) {
	__lambda6_ ((MathConverter*) self);
}


static void __lambda7_ (MathConverter* self, GParamSpec* pspec) {
	g_return_if_fail (pspec != NULL);
	math_converter_update_result_label (self);
}


static void ___lambda7__g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	__lambda7_ ((MathConverter*) self, pspec);
}


MathConverter* math_converter_construct (GType object_type, MathEquation* equation) {
	MathConverter * self = NULL;
	MathEquation* _tmp0_ = NULL;
	MathEquation* _tmp1_ = NULL;
	GtkBox* hbox = NULL;
	GtkBox* _tmp2_ = NULL;
	GtkComboBox* _tmp3_ = NULL;
	GtkCellRendererText* renderer = NULL;
	GtkCellRendererText* _tmp4_ = NULL;
	GtkComboBox* _tmp5_ = NULL;
	GtkCellRendererText* _tmp6_ = NULL;
	GtkComboBox* _tmp7_ = NULL;
	GtkCellRendererText* _tmp8_ = NULL;
	GtkComboBox* _tmp9_ = NULL;
	GtkCellRendererText* _tmp10_ = NULL;
	GtkComboBox* _tmp11_ = NULL;
	GtkComboBox* _tmp12_ = NULL;
	GtkComboBox* _tmp13_ = NULL;
	GtkLabel* label = NULL;
	const gchar* _tmp14_ = NULL;
	GtkLabel* _tmp15_ = NULL;
	GtkComboBox* _tmp16_ = NULL;
	GtkCellRendererText* _tmp17_ = NULL;
	GtkComboBox* _tmp18_ = NULL;
	GtkCellRendererText* _tmp19_ = NULL;
	GtkComboBox* _tmp20_ = NULL;
	GtkCellRendererText* _tmp21_ = NULL;
	GtkComboBox* _tmp22_ = NULL;
	GtkComboBox* _tmp23_ = NULL;
	GtkComboBox* _tmp24_ = NULL;
	GtkButton* swap_button = NULL;
	GtkButton* _tmp25_ = NULL;
	const gchar* _tmp26_ = NULL;
	GtkLabel* _tmp27_ = NULL;
	GtkLabel* _tmp28_ = NULL;
	GtkLabel* _tmp29_ = NULL;
	GtkLabel* _tmp30_ = NULL;
	GtkLabel* _tmp31_ = NULL;
	CurrencyManager* _tmp32_ = NULL;
	CurrencyManager* _tmp33_ = NULL;
	MathEquation* _tmp34_ = NULL;
	g_return_val_if_fail (equation != NULL, NULL);
	self = (MathConverter*) g_object_new (object_type, "orientation", GTK_ORIENTATION_HORIZONTAL, NULL);
	_tmp0_ = equation;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->equation);
	self->priv->equation = _tmp1_;
	gtk_box_set_spacing ((GtkBox*) self, 6);
	_tmp2_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
	g_object_ref_sink (_tmp2_);
	hbox = _tmp2_;
	gtk_widget_show ((GtkWidget*) hbox);
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) hbox, FALSE, TRUE, (guint) 0);
	_tmp3_ = (GtkComboBox*) gtk_combo_box_new ();
	g_object_ref_sink (_tmp3_);
	_g_object_unref0 (self->priv->from_combo);
	self->priv->from_combo = _tmp3_;
	_tmp4_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
	g_object_ref_sink (_tmp4_);
	renderer = _tmp4_;
	_tmp5_ = self->priv->from_combo;
	_tmp6_ = renderer;
	gtk_cell_layout_pack_start ((GtkCellLayout*) _tmp5_, (GtkCellRenderer*) _tmp6_, TRUE);
	_tmp7_ = self->priv->from_combo;
	_tmp8_ = renderer;
	gtk_cell_layout_add_attribute ((GtkCellLayout*) _tmp7_, (GtkCellRenderer*) _tmp8_, "text", 0);
	_tmp9_ = self->priv->from_combo;
	_tmp10_ = renderer;
	gtk_cell_layout_set_cell_data_func ((GtkCellLayout*) _tmp9_, (GtkCellRenderer*) _tmp10_, _math_converter_from_cell_data_func_gtk_cell_layout_data_func, g_object_ref (self), g_object_unref);
	_tmp11_ = self->priv->from_combo;
	g_signal_connect_object (_tmp11_, "changed", (GCallback) _math_converter_from_combobox_changed_cb_gtk_combo_box_changed, self, 0);
	_tmp12_ = self->priv->from_combo;
	gtk_widget_show ((GtkWidget*) _tmp12_);
	_tmp13_ = self->priv->from_combo;
	gtk_box_pack_start (hbox, (GtkWidget*) _tmp13_, FALSE, TRUE, (guint) 0);
	_tmp14_ = _ (" in ");
	_tmp15_ = (GtkLabel*) gtk_label_new (_tmp14_);
	g_object_ref_sink (_tmp15_);
	label = _tmp15_;
	gtk_widget_show ((GtkWidget*) label);
	gtk_box_pack_start (hbox, (GtkWidget*) label, FALSE, TRUE, (guint) 5);
	_tmp16_ = (GtkComboBox*) gtk_combo_box_new ();
	g_object_ref_sink (_tmp16_);
	_g_object_unref0 (self->priv->to_combo);
	self->priv->to_combo = _tmp16_;
	_tmp17_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
	g_object_ref_sink (_tmp17_);
	_g_object_unref0 (renderer);
	renderer = _tmp17_;
	_tmp18_ = self->priv->to_combo;
	_tmp19_ = renderer;
	gtk_cell_layout_pack_start ((GtkCellLayout*) _tmp18_, (GtkCellRenderer*) _tmp19_, TRUE);
	_tmp20_ = self->priv->to_combo;
	_tmp21_ = renderer;
	gtk_cell_layout_add_attribute ((GtkCellLayout*) _tmp20_, (GtkCellRenderer*) _tmp21_, "text", 0);
	_tmp22_ = self->priv->to_combo;
	g_signal_connect_object (_tmp22_, "changed", (GCallback) _math_converter_to_combobox_changed_cb_gtk_combo_box_changed, self, 0);
	_tmp23_ = self->priv->to_combo;
	gtk_widget_show ((GtkWidget*) _tmp23_);
	_tmp24_ = self->priv->to_combo;
	gtk_box_pack_start (hbox, (GtkWidget*) _tmp24_, FALSE, TRUE, (guint) 0);
	_tmp25_ = (GtkButton*) gtk_button_new_with_label ("⇆");
	g_object_ref_sink (_tmp25_);
	swap_button = _tmp25_;
	_tmp26_ = _ ("Switch conversion units");
	gtk_widget_set_tooltip_text ((GtkWidget*) swap_button, _tmp26_);
	gtk_button_set_relief (swap_button, GTK_RELIEF_NONE);
	g_signal_connect_object (swap_button, "clicked", (GCallback) _math_converter_swap_button_clicked_cb_gtk_button_clicked, self, 0);
	gtk_widget_show ((GtkWidget*) swap_button);
	gtk_box_pack_start (hbox, (GtkWidget*) swap_button, FALSE, TRUE, (guint) 0);
	_tmp27_ = (GtkLabel*) gtk_label_new ("");
	g_object_ref_sink (_tmp27_);
	_g_object_unref0 (self->priv->result_label);
	self->priv->result_label = _tmp27_;
	_tmp28_ = self->priv->result_label;
	gtk_misc_set_alignment ((GtkMisc*) _tmp28_, 1.0f, 0.5f);
	_tmp29_ = self->priv->result_label;
	gtk_widget_set_sensitive ((GtkWidget*) _tmp29_, FALSE);
	_tmp30_ = self->priv->result_label;
	gtk_widget_show ((GtkWidget*) _tmp30_);
	_tmp31_ = self->priv->result_label;
	gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) _tmp31_, TRUE, TRUE, (guint) 0);
	_tmp32_ = currency_manager_get_default ();
	_tmp33_ = _tmp32_;
	g_signal_connect_object (_tmp33_, "updated", (GCallback) ___lambda6__currency_manager_updated, self, 0);
	_g_object_unref0 (_tmp33_);
	_tmp34_ = equation;
	g_signal_connect_object ((GObject*) _tmp34_, "notify::display", (GCallback) ___lambda7__g_object_notify, self, 0);
	math_converter_update_from_model (self);
	_g_object_unref0 (swap_button);
	_g_object_unref0 (label);
	_g_object_unref0 (renderer);
	_g_object_unref0 (hbox);
	return self;
}


MathConverter* math_converter_new (MathEquation* equation) {
	return math_converter_construct (TYPE_MATH_CONVERTER, equation);
}


void math_converter_set_category (MathConverter* self, const gchar* category) {
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->category;
	_tmp1_ = category;
	if (g_strcmp0 (_tmp0_, _tmp1_) == 0) {
		return;
	}
	_tmp2_ = category;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->priv->category);
	self->priv->category = _tmp3_;
	math_converter_update_from_model (self);
}


gchar* math_converter_get_category (MathConverter* self) {
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->category;
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}


void math_converter_set_conversion (MathConverter* self, const gchar* unit_a, const gchar* unit_b) {
	Unit* ua = NULL;
	UnitManager* _tmp0_ = NULL;
	UnitManager* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	Unit* _tmp3_ = NULL;
	Unit* _tmp4_ = NULL;
	Unit* ub = NULL;
	UnitManager* _tmp5_ = NULL;
	UnitManager* _tmp6_ = NULL;
	const gchar* _tmp7_ = NULL;
	Unit* _tmp8_ = NULL;
	Unit* _tmp9_ = NULL;
	gboolean _tmp10_ = FALSE;
	Unit* _tmp11_ = NULL;
	GtkComboBox* _tmp26_ = NULL;
	Unit* _tmp27_ = NULL;
	GtkComboBox* _tmp28_ = NULL;
	Unit* _tmp29_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (unit_a != NULL);
	g_return_if_fail (unit_b != NULL);
	_tmp0_ = unit_manager_get_default ();
	_tmp1_ = _tmp0_;
	_tmp2_ = unit_a;
	_tmp3_ = unit_manager_get_unit_by_name (_tmp1_, _tmp2_);
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp1_);
	ua = _tmp4_;
	_tmp5_ = unit_manager_get_default ();
	_tmp6_ = _tmp5_;
	_tmp7_ = unit_b;
	_tmp8_ = unit_manager_get_unit_by_name (_tmp6_, _tmp7_);
	_tmp9_ = _tmp8_;
	_g_object_unref0 (_tmp6_);
	ub = _tmp9_;
	_tmp11_ = ua;
	if (_tmp11_ == NULL) {
		_tmp10_ = TRUE;
	} else {
		Unit* _tmp12_ = NULL;
		_tmp12_ = ub;
		_tmp10_ = _tmp12_ == NULL;
	}
	if (_tmp10_) {
		GtkTreeModel* model = NULL;
		GtkComboBox* _tmp13_ = NULL;
		GtkTreeModel* _tmp14_ = NULL;
		GtkTreeModel* _tmp15_ = NULL;
		GtkTreeIter iter = {0};
		GtkTreeModel* _tmp16_ = NULL;
		GtkTreeIter _tmp17_ = {0};
		gboolean _tmp18_ = FALSE;
		_tmp13_ = self->priv->from_combo;
		_tmp14_ = gtk_combo_box_get_model (_tmp13_);
		_tmp15_ = _g_object_ref0 (_tmp14_);
		model = _tmp15_;
		_tmp16_ = model;
		_tmp18_ = gtk_tree_model_get_iter_first (_tmp16_, &_tmp17_);
		iter = _tmp17_;
		if (_tmp18_) {
			GtkTreeIter child_iter = {0};
			GtkComboBox* _tmp24_ = NULL;
			GtkTreeIter _tmp25_ = {0};
			while (TRUE) {
				GtkTreeModel* _tmp19_ = NULL;
				GtkTreeIter _tmp20_ = {0};
				GtkTreeIter _tmp21_ = {0};
				gboolean _tmp22_ = FALSE;
				GtkTreeIter _tmp23_ = {0};
				_tmp19_ = model;
				_tmp20_ = iter;
				_tmp22_ = gtk_tree_model_iter_children (_tmp19_, &_tmp21_, &_tmp20_);
				child_iter = _tmp21_;
				if (!_tmp22_) {
					break;
				}
				_tmp23_ = child_iter;
				iter = _tmp23_;
			}
			_tmp24_ = self->priv->from_combo;
			_tmp25_ = iter;
			gtk_combo_box_set_active_iter (_tmp24_, &_tmp25_);
		}
		_g_object_unref0 (model);
		_g_object_unref0 (ub);
		_g_object_unref0 (ua);
		return;
	}
	_tmp26_ = self->priv->from_combo;
	_tmp27_ = ua;
	math_converter_set_active_unit (self, _tmp26_, NULL, _tmp27_);
	_tmp28_ = self->priv->to_combo;
	_tmp29_ = ub;
	math_converter_set_active_unit (self, _tmp28_, NULL, _tmp29_);
	_g_object_unref0 (ub);
	_g_object_unref0 (ua);
}


void math_converter_get_conversion (MathConverter* self, Unit** from_unit, Unit** to_unit) {
	Unit* _vala_from_unit = NULL;
	Unit* _vala_to_unit = NULL;
	GtkTreeIter from_iter = {0};
	GtkTreeIter to_iter = {0};
	GtkComboBox* _tmp0_ = NULL;
	GtkTreeIter _tmp1_ = {0};
	GtkComboBox* _tmp2_ = NULL;
	GtkTreeIter _tmp3_ = {0};
	GtkComboBox* _tmp4_ = NULL;
	GtkTreeModel* _tmp5_ = NULL;
	GtkTreeIter _tmp6_ = {0};
	GtkComboBox* _tmp7_ = NULL;
	GtkTreeModel* _tmp8_ = NULL;
	GtkTreeIter _tmp9_ = {0};
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->from_combo;
	gtk_combo_box_get_active_iter (_tmp0_, &_tmp1_);
	from_iter = _tmp1_;
	_tmp2_ = self->priv->to_combo;
	gtk_combo_box_get_active_iter (_tmp2_, &_tmp3_);
	to_iter = _tmp3_;
	_tmp4_ = self->priv->from_combo;
	_tmp5_ = gtk_combo_box_get_model (_tmp4_);
	_tmp6_ = from_iter;
	gtk_tree_model_get (_tmp5_, &_tmp6_, 2, &_vala_from_unit, -1, -1);
	_tmp7_ = self->priv->to_combo;
	_tmp8_ = gtk_combo_box_get_model (_tmp7_);
	_tmp9_ = to_iter;
	gtk_tree_model_get (_tmp8_, &_tmp9_, 2, &_vala_to_unit, -1, -1);
	if (from_unit) {
		*from_unit = _vala_from_unit;
	} else {
		_g_object_unref0 (_vala_from_unit);
	}
	if (to_unit) {
		*to_unit = _vala_to_unit;
	} else {
		_g_object_unref0 (_vala_to_unit);
	}
}


static void math_converter_update_result_label (MathConverter* self) {
	Number* x = NULL;
	MathEquation* _tmp0_ = NULL;
	Number* _tmp1_ = NULL;
	Number* _tmp2_ = NULL;
	Number* _tmp3_ = NULL;
	Number* z = NULL;
	Number* _tmp4_ = NULL;
	Number* _tmp5_ = NULL;
	GtkLabel* _tmp6_ = NULL;
	Number* _tmp7_ = NULL;
	Number* _tmp8_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->equation;
	_tmp1_ = math_equation_get_number (_tmp0_);
	_tmp2_ = _tmp1_;
	x = _tmp2_;
	_tmp3_ = x;
	if (_tmp3_ == NULL) {
		_g_object_unref0 (x);
		return;
	}
	_tmp4_ = x;
	_tmp5_ = math_converter_convert_equation (self, _tmp4_);
	z = _tmp5_;
	_tmp6_ = self->priv->result_label;
	_tmp7_ = z;
	gtk_widget_set_sensitive ((GtkWidget*) _tmp6_, _tmp7_ != NULL);
	_tmp8_ = z;
	if (_tmp8_ != NULL) {
		Unit* source_unit = NULL;
		Unit* target_unit = NULL;
		Unit* _tmp9_ = NULL;
		Unit* _tmp10_ = NULL;
		gchar* source_text = NULL;
		Unit* _tmp11_ = NULL;
		Number* _tmp12_ = NULL;
		gchar* _tmp13_ = NULL;
		gchar* target_text = NULL;
		Unit* _tmp14_ = NULL;
		Number* _tmp15_ = NULL;
		gchar* _tmp16_ = NULL;
		GtkLabel* _tmp17_ = NULL;
		const gchar* _tmp18_ = NULL;
		const gchar* _tmp19_ = NULL;
		gchar* _tmp20_ = NULL;
		gchar* _tmp21_ = NULL;
		math_converter_get_conversion (self, &_tmp9_, &_tmp10_);
		_g_object_unref0 (source_unit);
		source_unit = _tmp9_;
		_g_object_unref0 (target_unit);
		target_unit = _tmp10_;
		_tmp11_ = source_unit;
		_tmp12_ = x;
		_tmp13_ = unit_format (_tmp11_, _tmp12_);
		source_text = _tmp13_;
		_tmp14_ = target_unit;
		_tmp15_ = z;
		_tmp16_ = unit_format (_tmp14_, _tmp15_);
		target_text = _tmp16_;
		_tmp17_ = self->priv->result_label;
		_tmp18_ = source_text;
		_tmp19_ = target_text;
		_tmp20_ = g_strdup_printf ("%s = %s", _tmp18_, _tmp19_);
		_tmp21_ = _tmp20_;
		gtk_label_set_text (_tmp17_, _tmp21_);
		_g_free0 (_tmp21_);
		_g_free0 (target_text);
		_g_free0 (source_text);
		_g_object_unref0 (target_unit);
		_g_object_unref0 (source_unit);
	}
	_g_object_unref0 (z);
	_g_object_unref0 (x);
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


static void math_converter_update_from_model (MathConverter* self) {
	GtkTreeStore* from_model = NULL;
	GtkTreeStore* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	GtkComboBox* _tmp49_ = NULL;
	GtkTreeStore* _tmp50_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = gtk_tree_store_new (3, G_TYPE_STRING, TYPE_UNIT_CATEGORY, TYPE_UNIT);
	from_model = _tmp0_;
	_tmp1_ = self->priv->category;
	if (_tmp1_ == NULL) {
		GList* categories = NULL;
		UnitManager* _tmp2_ = NULL;
		UnitManager* _tmp3_ = NULL;
		GList* _tmp4_ = NULL;
		GList* _tmp5_ = NULL;
		GList* _tmp6_ = NULL;
		_tmp2_ = unit_manager_get_default ();
		_tmp3_ = _tmp2_;
		_tmp4_ = unit_manager_get_categories (_tmp3_);
		_tmp5_ = _tmp4_;
		_g_object_unref0 (_tmp3_);
		categories = _tmp5_;
		_tmp6_ = categories;
		{
			GList* category_collection = NULL;
			GList* category_it = NULL;
			category_collection = _tmp6_;
			for (category_it = category_collection; category_it != NULL; category_it = category_it->next) {
				UnitCategory* _tmp7_ = NULL;
				UnitCategory* category = NULL;
				_tmp7_ = _g_object_ref0 ((UnitCategory*) category_it->data);
				category = _tmp7_;
				{
					GtkTreeIter parent = {0};
					GtkTreeStore* _tmp8_ = NULL;
					GtkTreeIter _tmp9_ = {0};
					GtkTreeStore* _tmp10_ = NULL;
					GtkTreeIter _tmp11_ = {0};
					UnitCategory* _tmp12_ = NULL;
					gchar* _tmp13_ = NULL;
					gchar* _tmp14_ = NULL;
					gchar* _tmp15_ = NULL;
					UnitCategory* _tmp16_ = NULL;
					UnitCategory* _tmp17_ = NULL;
					GList* _tmp18_ = NULL;
					_tmp8_ = from_model;
					gtk_tree_store_append (_tmp8_, &_tmp9_, NULL);
					parent = _tmp9_;
					_tmp10_ = from_model;
					_tmp11_ = parent;
					_tmp12_ = category;
					_tmp13_ = unit_category_get_display_name (_tmp12_);
					_tmp14_ = _tmp13_;
					_tmp15_ = _tmp14_;
					_tmp16_ = category;
					gtk_tree_store_set (_tmp10_, &_tmp11_, 0, _tmp15_, 1, _tmp16_, -1, -1);
					_g_free0 (_tmp15_);
					_tmp17_ = category;
					_tmp18_ = unit_category_get_units (_tmp17_);
					{
						GList* unit_collection = NULL;
						GList* unit_it = NULL;
						unit_collection = _tmp18_;
						for (unit_it = unit_collection; unit_it != NULL; unit_it = unit_it->next) {
							Unit* _tmp19_ = NULL;
							Unit* unit = NULL;
							_tmp19_ = _g_object_ref0 ((Unit*) unit_it->data);
							unit = _tmp19_;
							{
								GtkTreeIter iter = {0};
								GtkTreeStore* _tmp20_ = NULL;
								GtkTreeIter _tmp21_ = {0};
								GtkTreeIter _tmp22_ = {0};
								GtkTreeStore* _tmp23_ = NULL;
								GtkTreeIter _tmp24_ = {0};
								Unit* _tmp25_ = NULL;
								gchar* _tmp26_ = NULL;
								gchar* _tmp27_ = NULL;
								gchar* _tmp28_ = NULL;
								UnitCategory* _tmp29_ = NULL;
								Unit* _tmp30_ = NULL;
								_tmp20_ = from_model;
								_tmp21_ = parent;
								gtk_tree_store_append (_tmp20_, &_tmp22_, &_tmp21_);
								iter = _tmp22_;
								_tmp23_ = from_model;
								_tmp24_ = iter;
								_tmp25_ = unit;
								_tmp26_ = unit_get_display_name (_tmp25_);
								_tmp27_ = _tmp26_;
								_tmp28_ = _tmp27_;
								_tmp29_ = category;
								_tmp30_ = unit;
								gtk_tree_store_set (_tmp23_, &_tmp24_, 0, _tmp28_, 1, _tmp29_, 2, _tmp30_, -1, -1);
								_g_free0 (_tmp28_);
								_g_object_unref0 (unit);
							}
						}
					}
					_g_object_unref0 (category);
				}
			}
		}
		__g_list_free__g_object_unref0_0 (categories);
	} else {
		UnitCategory* c = NULL;
		UnitManager* _tmp31_ = NULL;
		UnitManager* _tmp32_ = NULL;
		const gchar* _tmp33_ = NULL;
		UnitCategory* _tmp34_ = NULL;
		UnitCategory* _tmp35_ = NULL;
		UnitCategory* _tmp36_ = NULL;
		GList* _tmp37_ = NULL;
		_tmp31_ = unit_manager_get_default ();
		_tmp32_ = _tmp31_;
		_tmp33_ = self->priv->category;
		_tmp34_ = unit_manager_get_category (_tmp32_, _tmp33_);
		_tmp35_ = _tmp34_;
		_g_object_unref0 (_tmp32_);
		c = _tmp35_;
		_tmp36_ = c;
		_tmp37_ = unit_category_get_units (_tmp36_);
		{
			GList* unit_collection = NULL;
			GList* unit_it = NULL;
			unit_collection = _tmp37_;
			for (unit_it = unit_collection; unit_it != NULL; unit_it = unit_it->next) {
				Unit* _tmp38_ = NULL;
				Unit* unit = NULL;
				_tmp38_ = _g_object_ref0 ((Unit*) unit_it->data);
				unit = _tmp38_;
				{
					GtkTreeIter iter = {0};
					GtkTreeStore* _tmp39_ = NULL;
					GtkTreeIter _tmp40_ = {0};
					GtkTreeStore* _tmp41_ = NULL;
					GtkTreeIter _tmp42_ = {0};
					Unit* _tmp43_ = NULL;
					gchar* _tmp44_ = NULL;
					gchar* _tmp45_ = NULL;
					gchar* _tmp46_ = NULL;
					UnitCategory* _tmp47_ = NULL;
					Unit* _tmp48_ = NULL;
					_tmp39_ = from_model;
					gtk_tree_store_append (_tmp39_, &_tmp40_, NULL);
					iter = _tmp40_;
					_tmp41_ = from_model;
					_tmp42_ = iter;
					_tmp43_ = unit;
					_tmp44_ = unit_get_display_name (_tmp43_);
					_tmp45_ = _tmp44_;
					_tmp46_ = _tmp45_;
					_tmp47_ = c;
					_tmp48_ = unit;
					gtk_tree_store_set (_tmp41_, &_tmp42_, 0, _tmp46_, 1, _tmp47_, 2, _tmp48_, -1, -1);
					_g_free0 (_tmp46_);
					_g_object_unref0 (unit);
				}
			}
		}
		_g_object_unref0 (c);
	}
	_tmp49_ = self->priv->from_combo;
	_tmp50_ = from_model;
	gtk_combo_box_set_model (_tmp49_, (GtkTreeModel*) _tmp50_);
	_g_object_unref0 (from_model);
}


static gboolean math_converter_iter_is_unit (MathConverter* self, GtkTreeModel* model, GtkTreeIter* iter, Unit* unit) {
	gboolean result = FALSE;
	Unit* u = NULL;
	GtkTreeModel* _tmp0_ = NULL;
	GtkTreeIter _tmp1_ = {0};
	Unit* _tmp2_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (model != NULL, FALSE);
	g_return_val_if_fail (iter != NULL, FALSE);
	g_return_val_if_fail (unit != NULL, FALSE);
	_tmp0_ = model;
	_tmp1_ = *iter;
	gtk_tree_model_get (_tmp0_, &_tmp1_, 2, &u, -1, -1);
	_tmp2_ = unit;
	result = u == _tmp2_;
	_g_object_unref0 (u);
	return result;
}


static gboolean math_converter_set_active_unit (MathConverter* self, GtkComboBox* combo, GtkTreeIter* iter, Unit* unit) {
	gboolean result = FALSE;
	GtkTreeModel* model = NULL;
	GtkComboBox* _tmp0_ = NULL;
	GtkTreeModel* _tmp1_ = NULL;
	GtkTreeModel* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	GtkTreeIter* _tmp4_ = NULL;
	GtkTreeIter child_iter = {0};
	GtkTreeModel* _tmp12_ = NULL;
	GtkTreeIter* _tmp13_ = NULL;
	GtkTreeIter _tmp14_ = {0};
	gboolean _tmp15_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (combo != NULL, FALSE);
	g_return_val_if_fail (unit != NULL, FALSE);
	_tmp0_ = combo;
	_tmp1_ = gtk_combo_box_get_model (_tmp0_);
	_tmp2_ = _g_object_ref0 (_tmp1_);
	model = _tmp2_;
	_tmp4_ = iter;
	if (_tmp4_ != NULL) {
		GtkTreeModel* _tmp5_ = NULL;
		GtkTreeIter* _tmp6_ = NULL;
		Unit* _tmp7_ = NULL;
		GtkTreeIter _tmp8_ = {0};
		gboolean _tmp9_ = FALSE;
		_tmp5_ = model;
		_tmp6_ = iter;
		_tmp7_ = unit;
		_tmp8_ = *_tmp6_;
		_tmp9_ = math_converter_iter_is_unit (self, _tmp5_, &_tmp8_, _tmp7_);
		_tmp3_ = _tmp9_;
	} else {
		_tmp3_ = FALSE;
	}
	if (_tmp3_) {
		GtkComboBox* _tmp10_ = NULL;
		GtkTreeIter* _tmp11_ = NULL;
		_tmp10_ = combo;
		_tmp11_ = iter;
		gtk_combo_box_set_active_iter (_tmp10_, _tmp11_);
		result = TRUE;
		_g_object_unref0 (model);
		return result;
	}
	_tmp12_ = model;
	_tmp13_ = iter;
	_tmp15_ = gtk_tree_model_iter_children (_tmp12_, &_tmp14_, _tmp13_);
	child_iter = _tmp14_;
	if (!_tmp15_) {
		result = FALSE;
		_g_object_unref0 (model);
		return result;
	}
	{
		gboolean _tmp16_ = FALSE;
		_tmp16_ = TRUE;
		while (TRUE) {
			GtkComboBox* _tmp19_ = NULL;
			GtkTreeIter _tmp20_ = {0};
			Unit* _tmp21_ = NULL;
			gboolean _tmp22_ = FALSE;
			if (!_tmp16_) {
				GtkTreeModel* _tmp17_ = NULL;
				gboolean _tmp18_ = FALSE;
				_tmp17_ = model;
				_tmp18_ = gtk_tree_model_iter_next (_tmp17_, &child_iter);
				if (!_tmp18_) {
					break;
				}
			}
			_tmp16_ = FALSE;
			_tmp19_ = combo;
			_tmp20_ = child_iter;
			_tmp21_ = unit;
			_tmp22_ = math_converter_set_active_unit (self, _tmp19_, &_tmp20_, _tmp21_);
			if (_tmp22_) {
				result = TRUE;
				_g_object_unref0 (model);
				return result;
			}
		}
	}
	result = FALSE;
	_g_object_unref0 (model);
	return result;
}


static void math_converter_from_combobox_changed_cb (MathConverter* self) {
	GtkTreeModel* model = NULL;
	GtkComboBox* _tmp0_ = NULL;
	GtkTreeModel* _tmp1_ = NULL;
	GtkTreeModel* _tmp2_ = NULL;
	GtkTreeIter iter = {0};
	GtkComboBox* _tmp3_ = NULL;
	GtkTreeIter _tmp4_ = {0};
	gboolean _tmp5_ = FALSE;
	UnitCategory* category = NULL;
	Unit* unit = NULL;
	GtkTreeModel* _tmp6_ = NULL;
	GtkTreeIter _tmp7_ = {0};
	GtkListStore* to_model = NULL;
	GtkListStore* _tmp8_ = NULL;
	UnitCategory* _tmp9_ = NULL;
	GList* _tmp10_ = NULL;
	GtkComboBox* _tmp24_ = NULL;
	GtkListStore* _tmp25_ = NULL;
	GtkComboBox* _tmp26_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->from_combo;
	_tmp1_ = gtk_combo_box_get_model (_tmp0_);
	_tmp2_ = _g_object_ref0 (_tmp1_);
	model = _tmp2_;
	_tmp3_ = self->priv->from_combo;
	_tmp5_ = gtk_combo_box_get_active_iter (_tmp3_, &_tmp4_);
	iter = _tmp4_;
	if (!_tmp5_) {
		_g_object_unref0 (model);
		return;
	}
	_tmp6_ = model;
	_tmp7_ = iter;
	gtk_tree_model_get (_tmp6_, &_tmp7_, 1, &category, 2, &unit, -1, -1);
	_tmp8_ = gtk_list_store_new (3, G_TYPE_STRING, TYPE_UNIT_CATEGORY, TYPE_UNIT, -1);
	to_model = _tmp8_;
	_tmp9_ = category;
	_tmp10_ = unit_category_get_units (_tmp9_);
	{
		GList* u_collection = NULL;
		GList* u_it = NULL;
		u_collection = _tmp10_;
		for (u_it = u_collection; u_it != NULL; u_it = u_it->next) {
			Unit* _tmp11_ = NULL;
			Unit* u = NULL;
			_tmp11_ = _g_object_ref0 ((Unit*) u_it->data);
			u = _tmp11_;
			{
				Unit* _tmp12_ = NULL;
				Unit* _tmp13_ = NULL;
				GtkListStore* _tmp14_ = NULL;
				GtkTreeIter _tmp15_ = {0};
				GtkListStore* _tmp16_ = NULL;
				GtkTreeIter _tmp17_ = {0};
				Unit* _tmp18_ = NULL;
				gchar* _tmp19_ = NULL;
				gchar* _tmp20_ = NULL;
				gchar* _tmp21_ = NULL;
				UnitCategory* _tmp22_ = NULL;
				Unit* _tmp23_ = NULL;
				_tmp12_ = u;
				_tmp13_ = unit;
				if (_tmp12_ == _tmp13_) {
					_g_object_unref0 (u);
					continue;
				}
				_tmp14_ = to_model;
				gtk_list_store_append (_tmp14_, &_tmp15_);
				iter = _tmp15_;
				_tmp16_ = to_model;
				_tmp17_ = iter;
				_tmp18_ = u;
				_tmp19_ = unit_get_display_name (_tmp18_);
				_tmp20_ = _tmp19_;
				_tmp21_ = _tmp20_;
				_tmp22_ = category;
				_tmp23_ = u;
				gtk_list_store_set (_tmp16_, &_tmp17_, 0, _tmp21_, 1, _tmp22_, 2, _tmp23_, -1, -1);
				_g_free0 (_tmp21_);
				_g_object_unref0 (u);
			}
		}
	}
	_tmp24_ = self->priv->to_combo;
	_tmp25_ = to_model;
	gtk_combo_box_set_model (_tmp24_, (GtkTreeModel*) _tmp25_);
	_tmp26_ = self->priv->to_combo;
	gtk_combo_box_set_active (_tmp26_, 0);
	_g_object_unref0 (to_model);
	_g_object_unref0 (unit);
	_g_object_unref0 (category);
	_g_object_unref0 (model);
}


static void math_converter_to_combobox_changed_cb (MathConverter* self) {
	g_return_if_fail (self != NULL);
	math_converter_update_result_label (self);
	g_signal_emit_by_name (self, "changed");
}


static void math_converter_from_cell_data_func (MathConverter* self, GtkCellLayout* cell_layout, GtkCellRenderer* cell, GtkTreeModel* tree_model, GtkTreeIter* iter) {
	GtkCellRenderer* _tmp0_ = NULL;
	GtkTreeModel* _tmp1_ = NULL;
	GtkTreeIter _tmp2_ = {0};
	gboolean _tmp3_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (cell_layout != NULL);
	g_return_if_fail (cell != NULL);
	g_return_if_fail (tree_model != NULL);
	g_return_if_fail (iter != NULL);
	_tmp0_ = cell;
	_tmp1_ = tree_model;
	_tmp2_ = *iter;
	_tmp3_ = gtk_tree_model_iter_has_child (_tmp1_, &_tmp2_);
	g_object_set ((GObject*) _tmp0_, "sensitive", !_tmp3_, NULL);
}


static void math_converter_swap_button_clicked_cb (MathConverter* self) {
	Number* x = NULL;
	MathEquation* _tmp0_ = NULL;
	Number* _tmp1_ = NULL;
	Number* _tmp2_ = NULL;
	Number* _tmp3_ = NULL;
	Unit* from_unit = NULL;
	Unit* to_unit = NULL;
	Unit* _tmp9_ = NULL;
	Unit* _tmp10_ = NULL;
	GtkComboBox* _tmp11_ = NULL;
	GtkComboBox* _tmp12_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->equation;
	_tmp1_ = math_equation_get_number (_tmp0_);
	_tmp2_ = _tmp1_;
	x = _tmp2_;
	_tmp3_ = x;
	if (_tmp3_ != NULL) {
		Number* z = NULL;
		Number* _tmp4_ = NULL;
		Number* _tmp5_ = NULL;
		Number* _tmp6_ = NULL;
		_tmp4_ = x;
		_tmp5_ = math_converter_convert_equation (self, _tmp4_);
		z = _tmp5_;
		_tmp6_ = z;
		if (_tmp6_ != NULL) {
			MathEquation* _tmp7_ = NULL;
			Number* _tmp8_ = NULL;
			_tmp7_ = self->priv->equation;
			_tmp8_ = z;
			math_equation_set_number (_tmp7_, _tmp8_, (guint) 0);
		}
		_g_object_unref0 (z);
	}
	math_converter_get_conversion (self, &_tmp9_, &_tmp10_);
	_g_object_unref0 (from_unit);
	from_unit = _tmp9_;
	_g_object_unref0 (to_unit);
	to_unit = _tmp10_;
	_tmp11_ = self->priv->from_combo;
	math_converter_set_active_unit (self, _tmp11_, NULL, to_unit);
	_tmp12_ = self->priv->to_combo;
	math_converter_set_active_unit (self, _tmp12_, NULL, from_unit);
	math_converter_update_result_label (self);
	_g_object_unref0 (to_unit);
	_g_object_unref0 (from_unit);
	_g_object_unref0 (x);
}


static Number* math_converter_convert_equation (MathConverter* self, Number* x) {
	Number* result = NULL;
	GtkTreeIter from_iter = {0};
	GtkTreeIter to_iter = {0};
	GtkComboBox* _tmp0_ = NULL;
	GtkTreeIter _tmp1_ = {0};
	gboolean _tmp2_ = FALSE;
	GtkComboBox* _tmp3_ = NULL;
	GtkTreeIter _tmp4_ = {0};
	gboolean _tmp5_ = FALSE;
	UnitCategory* category = NULL;
	Unit* source_unit = NULL;
	Unit* target_unit = NULL;
	GtkComboBox* _tmp6_ = NULL;
	GtkTreeModel* _tmp7_ = NULL;
	GtkTreeModel* _tmp8_ = NULL;
	GtkTreeIter _tmp9_ = {0};
	GtkComboBox* _tmp10_ = NULL;
	GtkTreeModel* _tmp11_ = NULL;
	GtkTreeModel* _tmp12_ = NULL;
	GtkTreeIter _tmp13_ = {0};
	UnitCategory* _tmp14_ = NULL;
	Number* _tmp15_ = NULL;
	Unit* _tmp16_ = NULL;
	Unit* _tmp17_ = NULL;
	Number* _tmp18_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (x != NULL, NULL);
	_tmp0_ = self->priv->from_combo;
	_tmp2_ = gtk_combo_box_get_active_iter (_tmp0_, &_tmp1_);
	from_iter = _tmp1_;
	if (!_tmp2_) {
		result = NULL;
		return result;
	}
	_tmp3_ = self->priv->to_combo;
	_tmp5_ = gtk_combo_box_get_active_iter (_tmp3_, &_tmp4_);
	to_iter = _tmp4_;
	if (!_tmp5_) {
		result = NULL;
		return result;
	}
	_tmp6_ = self->priv->from_combo;
	_tmp7_ = gtk_combo_box_get_model (_tmp6_);
	_tmp8_ = _tmp7_;
	_tmp9_ = from_iter;
	gtk_tree_model_get (_tmp8_, &_tmp9_, 1, &category, 2, &source_unit, -1, -1);
	_tmp10_ = self->priv->to_combo;
	_tmp11_ = gtk_combo_box_get_model (_tmp10_);
	_tmp12_ = _tmp11_;
	_tmp13_ = to_iter;
	gtk_tree_model_get (_tmp12_, &_tmp13_, 2, &target_unit, -1, -1);
	_tmp14_ = category;
	_tmp15_ = x;
	_tmp16_ = source_unit;
	_tmp17_ = target_unit;
	_tmp18_ = unit_category_convert (_tmp14_, _tmp15_, _tmp16_, _tmp17_);
	result = _tmp18_;
	_g_object_unref0 (target_unit);
	_g_object_unref0 (source_unit);
	_g_object_unref0 (category);
	return result;
}


static void math_converter_class_init (MathConverterClass * klass) {
	math_converter_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (MathConverterPrivate));
	G_OBJECT_CLASS (klass)->finalize = math_converter_finalize;
	g_signal_new ("changed", TYPE_MATH_CONVERTER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}


static void math_converter_instance_init (MathConverter * self) {
	self->priv = MATH_CONVERTER_GET_PRIVATE (self);
}


static void math_converter_finalize (GObject* obj) {
	MathConverter * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_MATH_CONVERTER, MathConverter);
	_g_object_unref0 (self->priv->equation);
	_g_free0 (self->priv->category);
	_g_object_unref0 (self->priv->from_combo);
	_g_object_unref0 (self->priv->to_combo);
	_g_object_unref0 (self->priv->result_label);
	G_OBJECT_CLASS (math_converter_parent_class)->finalize (obj);
}


GType math_converter_get_type (void) {
	static volatile gsize math_converter_type_id__volatile = 0;
	if (g_once_init_enter (&math_converter_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MathConverterClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) math_converter_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MathConverter), 0, (GInstanceInitFunc) math_converter_instance_init, NULL };
		GType math_converter_type_id;
		math_converter_type_id = g_type_register_static (gtk_box_get_type (), "MathConverter", &g_define_type_info, 0);
		g_once_init_leave (&math_converter_type_id__volatile, math_converter_type_id);
	}
	return math_converter_type_id__volatile;
}



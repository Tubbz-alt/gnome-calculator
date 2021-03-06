/* libcalculator.vapi generated by valac 0.30.0.14-c43a, do not modify. */

[CCode (cheader_filename = "libcalculator.h")]
public enum ErrorCode {
	NONE,
	INVALID,
	OVERFLOW,
	UNKNOWN_VARIABLE,
	UNKNOWN_FUNCTION,
	UNKNOWN_CONVERSION,
	MP
}
[CCode (cheader_filename = "libcalculator.h")]
public enum LexerTokenType {
	UNKNOWN,
	PL_DECIMAL,
	PL_DIGIT,
	PL_HEX,
	PL_SUPER_DIGIT,
	PL_SUPER_MINUS,
	PL_SUB_DIGIT,
	PL_FRACTION,
	PL_DEGREE,
	PL_MINUTE,
	PL_SECOND,
	PL_LETTER,
	PL_EOS,
	PL_SKIP,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	MOD,
	L_FLOOR,
	R_FLOOR,
	L_CEILING,
	R_CEILING,
	ROOT,
	ROOT_3,
	ROOT_4,
	NOT,
	AND,
	OR,
	XOR,
	IN,
	NUMBER,
	SUP_NUMBER,
	NSUP_NUMBER,
	SUB_NUMBER,
	FUNCTION,
	VARIABLE,
	ASSIGN,
	L_R_BRACKET,
	R_R_BRACKET,
	L_S_BRACKET,
	R_S_BRACKET,
	L_C_BRACKET,
	R_C_BRACKET,
	ABS,
	POWER,
	FACTORIAL,
	PERCENTAGE,
	ARGUMENT_SEPARATOR
}
[CCode (cheader_filename = "libcalculator.h")]
public enum Associativity {
	LEFT,
	RIGHT
}
[CCode (cheader_filename = "libcalculator.h")]
public enum FinancialDialog {
	CTRM_DIALOG,
	DDB_DIALOG,
	FV_DIALOG,
	GPM_DIALOG,
	PMT_DIALOG,
	PV_DIALOG,
	RATE_DIALOG,
	SLN_DIALOG,
	SYD_DIALOG,
	TERM_DIALOG
}
[CCode (cheader_filename = "libcalculator.h")]
public enum NumberMode {
	NORMAL,
	SUPERSCRIPT,
	SUBSCRIPT
}
[CCode (cheader_filename = "libcalculator.h")]
public enum AngleUnit {
	RADIANS,
	DEGREES,
	GRADIANS
}
[CCode (cheader_filename = "libcalculator.h")]
public enum DisplayFormat {
	AUTOMATIC,
	FIXED,
	SCIENTIFIC,
	ENGINEERING
}
[CCode (cheader_filename = "libcalculator.h")]
public class CurrencyManager : GLib.Object {
	public CurrencyManager ();
	public GLib.List<Currency> get_currencies ();
	public Currency? get_currency (string name);
	public static CurrencyManager get_default ();
	public Number? get_value (string currency);
	public signal void updated ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class Currency : GLib.Object {
	public Currency (string name, string display_name, string symbol);
	public Number? get_value ();
	public void set_value (Number value);
	public string display_name { owned get; }
	public string name { owned get; }
	public string symbol { owned get; }
}
[CCode (cheader_filename = "libcalculator.h")]
public class Equation : GLib.Object {
	public AngleUnit angle_units;
	public int @base;
	public int wordlen;
	public Equation (string expression);
	public virtual Number? convert (Number x, string x_units, string z_units);
	public virtual bool function_is_defined (string name);
	public virtual Number? get_variable (string name);
	public new Number? parse (out uint representation_base = null, out ErrorCode error_code = null, out string? error_token = null, out uint? error_start = null, out uint? error_end = null);
	public virtual void set_variable (string name, Number x);
	public virtual bool variable_is_defined (string name);
}
[CCode (cheader_filename = "libcalculator.h")]
public class PreLexer : GLib.Object {
	public int index;
	public int mark_index;
	public string stream;
	public PreLexer (string input);
	public string get_marked_substring ();
	public LexerTokenType get_next_token ();
	public void roll_back ();
	public void set_marker ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class LexerToken : GLib.Object {
	public uint end_index;
	public uint start_index;
	public string text;
	public LexerTokenType type;
	public LexerToken ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class Lexer : GLib.Object {
	public GLib.List<LexerToken> tokens;
	public Lexer (string input, Parser parser, int number_base = 10);
	public LexerToken get_next_token ();
	public void roll_back ();
	public void scan ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class ParseNode : GLib.Object {
	public Associativity associativity;
	public ParseNode? left;
	public ParseNode? parent;
	public Parser parser;
	public uint precedence;
	public ParseNode? right;
	public LexerToken token;
	public string? value;
	public ParseNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity, string? value = null);
	public virtual Number? solve ();
}
[CCode (cheader_filename = "libcalculator.h")]
public abstract class RNode : ParseNode {
	public RNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number? solve ();
	public abstract Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public abstract class LRNode : ParseNode {
	public LRNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number? solve ();
	public abstract Number solve_lr (Number left, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class ConstantNode : ParseNode {
	public ConstantNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number? solve ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class AssignNode : RNode {
	public AssignNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class AssignFunctionNode : ParseNode {
	public AssignFunctionNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number? solve ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class NameNode : ParseNode {
	public NameNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity, string? text = null);
}
[CCode (cheader_filename = "libcalculator.h")]
public class VariableNode : ParseNode {
	public VariableNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number? solve ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class VariableWithPowerNode : ParseNode {
	public VariableWithPowerNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity, string text);
	public override Number? solve ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class FunctionNameNode : NameNode {
	public FunctionNameNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity, string name);
}
[CCode (cheader_filename = "libcalculator.h")]
public class FunctionArgumentsNode : NameNode {
	public FunctionArgumentsNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity, string arguments);
}
[CCode (cheader_filename = "libcalculator.h")]
public class FunctionDescriptionNode : NameNode {
	public FunctionDescriptionNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity, string description);
}
[CCode (cheader_filename = "libcalculator.h")]
public class FunctionNode : ParseNode {
	public FunctionNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity, string? text);
	public override Number? solve ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class UnaryMinusNode : RNode {
	public UnaryMinusNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class AbsoluteValueNode : RNode {
	public AbsoluteValueNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class FloorNode : RNode {
	public FloorNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class CeilingNode : RNode {
	public CeilingNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class FractionalComponentNode : RNode {
	public FractionalComponentNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class RoundNode : RNode {
	public RoundNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class PercentNode : RNode {
	public PercentNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class FactorialNode : RNode {
	public FactorialNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class AddNode : LRNode {
	public bool do_percentage;
	public AddNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class SubtractNode : LRNode {
	public bool do_percentage;
	public SubtractNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class MultiplyNode : LRNode {
	public MultiplyNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class DivideNode : LRNode {
	public DivideNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class ModulusDivideNode : LRNode {
	public ModulusDivideNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number? solve ();
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class RootNode : RNode {
	public RootNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity, int n);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class XPowYNode : LRNode {
	public XPowYNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class XPowYIntegerNode : ParseNode {
	public XPowYIntegerNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number? solve ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class NotNode : RNode {
	public NotNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_r (Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class AndNode : LRNode {
	public AndNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class OrNode : LRNode {
	public OrNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class XorNode : LRNode {
	public XorNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class ConvertNode : LRNode {
	public ConvertNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number solve_lr (Number l, Number r);
}
[CCode (cheader_filename = "libcalculator.h")]
public class ConvertBaseNode : ParseNode {
	public ConvertBaseNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity, string? value);
	public override Number? solve ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class ConvertNumberNode : ParseNode {
	public ConvertNumberNode (Parser parser, LexerToken? token, uint precedence, Associativity associativity);
	public override Number? solve ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class Parser {
	public AngleUnit angle_units;
	public int number_base;
	public int wordlen;
	public Parser (string input, int number_base, int wordlen, AngleUnit angle_units);
	public virtual Number? convert (Number x, string x_units, string z_units);
	public bool create_parse_tree (out uint representation_base, out ErrorCode error_code, out string? error_token, out uint error_start, out uint error_end);
	public virtual bool function_is_defined (string name);
	public virtual Number? get_variable (string name);
	public Number? parse (out uint representation_base, out ErrorCode error_code, out string? error_token, out uint error_start, out uint error_end);
	public void set_error (ErrorCode errorno, string? token = null, uint token_start = 0, uint token_end = 0);
	public void set_representation_base (uint new_base);
	public virtual void set_variable (string name, Number x);
	public virtual bool variable_is_defined (string name);
}
[CCode (cheader_filename = "libcalculator.h")]
public class FunctionManager : GLib.Object {
	public FunctionManager ();
	public bool add_function_with_properties (string name, string arguments, string description, Parser? root_parser = null);
	public void @delete (string name);
	public Number? evaluate_function (string name, Number[] arguments, Parser parser);
	public MathFunction[] functions_eligible_for_autocompletion_for_text (string display_text);
	public new MathFunction? @get (string name);
	public static FunctionManager get_default_function_manager ();
	public string[] get_names ();
	public bool is_function_defined (string name);
}
[CCode (cheader_filename = "libcalculator.h")]
public class MathEquation : Gtk.SourceBuffer {
	public MathEquation ();
	public new void backspace ();
	public void clear ();
	public void copy ();
	public void delete_next ();
	protected override void delete_range (Gtk.TextIter start, Gtk.TextIter end);
	public void display_selected (string selected);
	public void factorize ();
	public unichar get_digit_text (uint digit);
	public new void insert (string text);
	public void insert_digit (uint digit);
	public void insert_exponent ();
	public void insert_number (Number x);
	public void insert_numeric_point ();
	public void insert_selected (string answer);
	public new void insert_square ();
	public void insert_subtract ();
	protected override void insert_text (ref Gtk.TextIter location, string text, int len);
	public void paste ();
	public void recall (string name);
	public override void redo ();
	public new void @set (string text);
	public void set_number (Number x, uint representation_base = 0);
	public void shift (int count);
	public void solve ();
	public void store (string name);
	public void toggle_bit (uint bit);
	public override void undo ();
	public int accuracy { get; set; }
	public AngleUnit angle_units { get; set; }
	public Number answer { get; }
	public string display { owned get; }
	public string equation { owned get; }
	public uint error_token_end { get; }
	public uint error_token_start { get; }
	public bool in_solve { get; }
	public bool is_empty { get; }
	public bool is_result { get; }
	public Number? number { owned get; }
	public int number_base { get; set; }
	public DisplayFormat number_format { get; set; }
	public NumberMode number_mode { get; set; }
	public Serializer serializer { get; }
	public bool show_thousands_separators { get; set; }
	public bool show_trailing_zeroes { get; set; }
	public string source_currency { owned get; set; }
	public string source_units { owned get; set; }
	public string status { owned get; set; }
	public string target_currency { owned get; set; }
	public string target_units { owned get; set; }
	public MathVariables variables { get; }
	public int word_size { get; set; }
	public signal void history_signal (string answer, Number number, int number_base, uint representation_base);
}
[CCode (cheader_filename = "libcalculator.h")]
public class MathFunction : GLib.Object {
	public MathFunction (string function_name, string[] arguments, string? expression, string? description);
	public virtual Number? evaluate (Number[] args, Parser? root_parser = null);
	public virtual bool is_custom_function ();
	public bool validate (Parser? root_parser = null);
	public string[] arguments { get; }
	public string? description { get; }
	public string? expression { get; }
	public string name { get; }
}
[CCode (cheader_filename = "libcalculator.h")]
public class ExpressionParser : Parser {
	public ExpressionParser (string expression, Parser? root_parser = null);
	protected override bool function_is_defined (string name);
	protected override Number? get_variable (string name);
	protected override bool variable_is_defined (string name);
}
[CCode (cheader_filename = "libcalculator.h")]
public class BuiltInMathFunction : MathFunction {
	public BuiltInMathFunction (string function_name, string? description);
	public override Number? evaluate (Number[] args, Parser? root_parser = null);
	public override bool is_custom_function ();
}
[CCode (cheader_filename = "libcalculator.h")]
public class MathVariables : GLib.Object {
	public MathVariables ();
	public void @delete (string name);
	public new Number? @get (string name);
	public string[] get_names ();
	public new void @set (string name, Number value);
	public string[] variables_eligible_for_autocompletion (string text);
}
[CCode (cheader_filename = "libcalculator.h")]
public class Number : GLib.Object {
	public Number ();
	public Number abs ();
	public Number acos (AngleUnit unit = AngleUnit.RADIANS);
	public Number acosh ();
	public Number add (Number y);
	public Number add_real (Number y);
	public Number and (Number y);
	public Number arg (AngleUnit unit = AngleUnit.RADIANS);
	public Number asin (AngleUnit unit = AngleUnit.RADIANS);
	public Number asinh ();
	public Number atan (AngleUnit unit = AngleUnit.RADIANS);
	public Number atanh ();
	public Number ceiling ();
	public static void check_flags ();
	public int compare (Number y);
	public Number.complex (Number x, Number y);
	public Number conjugate ();
	public Number cos (AngleUnit unit = AngleUnit.RADIANS);
	public Number cosh ();
	public Number divide (Number y);
	public Number divide_integer (int64 y);
	public Number.double (global::double value);
	public Number epowy ();
	public bool equals (Number y);
	public Number.eulers ();
	public Number factorial ();
	public GLib.List<Number?> factorize ();
	public GLib.List<Number?> factorize_uint64 (uint64 n);
	public Number floor ();
	public Number.fraction (int64 numerator, int64 denominator);
	public Number fractional_component ();
	public Number fractional_part ();
	public Number.i ();
	public Number imaginary_component ();
	public Number.integer (int64 value);
	public Number integer_component ();
	public Number invert_sign ();
	public bool is_complex ();
	public bool is_integer ();
	public bool is_natural ();
	public bool is_negative ();
	public bool is_positive_integer ();
	public bool is_zero ();
	public Number ln ();
	public Number logarithm (int64 n);
	public Number mask (Number x, int wordlen);
	public Number modular_exponentiation (Number exp, Number mod);
	public Number modulus_divide (Number y);
	public Number.mpfloat (MPFR.MPFloat value);
	public Number multiply (Number y);
	public Number multiply_integer (int64 y);
	public Number multiply_real (Number y);
	public Number not (int wordlen);
	public Number ones_complement (int wordlen);
	public Number or (Number y);
	public Number.pi ();
	public Number.polar (Number r, Number theta, AngleUnit unit = AngleUnit.RADIANS);
	public Number.random ();
	public Number real_component ();
	public Number reciprocal ();
	public Number root (int64 n);
	public Number round ();
	public Number sgn ();
	public Number shift (int count);
	public Number sin (AngleUnit unit = AngleUnit.RADIANS);
	public Number sinh ();
	public Number sqrt ();
	public Number subtract (Number y);
	public Number tan (AngleUnit unit = AngleUnit.RADIANS);
	public Number tanh ();
	public global::double to_double ();
	public float to_float ();
	public int64 to_integer ();
	public uint64 to_unsigned_integer ();
	public Number twos_complement (int wordlen);
	public Number.unsigned_integer (uint64 x);
	public Number xor (Number y);
	public Number xpowy (Number y);
	public Number xpowy_integer (int64 n);
	public static string? error { get; set; }
	public static ulong precision { get; set; }
}
[CCode (cheader_filename = "libcalculator.h")]
public class Serializer : GLib.Object {
	public Serializer (DisplayFormat format, int number_base, int trailing_digits);
	public Number? from_string (string str);
	public int get_base ();
	public int get_leading_digits ();
	public DisplayFormat get_number_format ();
	public unichar get_radix ();
	public uint get_representation_base ();
	public bool get_show_thousands_separators ();
	public bool get_show_trailing_zeroes ();
	public unichar get_thousands_separator ();
	public int get_thousands_separator_count ();
	public int get_trailing_digits ();
	public void set_base (int number_base);
	public void set_leading_digits (int leading_digits);
	public void set_number_format (DisplayFormat format);
	public void set_radix (unichar radix);
	public void set_representation_base (uint representation_base);
	public void set_show_thousands_separators (bool visible);
	public void set_show_trailing_zeroes (bool visible);
	public void set_thousands_separator (unichar separator);
	public void set_thousands_separator_count (int count);
	public void set_trailing_digits (int trailing_digits);
	public string to_string (Number x);
	public string? error { get; set; }
}
[CCode (cheader_filename = "libcalculator.h")]
public class UnitManager : GLib.Object {
	public UnitManager ();
	public UnitCategory add_category (string name, string display_name);
	public Number? convert_by_symbol (Number x, string x_symbol, string z_symbol);
	public GLib.List<UnitCategory> get_categories ();
	public UnitCategory? get_category (string category);
	public static UnitManager get_default ();
	public Unit? get_unit_by_name (string name);
	public Unit? get_unit_by_symbol (string symbol);
}
[CCode (cheader_filename = "libcalculator.h")]
public class UnitCategory : GLib.Object {
	public UnitCategory (string name, string display_name);
	public void add_unit (Unit unit);
	public Number? convert (Number x, Unit x_units, Unit z_units);
	public Unit? get_unit_by_name (string name, bool case_sensitive = true);
	public Unit? get_unit_by_symbol (string symbol, bool case_sensitive = true);
	public unowned GLib.List<Unit> get_units ();
	public string display_name { owned get; }
	public string name { owned get; }
}
[CCode (cheader_filename = "libcalculator.h")]
public class Unit : GLib.Object {
	public Unit (string name, string display_name, string format, string? from_function, string? to_function, string symbols);
	public Number? convert_from (Number x);
	public Number? convert_to (Number x);
	public string format (Number x);
	public unowned GLib.List<string> get_symbols ();
	public bool matches_symbol (string symbol, bool case_sensitive = true);
	public string display_name { owned get; }
	public string name { owned get; }
}
[CCode (cheader_filename = "libcalculator.h")]
public static int sub_atoi (string data);
[CCode (cheader_filename = "libcalculator.h")]
public static int super_atoi (string data);
[CCode (cheader_filename = "libcalculator.h")]
public static string mp_error_code_to_string (ErrorCode error_code);
[CCode (cheader_filename = "libcalculator.h")]
public static void do_finc_expression (MathEquation equation, FinancialDialog function, Number arg1, Number arg2, Number arg3, Number arg4);
[CCode (cheader_filename = "libcalculator.h")]
public static Number? mp_set_from_string (string str, int default_base = 10);
[CCode (cheader_filename = "libcalculator.h")]
public static bool mp_is_overflow (Number x, int wordlen);

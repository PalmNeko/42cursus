# s_conversion_specification

## type

```c
typedef struct s_conversion_specification
{
	t_conversion_specifier conversion_specifier; // 変換指定子
	int flag_sharp; // ＃フラグが指定されているかどうか。
	int	flag_minus; // -フラグが指定されているかどうか。
	int	flag_plus; // + フラグが指定されているかどうか。
	int	flag_zero; // 0 フラグが指定されているかどうか。
	int	flag_space; // ` ` フラグが指定されているかどうか。
	int is_specified_min_field_width; // 最小フィールドが指定されているかどうか。
	int minimum_field_width; // 最小フィールドの値
	int is_specified_precision; // 精度が指定されているかどうか。
	int precision; // 精度の値
} t_conv_specification;
```
## description

変換仕様一つの構造体

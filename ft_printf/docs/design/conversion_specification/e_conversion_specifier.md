# e_conversion_specifier

## type

```c
typedef enum e_conversion_specifier
{
	CS_NONE, // 何もない。
	CS_LOWER_S, // %s
	CS_LOWER_P, // %p
	CS_LOWER_C, // %c
	CS_LOWER_D, // %d
	CS_LOWER_U, // %u
	CS_LOWER_I, // %i
	CS_LOWER_X, // %x
	CS_UPPER_X, // %X
	CS_PERCENT, // %%
} t_conv_specifier;
```

## description

変換指定子の種類

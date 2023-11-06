# print_va_list_fd

## prototype

```c
int	print_va_list_fd(int fd, t_conv_specification *cs, va_list args)
```

## return value

成功時: 出力した文字数
失敗時: 負の値

## description

`va_list`と`変換仕様構造体`を元に文字列をfdに出力する。

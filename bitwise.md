# Bitwise Operators
Misol uchun bizda 5 soni bor , uning 2lik ko'rinishi `101`. Aslida C dasturlash tilida `int` 4-bayt (32-bit) xotirani egallaydi va shunda 5 sonimiz :

![shunaqa Korinishda bo'ladi](/home/ronin/Pictures/Screenshots/h.png)


hop , biz hozir Decimal degan yangi turdagi ma'lumot turini yozayapmiz, unda biz 4 bayt xotirani emas 16 bayt xotirani egallaydigan `s21_decimal` yaratamiz, undan tashqari ikki decimal ni qo'shish ayirish kabi turli matematik amallarni ham bajarishimiz kerak. bunga bizga to'g'ridan to'g'ri indvidual bitlar bilan ishlashimiz kerak bo'ladi, chunki biz amalda bitta sonni 4ta `int` arrayda saqlayapmiz


C dasturlash tilida quyidagi bitwise operatorlar bor.
`&` - AND operatori , 
`|` - OR operatori
`^` - XOR operatori
`<<` - chapga surish -> `0001 << 1` -> `0010`
`>>` - o'ngga surish -> `0010 >> 1` -> `0001`
`~` - NOT operatori

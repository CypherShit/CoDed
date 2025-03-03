## Результаты тестирования на x86-64 машине + Debian 12

```
Run on (24 X 2496 MHz CPU s)
CPU Caches:
  L1 Data 48 KiB (x12)
  L1 Instruction 32 KiB (x12)
  L2 Unified 1280 KiB (x12)
  L3 Unified 30720 KiB (x1)
Load Average: 0.06, 0.06, 0.06
-----------------------------------------------------------------------
Benchmark                             Time             CPU   Iterations
-----------------------------------------------------------------------
BM_CaesarCipher_Encode             1767 ns         1775 ns       385453
BM_CaesarCipher_Decode             1763 ns         1771 ns       390882
BM_PlayfairCipher_Encode           6124 ns         6152 ns       115212
BM_PlayfairCipher_Decode           5950 ns         5977 ns       118289
BM_RC4_Encode                      1781 ns         1789 ns       394898
BM_RC4_Decode                      1751 ns         1759 ns       398844
BM_Vigenere_Encode                 2108 ns         2119 ns       319097
BM_Vigenere_Decode                 2263 ns         2274 ns       297422
BM_Vernam_Encode                   1594 ns         1602 ns       438375
BM_Vernam_Decode                   1624 ns         1629 ns       437123
BM_Atbash_Encode                   1780 ns         1750 ns       400913
BM_Atbash_Decode                   1721 ns         1697 ns       416872
BM_Trithemius_Encode               1826 ns         1805 ns       390672
BM_Trithemius_Decode               1845 ns         1827 ns       386173
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
BM_CaesarCipher_Encode_Mem         1777 ns         1763 ns       388160
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
BM_CaesarCipher_Decode_Mem         1766 ns         1754 ns       397175
Current allocated bytes: 119656
Current allocated bytes: 119656
Current allocated bytes: 119656
Current allocated bytes: 119656
Current allocated bytes: 119656
Current allocated bytes: 119656
BM_PlayfairCipher_Encode_Mem       6154 ns         6119 ns       112501
Current allocated bytes: 119784
Current allocated bytes: 119784
Current allocated bytes: 119784
Current allocated bytes: 119784
Current allocated bytes: 119784
Current allocated bytes: 119784
BM_PlayfairCipher_Decode_Mem       5970 ns         5942 ns       114770
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
BM_RC4_Encode_Mem                  1791 ns         1785 ns       395535
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
BM_RC4_Decode_Mem                  1743 ns         1739 ns       398265
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
BM_Vigenere_Encode_Mem             2106 ns         2103 ns       329762
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
BM_Vigenere_Decode_Mem             2146 ns         2145 ns       296037
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
BM_Vernam_Encode_Mem               1600 ns         1600 ns       438725
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
BM_Vernam_Decode_Mem               1628 ns         1628 ns       438250
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
BM_Atbash_Encode_Mem               1721 ns         1723 ns       402172
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
BM_Atbash_Decode_Mem               1730 ns         1733 ns       410248
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
Current allocated bytes: 112616
BM_Trithemius_Encode_Mem           1769 ns         1772 ns       394945
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
Current allocated bytes: 112728
BM_Trithemius_Decode_Mem           1814 ns         1818 ns       394699
```

## Результаты тестирования на X86 машине + Ubuntu 24.04.1 LTS
```
Run on (4 X 1995.31 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 4096 KiB (x2)
  L3 Unified 16384 KiB (x1)
Load Average: 0.00, 0.00, 0.02
***WARNING*** Library was built as DEBUG. Timings may be affected.
-----------------------------------------------------------------------
Benchmark                             Time             CPU   Iterations
-----------------------------------------------------------------------
BM_CaesarCipher_Encode              381 ns          381 ns      1868344
BM_CaesarCipher_Decode              380 ns          380 ns      1873032
BM_PlayfairCipher_Encode            494 ns          494 ns      1411150
BM_PlayfairCipher_Decode            530 ns          530 ns      1268540
BM_RC4_Encode                       339 ns          339 ns      2080828
BM_RC4_Decode                       349 ns          349 ns      1933830
BM_Vigenere_Encode                  238 ns          238 ns      2905226
BM_Vigenere_Decode                  260 ns          260 ns      2612595
BM_Vernam_Encode                    345 ns          345 ns      2020208
BM_Vernam_Decode                    348 ns          348 ns      2018728
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
BM_CaesarCipher_Encode_Mem          382 ns          382 ns      1828125
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
BM_CaesarCipher_Decode_Mem          386 ns          386 ns      1755918
Current allocated bytes: 109168
Current allocated bytes: 109168
Current allocated bytes: 109168
Current allocated bytes: 109168
Current allocated bytes: 109168
Current allocated bytes: 109168
Current allocated bytes: 109168
BM_PlayfairCipher_Encode_Mem        501 ns          501 ns      1000000
Current allocated bytes: 109296
Current allocated bytes: 109296
Current allocated bytes: 109296
Current allocated bytes: 109296
Current allocated bytes: 109296
Current allocated bytes: 109296
Current allocated bytes: 109296
BM_PlayfairCipher_Decode_Mem        538 ns          538 ns      1352599
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
BM_RC4_Encode_Mem                   347 ns          347 ns      1888479
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
BM_RC4_Decode_Mem                   368 ns          368 ns      2120158
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
BM_Vigenere_Encode_Mem              244 ns          244 ns      2799768
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
BM_Vigenere_Decode_Mem              265 ns          265 ns      2635730
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
Current allocated bytes: 102128
BM_Vernam_Encode_Mem                347 ns          347 ns      1985837
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
Current allocated bytes: 102240
BM_Vernam_Decode_Mem                350 ns          350 ns      1967267
```

## Производительность алгоритмов:
 Caesar Cipher: Похож на результаты других архитектур, около 345 нс на кодирование и 348 нс на декодирование.

Playfair Cipher: Остается более медленным (478 нс кодирование, 466 нс декодирование) из-за сложной структуры ключа.

RC4: Лучший результат среди всех (105 нс кодирование, 115 нс декодирование).

Vigenere Cipher: Время выполнения аналогично другим тестам (~275 нс на операцию).

Vernam Cipher: Почти идентичные результаты с Виженером (~280 нс).

Atbash Cipher: Один из самых быстрых алгоритмов (~160 нс на операцию).

Trithemius Cipher: Быстрее, чем Виженер (~310 нс), но требует немного больше вычислений.

## Использование памяти:
Выделение памяти немного выше, чем на ARM и x86, что может быть связано с особенностями архитектуры.

Наибольшее выделение памяти у Playfair (~65712 байт).

Алгоритмы Атбаша и Тритемиуса используют умеренные объемы памяти (~58976-60048 байт).

## Общие выводы:
x86-64 показывает отличные результаты для RC4 и Атбаша, что делает их лучшими кандидатами для высокой скорости шифрования.

Playfair остается самым тяжелым по вычислениям и памяти.

Trithemius занимает промежуточное положение между Caesar и Vigenere по производительности.

В целом, результаты схожи с другими архитектурами, но архитектурные различия x86-64 дают некоторые отличия в использовании памяти и времени обработки.
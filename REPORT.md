Результаты тестирования на ARM машине:

```
Run on (10 X 24 MHz CPU s)
CPU Caches:
  L1 Data 64 KiB
  L1 Instruction 128 KiB
  L2 Unified 4096 KiB (x10)
Load Average: 1.64, 2.44, 2.60
-----------------------------------------------------------------------
Benchmark                             Time             CPU   Iterations
-----------------------------------------------------------------------
BM_CaesarCipher_Encode             1291 ns         1289 ns       548839
BM_CaesarCipher_Decode             1294 ns         1289 ns       543854
BM_PlayfairCipher_Encode           7176 ns         7155 ns        98224
BM_PlayfairCipher_Decode           6341 ns         6326 ns       112587
BM_RC4_Encode                      1550 ns         1547 ns       452223
BM_RC4_Decode                      1554 ns         1552 ns       446631
BM_Vigenere_Encode                 2597 ns         2592 ns       237661
BM_Vigenere_Decode                 2800 ns         2796 ns       254279
Current allocated bytes: 47376
Current allocated bytes: 47376
Current allocated bytes: 47376
Current allocated bytes: 47376
Current allocated bytes: 47376
Current allocated bytes: 47376
Current allocated bytes: 47376
BM_CaesarCipher_Encode_Mem         1245 ns         1238 ns       567951
Current allocated bytes: 47488
Current allocated bytes: 47488
Current allocated bytes: 47488
Current allocated bytes: 47488
Current allocated bytes: 47488
Current allocated bytes: 47488
Current allocated bytes: 47488
BM_CaesarCipher_Decode_Mem         1239 ns         1234 ns       567749
Current allocated bytes: 53904
Current allocated bytes: 53904
Current allocated bytes: 53904
Current allocated bytes: 53904
Current allocated bytes: 53904
Current allocated bytes: 53904
BM_PlayfairCipher_Encode_Mem       7276 ns         7251 ns        96765
Current allocated bytes: 54096
Current allocated bytes: 54096
Current allocated bytes: 54096
Current allocated bytes: 54096
Current allocated bytes: 54096
Current allocated bytes: 54096
BM_PlayfairCipher_Decode_Mem       6260 ns         6237 ns       111653
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
BM_RC4_Encode_Mem                  1554 ns         1548 ns       450862
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
BM_RC4_Decode_Mem                  1559 ns         1554 ns       443293
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
Current allocated bytes: 47344
BM_Vigenere_Encode_Mem             2855 ns         2846 ns       247094
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
Current allocated bytes: 47456
BM_Vigenere_Decode_Mem             2876 ns         2868 ns       248877
```

### Общие выводы:

1. Скорость выполнения:
   - Caesar Cipher: Обладает самой высокой скоростью выполнения среди рассмотренных алгоритмов, как для кодирования, так и для декодирования, с временными затратами около 1,289 нс.
   - RC4: Находится рядом с Caesar Cipher по времени выполнения — около 1,550 нс для обоих процессов.
   - Vigenere Cipher: Заметно медленнее, с временем выполнения около 2,800 нс для декодирования.
   - Playfair Cipher: Самый медленный из всех тестов, с приблизительным временем выполнения 7,200 нс для кодирования.

2. Потребление памяти:
   - Все алгоритмы показывают незначительное текущее потребление памяти, по крайней мере, в ходе этих бенчмарков. Величина выделенной памяти не сильно отличается между различными запусками одного и того же теста.
   - Наибольшее текущее выделение наблюдается в BM_PlayfairCipher_Encode_Mem и BM_PlayfairCipher_Decode_Mem, достигая 54,096 байт. В других тестах наблюдаются меньшие значения, колеблющиеся в районе 47,344-54,904 байт.
   
3. Устойчивость и стабильность:
   - Количество итераций значительно варьируется в зависимости от алгоритма, это связано с особенностями алгоритмов, а именно их солей. Однако производительность является достаточно стабильной в пределах каждого конкретного бенчмарка, на разных (сгенерированных) входных данных.

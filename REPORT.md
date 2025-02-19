## Результаты тестирования на ARM машине + macOS 14.5 (23F79)

```
Run on (10 X 24 MHz CPU s)
CPU Caches:
  L1 Data 64 KiB
  L1 Instruction 128 KiB
  L2 Unified 4096 KiB (x10)
Load Average: 4.19, 3.92, 3.18
-----------------------------------------------------------------------
Benchmark                             Time             CPU   Iterations
-----------------------------------------------------------------------
BM_CaesarCipher_Encode              314 ns          312 ns      2243051
BM_CaesarCipher_Decode              316 ns          314 ns      2234551
BM_PlayfairCipher_Encode            441 ns          438 ns      1561611
BM_PlayfairCipher_Decode            433 ns          431 ns      1629476
BM_RC4_Encode                       110 ns          109 ns      6559897
BM_RC4_Decode                       119 ns          118 ns      5933209
BM_Vigenere_Encode                  261 ns          259 ns      2694277
BM_Vigenere_Decode                  262 ns          261 ns      2675493
BM_Vernam_Encode                    263 ns          262 ns      2686748
BM_Vernam_Decode                    263 ns          261 ns      2672460
Current allocated bytes: 52784
Current allocated bytes: 52784
Current allocated bytes: 52784
Current allocated bytes: 52784
Current allocated bytes: 52784
Current allocated bytes: 52784
Current allocated bytes: 52784
Current allocated bytes: 52784
BM_CaesarCipher_Encode_Mem          308 ns          305 ns      2284685
Current allocated bytes: 52896
Current allocated bytes: 52896
Current allocated bytes: 52896
Current allocated bytes: 52896
Current allocated bytes: 52896
Current allocated bytes: 52896
Current allocated bytes: 52896
Current allocated bytes: 52896
BM_CaesarCipher_Decode_Mem          327 ns          312 ns      2292008
Current allocated bytes: 59312
Current allocated bytes: 59312
Current allocated bytes: 59312
Current allocated bytes: 59312
Current allocated bytes: 59312
Current allocated bytes: 59312
Current allocated bytes: 59312
Current allocated bytes: 59312
BM_PlayfairCipher_Encode_Mem        492 ns          465 ns      1486935
Current allocated bytes: 59504
Current allocated bytes: 59504
Current allocated bytes: 59504
Current allocated bytes: 59504
Current allocated bytes: 59504
Current allocated bytes: 59504
Current allocated bytes: 59504
Current allocated bytes: 59504
BM_PlayfairCipher_Decode_Mem        446 ns          431 ns      1562165
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
BM_RC4_Encode_Mem                   124 ns          116 ns      6339833
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
BM_RC4_Decode_Mem                   117 ns          116 ns      5933963
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
BM_Vigenere_Encode_Mem              256 ns          255 ns      2712348
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
BM_Vigenere_Decode_Mem              260 ns          258 ns      2725793
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
Current allocated bytes: 52752
BM_Vernam_Encode_Mem                262 ns          260 ns      2684976
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
Current allocated bytes: 52864
BM_Vernam_Decode_Mem                263 ns          261 ns      2681592
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
   - Caesar Cipher: Алгоритм является относительно медленным для своей категории, хоть и он довольно прост. Вариации времени для кодирования и декодирования минимальны (314-316 нс).
   - Playfair Cipher: Данный алгоритм сложнее, чем шифр Цезаря, и как результат более медленный, время исполнения составляет около 441 нс для кодирования и 433 нс для декодирования - дело в том, что у него самая сложная соль из представленных.
   - RC4: Преимущество данного алгоритма заключается в его высокой скорости: он быстрее всех других алгоритмов в тесте, с временем около 110 нс для кодирования и 119 нс для декодирования.
   - Vigenere Cipher: Он показывает приемлемую производительность, затрачивая около 261 нс на операцию.
   - Vernam Cipher: Аналогично шифру Виженера, с небольшими отличиями во времени.

## Использование памяти:
   - Различия в использовании памяти для каждого алгоритма незначительны, но играют роль при большом числе операций. Изначально выделено 52784 байт для всех тестов, кроме тестов *Encode_Mem, где мемоизация может занять немного больше: превышение памяти было замечено у Playfair (до 59504 байт) - опять же из-за особенностей соли.
   - Наибольшее выделение памяти для декодирования шифра Цезаря (59312 байт), это странно.

## Общие выводы:
   - RC4 проявляет лучшие результаты с точки зрения производительности (наименьшее время исполнения), что делает его подходящим для задач, требующих высокой скорости.
   - Простота шифра Виженера и его аналогичное использование памяти делает его хорошим выбором для систем с ограниченными ресурсами.
   - Алгоритмы, такие как Playfair, показывают зависимость между сложностью алгоритма и увеличением как времени обработки сообщения, так и использования памяти.

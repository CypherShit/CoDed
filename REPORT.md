## Результаты тестирования на ARM машине:

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

## Производительность алгоритмов:
   - Caesar Cipher: Алгоритм является относительно медленным для своей категории, хоть и он довольно прост. Вариации времени для кодирования и декодирования минимальны (314-316 нс).
   - Playfair Cipher: Данный алгоритм сложнее, чем шифр Цезаря, и как результат более медленный, время исполнения составляет около 441 нс для кодирования и 433 нс для декодирования.
   - RC4: Преимущество данного алгоритма заключается в его высокой скорости: он быстрее всех других алгоритмов в тесте, с временем около 110 нс для кодирования и 119 нс для декодирования.
   - Vigenere Cipher: Он показывает приемлемую производительность, затрачивая около 261 нс на операцию.
   - Vernam Cipher: Аналогично шифру Виженера, с небольшими отличиями во времени.

## Использование памяти:
   - Различия в использовании памяти для каждого алгоритма незначительны, но играют роль при большом числе операций. Изначально выделено 52784 байт для всех тестов, кроме тестов *Encode_Mem, где мемоизация может занять немного больше: превышение памяти было замечено у Playfair (до 59504 байт).
   - Наибольшее выделение памяти для декодирования шифра Цезаря (59312 байт) указывает на возможные особенности реализации, требующие более тщательного анализа.

## Системная нагрузка:
   - Данные тесты запущены на процессоре с частотой 24 МГц, что намного ниже современных стандартов, предполагая специфичные условия тестовой среды, такие как симуляция или использование старой системы.
   - Среднее значение нагрузки системы (Load Average) указывает на умеренную активность, что говорит нам о том, что система справляется с нагрузкой в условиях этих тестов.

## Общие выводы:
   - RC4 проявляет лучшие результаты с точки зрения производительности (наименьшее время исполнения), что делает его подходящим для задач, требующих высокой скорости.
   - Простота шифра Виженера и его аналогичное использование памяти делает его хорошим выбором для систем с ограниченными ресурсами.
   - Алгоритмы, такие как Playfair, показывают зависимость между сложностью алгоритма и увеличением как времени обработки сообщения, так и использования памяти.
   - Для дальнейших улучшений стоит рассмотреть способы оптимизации использования памяти, особенно для алгоритмов, которые показывают неоптимальное выделение памяти при декодировании.

# CoDed
## Авторы
* Афонькин Павел @[Redvin-dt](https://github.com/Redvin-dt)
* Нейков Даниил @[sssi111](https://github.com/sssi111)
* Панов Андрей @[cowboymalboro1884](https://github.com/cowboymalboro1884)

## Dependencies
* C++ 20 only
## Предметная область
Шифрование данных 🛡️
## Алгоритмы: 
1. **Алгоритм RSA**: ассиметричный криптографический алгоритм, широко используемый для безопасной передачи данных. RSA основан на математической сложности факторизации больших чисел. Он использует пару ключей: открытый ключ для шифрования и закрытый ключ для дешифрования. Это позволяет обмениваться зашифрованными сообщениями, не передавая секретный ключ.
2. **Шифр Виженера**: расширение шифра Цезаря, использующее ключевое слово для определения сдвига каждой буквы. Каждый символ сообщения смещается на количество позиций, соответствующее букве ключа. 
3. **Шифр Плейфер**: использует сетку 5x5 в оригинале, заполненную ключом и алфавитом, для шифрования пар букв (для английского алфавита). Это был первый шифр, использующий пары букв для повышения безопасности. Мы будем использовать 16x16 для ASCII, и просто динамическую сетку для алфавита произвольного размера.
4. **Шифр Вернама**: теоретически непробиваемый шифр, использующий ключ, равный по длине сообщению. Каждый символ сообщения комбинируется с соответствующим символом из ключа.
5. **Шифр перестановок (permutation)**: перестановка символов сообщения по определенному алгоритму или ключевому шаблону. Обратим, если шаблон известен.
6. **Шифр Квадрата Полибия**: использует сетку 5x5 для английского алфавита (в оригинале) для замены каждой буквы на пару координат. Эффективен для шифрования букв. Мы будем использовать 16x16 для ASCII, и просто динамическую сетку для алфавита произвольного размера.
7. **Шифр ADFGVX**: использует словарь символов и решетку для шифрования текста. Этот метод комбинирует шифры замены и перестановки.
8. **Алгоритм RC4**: потоковый шифр, разработанный для быстрого софтверного шифрования. Он генерирует псевдослучайный поток бит, который затем комбинируется с текстом сообщения.
9. **Шифр Цезаря**: cамый простой и известный метод шифрования, который сдвигает каждую букву в строке на фиксированное число позиций в алфавите.
10. **Алгоритм AES**: симметричный блочный шифр, который является стандартом шифрования во многих приложениях. AES работает с данными, разделенными на блоки, и применяет серию преобразований (подстановка, перестановка, перемешивание) с использованием секретного ключа. Он отличается высокой скоростью и безопасностью, что делает его предпочтительным выбором для шифрования данных.

(последние два - как пример самого простого и самого сложного метода - реализованы не будут)

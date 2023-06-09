С клавиатуры вводятся числа. Когда пользователь вводит «-1». 
Необходимо выводить на экран пятое по возрастанию число среди введённых. 
Когда пользователь вводит «-2», программа завершает работу.

Пример:

```text
ввод: 7 5 3 1 2 4 6 -1
вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
ввод: 1 1 1 -1
вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
ввод -2
завершение программы
```

### Примечание:

При введении пользователем числа, оно помещается в отсортированный вектор. 
Вектор, при этом, формируется последовательно - от меньшего числа к большему. 

Поскольку вектор формируется не сразу, а последовательно, использовать стандартный подход с `пузырьковой сортировкой` 
или `сортировкой выборкой` - не имело смысла:

```C++
int arr[] = {3, 5, 8, 1, 3, 9, 0, 2, 2, -3};
int arrSize = sizeof(arr) / sizeof(arr[0]);

for (int i = 0; i < arrSize; ++i) {
    for (int j = i + 1; j < arrSize; ++j) {
        if (arr[j] < arr[i]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
```
При последовательном добавлении новых элементов выгоднее воспользоваться 
стандартными инструментами типа `std::lower_bound`.

Ещё момент: можно было бы оптимизировать процесс, добавив резервирование в вектор, 
используя `vector.resize()` и `vector.reserve()`.

### Полезная информация:

По `std::lower_bound` и `std::upper_bound` - в [небольшой справке](https://silvertests.ru/GuideView.aspx?id=32103)
# Практика 381908-1-2
## Задания
Для сдачи задания нужно создать Pull Request с решением в upstream-репозиторий.

Задание будет считаться сданным, если ваш Pull Request будет одобрен.

Время сдачи -- время слияния.

Все задачи предполагают использование классов и небольшую демонстрацию с примерами их использования.

Всего на семестр у вас будет 6 задач.

| Задача 	| Число классов 	| Время на решение (в неделях) 	|
|:------:	|:-------------:	|:----------------------------:	|
|  1, 2  	|       1       	|               1              	|
|  3, 4  	|       1+      	|               2              	|
|    5   	|       2+      	|               3              	|
|    6   	|     UI, 2+    	|               4              	|

| Тип задачи | Сложность  | 
|:----------:|:----------:| 
|     L      |  Низкая    |
|     M      |  Средняя   |
|     H      |  Высокая   |

Распределение задач можно найти здесь: [таблица](https://docs.google.com/spreadsheets/d/1KRfV4ydr0sxQcUaSl-PW_Vm9AKXQ5_1kCoj6ITggR5Q/edit#gid=1488127654)

Постановки заданий: [задачи](https://github.com/SemyonBevzuk/Programming_practice_381908-1-2/tree/master/Tasks)

## Работа с Git
### Настройка Git
1. Нужно установить клиент [Git](https://git-scm.com/downloads)
2. Настроить пользователя для работы с репозиториями
    ```bash
    git config --global user.name "name"
    git config --global user.email "name@mail.com"
    ```

### Работа с консолью
Если вы открываете Git Bash через ПКМ в какой-то директории, то консоль запускается из этой директории.

Для проверки этого можете набрать `ls` или `dir`. Вы увидите список файлов в текущей директории.

Для смены директории можете использовать команду `cd`. Подняться выше: `cd ..`. Перейти в конкретную директорию: `cd имя_директории/`.
Имя директории полностью набирать нет нужды, можете нажать Tab и консоль подскажет возможные варианты.

Для повторного использования команды можете найти её при помощи стрелочек.

### Клонирование репозитория
1. Создать аккаунт на GitHub
2. Открыть этот репозиторий
3. Сделать fork этого репозитория (upstream-репозиторий) к себе. В результате в списке ваших репозиториев появится копия данного (origin-репозиторий).
4. Клонировать origin-репозиторий на компьютер можно следующей командой:
    ```bash
    git clone https://github.com/YourName/Programming_practice_381908-1-2.git
    ```
    Ссылку можно найти под кнопкой Clone.
    Перед клонированеим рекомендуется выбрать удобную для вас директорию используя `cd` или открыв Git Bash в нужной директории.
5. Перейти в директорию для дальнейшей работы
    ```bash
    cd Programming_practice_381908-1-2/
    ```
Отлично, теперь у вас на компьютере будет локальная копия данного репозитория. В ней вы можете вести работу.

### Работа с ветками
По умолчанию вы находитесь в ветке master. Но полезно под решаемую задачу создавать свою ветку, которую уже можно будет слить с master. Рассмотрим некоторые команды для работы с ветками.
* Посмотреть на доступные ветки
    ```bash
        git branch -v
    ```
* Создать новую ветку
    ```bash
        git branch имя_ветки
    ```
* Создать новую ветку и перейти в неё
    ```bash
        git checkout -b имя_ветки
    ```
* Сменить ветку
    ```bash
        git checkout имя_ветки
    ```

### Внесение изменений
* Получить текущие изменения по сравнению с прошлым коммитом
    ```bash
        git status
    ```

* Добавить новые файлы в коммит

    Вы увидели в консоли список файлов и решили часть из них добавить в будущий коммит. Это делается командой:
    ```bash
        git add файл.txt
    ```
    Можно добавить все новые файлы, кроме указанных в .gitignore.
    ```bash
        git add *
    ```
    Использовать этот трюк стоит аккуратно, дабы не заполнить репозиторий лишними файлами.

* Добавление нового коммита локально

    Теперь у нас есть файлы, которые мы хотим добавить в новый коммит. Можем проверить это командой `git status`. Создадим локальный коммит.
    ```bash
        git commit -m "Краткое описание изменений"
    ```
    Если вы не укажите через -m описание изменений, то Git попросит их написать в [Vim](https://stackoverflow.com/questions/11828270/how-do-i-exit-the-vim-editor).

* Отправка изменений в origin-репозиторий

    Вы сохранили свои изменения только локально, если зайти в репозиторий на сайте, то их там не будет. Нужно его обновить.
    ```bash
        git push origin HEAD
    ```
    Git попросит вас ввести логин и пароль от аккаунта на GitHub. Если не хотите вводить их постоянно, то вы можете настроить доступ по SSH.

* История коммитов

    Вы можете посмотреть на историю коммитов. В ней указывается автор коммита, его описание, время, хэш коммита.
    ```bash
        git log
    ```

### Создание pull-request
Вы успешно решили задание и хотите отправить его на проверку. Для этого нужно создать Pull Request в upstream-репозиторий.
1. Откройте ваш origin-репозиторий на сайте GitHub
2. Нажмите кнопку Pull Request и даллее  New Pull Request
3. Выберите какую ветку вы хотите отправить в upstream-репозиторий
4. Назовите свой Pull Request по шаблону: 
    ` "Бевзюк -- Задание #1" `
5. Если по вашей работе будут замечания, то вы их исправляете у себя, делаете коммит, пушите к себе в репозиторий и изменения автоматически будут добавлены в созданный Pull Request. Не нужно создавать ещё один.

### Получение изменений
Для получения последних изменений из своего репозитория и слияния их в текущую ветку можно воспользоваться командой
```bash
    git pull
```

Если вы хотите просто скачать изменения для сохранения их локально без слияния, то используйте  
```bash
    git fetch 
```

Перед началом работы над следующим заданием полезно синхронизироваться с upstream-репозиторием.
```bash
    git remote add upstream https://github.com/SemyonBevzuk/Programming_practice_381908-1-2
    git fetch upstream
    git checkout -b ваша_ветка
```

## Ссылки про работу с Git
Информации про Git много, можно найти решение почти любой проблемы.
* [Книга Pro Git](https://git-scm.com/book/ru/v2)
* [Интерактивный учебник с годной визуализацией](https://learngitbranching.js.org/)

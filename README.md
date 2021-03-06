#  Deadline Helper
Данное приложение помогает хранить Ваши существующие дедлайны в одном месте. С его помощью Вы можете менять прогресс, дату и время Ваших дедлайнов и отслеживать текущее состояние.

## Команды
* `add <name> <type> <task> <date: dd.mm.yyyy> <time: hh:mm:ss>` — добавить новый дедлайн с данными характеристиками в список.
Бывает два типа дедлайна: `big` и `set`.
`big` означает, что это большое задание и `<task> = x`, где `x` — процент выполненного задания.
`set` означает, что это набор заданий и `<task> = x y`, где `x` — общее количество заданий, а `y` — количество выполненных к данном моменту.
* `remove <name>` — удалить данный дедлайн из списка.
* `change name progress <task>` — изменить прогресс данного дедлайна.
* `change name date <date: dd.mm.yyyy>` — изменить дату данного дедлайна.
* `change name time <time: hh:mm:ss>` — изменить время данного дедлайна.
* `list` — вывести список дедлайнов.
* `exit` — завершить работу.

Приложение сохраняет информацию о списке в файле `deadlineList.txt` для его использования при следующем запуске.

## Пример использования
![Example](/media/example.gif)

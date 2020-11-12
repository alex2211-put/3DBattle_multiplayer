 В папке 3DBattle_C++_client лежит код клиента на С++ (игра на локальном компьютере).
 Также там есть скомпиллированный код в папке cmake-build-debug, который сразу можно запускать.
 
 В папке 3DBattle_python_server лежит файл сервера на питоне.

Управление:
На главной странице вас приветствует меню:
* 1 кнопка - начало игры
* 2 кнопка - выбор длины поля (стелочками влево и вправо)
* 3 кнопка - правила игры
* 4 кнопка - разработчики
* 5 кнопка - выход из игры
Для перемещения по пунктам меню используйте стрелочки вверх и вних. А для выбора пункта, нажмите Enter.

Как только вы начнете игру, вам надо будет расставить свои корабли. 
1. Для этого, для начала, используя кнопки f7, f8, f9 нужно выбрать сторону. Выбранная сторона подсвечивается синим цветом.
2. После того, как определились со стороной, нажимаем Enter и нам становится доступным выбор колонки, в которой будет стоять наш корабль. Для выбора колонки пользуемся стрелочками вверх, вниз, вправо и влево. Колонка подсвечивается желтым цветом. Когда определились с колонкой - нажимаем Enter.
3. Когда выбрали колонку, появляется корабль (он закрашен желтым цветом). Чтобы его перемещать по колонке, используйте PgUp и PgDn. Когда выбрали нужное положение, нажимайте Enter, и вы автоматически перейдете к постановке следующего корабля.

После того, как вы расставите свои корабли, появится окно выбора игры - с игроком или ботом. Если вы хотите играть с playerом, то после выбра соответствующего пункта появитя окно ожидания, пока вам не найдут противника. Как только второй игрок подключится, на вашем экране появятся 2 кубика. Слева ваше поле, справа поле соперника. Чтобы стрелять, используйте ту же логику, что и при расстановке кораблей. Сначала выбор стороны, потом колонки, потом кубика. Если вы промахнулись, то ход переходит к сопернику и кубик подсвечивается синим. Если вы попали, то кубик становится красным и вы продолжаете стрелять. Когда корабль будет потоплен, вокруг него все клетки закрасятся синим.
Если же вы пытаетесь выбрать кубик, в который вы уже стреляли, то цвет фона на секунду станет красным и вы снова должны будете выбрать кубик, в который хотите стрелять.

Если вы можете только вращать поле стрелочками, но не получается выбрать сторону, значит сейчас ход соперника. Как только он выстрелит, вы увидите на своем поле или закрашенный синий квадратик (если он промахнулся) или закрашенный красный квадратик, если соответственно было попадание. Между кубиками находится стрелочка, которая красная, когда стреляет противник и зеленая, когда стреляете вы.

Если же вы играете с ботом, то логика игры точно такая же.

В любой момент игры вы можете нажать кнопку Esc, и посмотреть правила, имена разработчиков, размер вашего поля или выйти из игры (нижняя кнопка). Также можете нажать f1 для получения подсказки.

В какой-то момент синих квадратиков может стать достаточно много и будет некомфортно оценивать поле боя. В таком случае вы можете нажать на пробел и все синие поля вырежутся. Останутся только нетронутые клетки и подбитые клетки. Чтобы вернуть их назад, снова нажмите на пробел.

Как только кто-то из вас убьет все корабли соперника, или же ваш соперник решит закрыть игру, то на экране появится сообщение, в котором будет написано, кто выиграл и сколько времени в игре вы провели.

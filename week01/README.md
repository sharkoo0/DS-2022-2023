## Преговор на УП и ООП

### TASK 1 - Рекурсия
Професор Х се забавлява като съставя интересни числови редици. Последното му
творчество е следната редица:
1, 121, 1213121, 121312141213121, …
Първият член на редицата е 1. Всеки от следващите членове се получава от две копия
на предходния член на редицата, между които е изписан поредният номер на текущия
член. Тъй като дължината на числата в редицата нараства много бързо и ръчното им
изписване е доста трудоемко, професорът се нуждае от програма, която да извежда
посочения от него член на тази редица. Помогнете му като напишете програма, която
по въведено цяло положително число n < 20 извежда n-тия член на редицата, следван
от знак за нов ред.

Пример:
Вход:
```
Enter n: 4
```
Изход:
```
121312141213121
```

### TASK 2 - Наследяване и полиморфизъм
Вие работите в голяма компания за разработване на игри. От днес сте в нов екип и ви е поставена следната задача:

Създайте клас Hero, описващ герой в новата игра. Всеки Hero има име и "живот". 
За героя трябва да може да се получава информация за това, колко "живот" има. 
Също така героят трябва да може да се представя. Hero трябва да има чист виртуален метод void attack(Hero* enemy).

Създайте клас Magician, описващ магьосник, наследяващ класа Hero. 
Магьосникът има име, "живот" и "мана". За магьосника трябва да може да се получава информация за това, колко "живот" има, 
и за това, колко "мана" има. Магьосникът също трябва да може да се представя. 
Методът attack на магьосника отнема точно толкова живот от противника, колкото "мана" има в момента магьосникът. 
Освен това всяка атака намалява текущата "мана" на магьосника с 20. 
По подразбиране магьосникът се инициализира със 100 "живот" и 200 "мана".

Създайте клас Warrior, описващ воин, наследяващ класа Hero. 
Воинът има име, "живот" и "ярост". За воина трябва да може да се получава информация за това, колко "живот" има, 
и за това, колко "ярост" има. Воинът също трябва да може да се представя. 
Методът attack на воина отнема на противника толкова "живот", колкото е текущата "ярост" на воина плюс 10. 
Всяка атака увеличава текущата "ярост" на воина с 20. По подразбиране воинът се инициализира с 0 "ярост" и 120 "живот".

Създайте клас Arena, описващ арена за битка между герои.
Арената получава брой герои и списък от такива при създаването си. 
Напишете метод, който извежда данни за героите в битката на всеки рунд. Един рунд представлява
сбор от по една атака на всеки герой.

Да се направи демонстрация на класовете.






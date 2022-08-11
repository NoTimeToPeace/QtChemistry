# Аптека

Данная система выполняет основную задачу – оформление заказа лекарственных средств и выдача их в выбранном пользователем пункте выдачи. Поиск товаров можно осуществить на основе имеющихся симптомов, цене или названию лекарства. Также пользователь может узнать статистику: кол-ва купленного товара, кол-во заказов, суммарная стоимость покупок, любимый пункт выдачи.

## Техническое задание:

- Приложение должно иметь простой и интуитивно понятный пользовательский интерфейс, по возможности, содержащий различного рода подсказки;
- Приложение должно обеспечивать добавление в корзину, удаление из корзины, покупку товаров; сбор статистики по ходу пользования приложения; поиск необходимого товара по критериям: название, болезнь, цена;
- Предотвратить неправильные запросы приложению от пользователя, как при помощи уведомлений пользователя, так и заблокировав определённую функцию до выполнения необходимых требований, приводящих ее в активное состояние;
- Вся информация должна сохраняться и обновляться при каждом пользовательском действии.

## Используемые классы:

- Analytics – класс, отвечающий за статистику для пользователя, также является классом формы;
- Drug – класс, хранящий информацию о лекарствах;
- Drugstore – класс, хранящий информацию об аптеках;
- Goods – класс, хранящий информацию о заказанном товаре;
- Location – класс, хранящий полный адрес;
- Basket – класс управления для вывода товаров корзины и их отправки в заказ;
- Global_setting – класс, управляющий всем приложением;
- Menu – класс управления для переключения среди всех форм и возможности вывода меню на экран;
- Product – класс управления для добавления товаров в корзину и возможности вывода информации о товаре;
- Order – класс формы для вывода ранее сделанных заказов;
- Mainwindow – класс формы, являющийся общим экраном для всех форм и выводящий их.

## Иллюстрации:

Основной экрна:

![image](https://user-images.githubusercontent.com/54364982/184111657-aafe315f-97ae-4463-93bd-0cc261e2f24c.png)

Страница товара:

![image](https://user-images.githubusercontent.com/54364982/184111892-770aaa25-de1b-420f-80d8-6a9697152871.png)

Корзина:

![image](https://user-images.githubusercontent.com/54364982/184112118-594f447e-9346-480c-afb1-3456c0f7a106.png)

Формирование заказа:

![image](https://user-images.githubusercontent.com/54364982/184112208-7afc569a-71bd-4dfc-9e3e-a3f73cfa106a.png)

Оформленные заказы:

![image](https://user-images.githubusercontent.com/54364982/184112342-328859cd-f990-4f31-a44a-fb395d1ea221.png)

Статистика:

![image](https://user-images.githubusercontent.com/54364982/184112470-33067507-a519-496a-9a53-9d7ec8750921.png)


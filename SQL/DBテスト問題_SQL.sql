１．テーブル employee とテーブル accept_order を結合して、従業員名とそれぞれのオプションの価格の合計を表示する SQL 文を記述しなさい。

select 
  E.e_name
  , sum(A.option_price) sum_option_price 
from 
  employee E
left outer join 
  accept_order A 
on 
  E.e_num = A.e_num 
where 
  E.valid_flg = '1' 
group by 
  E.e_num
  , E.e_name
order by 
  sum_option_price desc;

select 
  E.e_name
  , sum(A.option_price) sum_option_price 
from 
  employee E
  , accept_order A 
where 
  E.e_num = A.e_num(+) 
  and E.valid_flg = '1' 
group by 
  E.e_num
  , E.e_name
order by 
  sum_option_price desc;

/*
select E.e_name, nvl(A.sum_option_price,0) sum_option_price from employee E left outer join
(select e_num, sum(option_price) sum_option_price from accept_order group by e_num) A
on E.e_num = A.e_num
where E.valid_flg = '1'
order by sum_option_price desc;

select E.e_name, nvl(A.sum_option_price,0) sum_option_price from employee E,
(select e_num, sum(option_price) sum_option_price from accept_order group by e_num) A
where E.e_num = A.e_num(+)
and E.valid_flg = '1'
order by sum_option_price desc;
*/

２．テーブル「employee」から、それぞれの事務所の男性と女性の人数を求めるための SQL 文を記述しなさい。表示する列は、「営業所名」「性別」及び「各性別の人数」である。gender 列で、'0' は女性、'1' は男性を表す。

select 
  O.office
  , decode(E.gender, '0', '女性', '1', '男性', '') gender
  , count(E.gender) count_gender
from 
  employee E 
left outer join 
  office O 
on 
  E.o_num = O.o_num
where 
  E.valid_flg = '1'
group by 
  O.o_num
  ,O.office
  ,E.gender 
order by 
  office;

select 
  O.office
  , decode(E.gender, '0', '女性', '1', '男性', '') gender
  , count(E.gender) count_gender
from 
  employee E
  , office O 
where
  E.o_num = O.o_num(+)
  and E.valid_flg = '1'
group by 
  O.o_num
  ,O.office
  ,E.gender 
order by 
  office;

/*
select 
  O.office
  , decode(E.gender, '0', '女性', '1', '男性', '') gender
  , E.count_gender 
from
(select o_num, gender, count(gender) count_gender from employee where valid_flg = '1' group by o_num,gender) E left outer join 
office O on E.o_num = O.o_num;

select O.office, decode(E.gender, '0', '女性', '1', '男性', '') gender, E.count_gender 
from 
  (select 
     o_num, gender, count(gender) count_gender 
   from 
     employee 
   where
      valid_flg = '1' 
   group by 
     o_num
     , gender
  ) E,
office O where E.o_num = O.o_num(+);
*/


３．ある自動車メーカーの販売管理データベースに用意されているテーブル customer と office から、各営業所が抱えている顧客が何名いるのかを確認する SQL 文を記述しなさい。営業所名と顧客の人数を表示すること。

select 
  O.office
  , count(C.c_num) count_c_num 
from 
  customer C 
left outer join 
  office O 
on 
  C.o_num = O.o_num
group by 
  O.o_num
  , O.office
order by 
  count_c_num desc;

select 
  O.office
  , count(C.c_num) count_c_num 
from 
  customer C
  , office O 
where 
  C.o_num = O.o_num(+)
group by 
  O.o_num
  , O.office
order by 
  count_c_num desc;

/*
select O.office, C.count_c_num from 
(select o_num, count(c_num) count_c_num from customer group by o_num) C left outer join
office O on C.o_num = O.o_num
order by C.count_c_num desc;
*/
  
４．販売管理データベースから、支払った金額の大きいもの順に、顧客名と支払った合計金額を表示する SQL 文を記述しなさい。一回あたりの支払い金額は、次の式で求めるものとする。複数台自動車を購入した顧客はそれらすべてを合計したものを支払い金額とする。
(製品の価格) x (100 - (製品の値引率)) / 100 + (オプションの価格) 
= product.price x (100 - accept_order.dc_rate) / 100 + accept_order.option_price 
顧客名とその支払い金額を表示すること。

select 
  C.c_name
  , nvl(sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)), 0) sum_price
  , count(A.order_num) count_order  
from 
  customer C 
left outer join 
  accept_order A 
on 
  C.c_num = A.c_num 
  and A.o_flg = '1'
left outer join 
  product P 
on 
  A.p_num = P.p_num
group by 
  C.c_num, C.c_name
order by 
  sum_price;
  
select 
  C.c_name
  , nvl(sum(P.price * (100 - A.dc_rate) / 100 + A.option_price),0) sum_price
  , count(A.order_num) count_order  
from 
  customer C
  , accept_order A
  , product P 
where 
  C.c_num = A.c_num(+)
  and A.o_flg(+) = '1'
  and A.p_num = P.p_num(+) 
group by 
  C.c_num
  , C.c_name
order by 
  sum_price;


５．販売管理データベースから、2012年 3月中に各従業員の自動車販売件数を、販売件数の少ないものから順に表示する SQL 文を記述しなさい。従業員名と販売件数を表示すること。

select 
  E.e_name
  , count(A.order_num) count_order_num
from 
  employee E 
left outer join 
  accept_order A 
on 
  E.e_num = A.e_num 
  and A.accept_date >= to_date('2012/03/01', 'yyyy/mm/dd')
  and A.accept_date <= to_date('2012/03/31', 'yyyy/mm/dd')
where 
  E.valid_flg = '1'
group by 
  E.e_num
  , E.e_name
order by 
  count_order_num;

select 
  E.e_name
  ,count(A.order_num) count_order_num
from 
  employee E, accept_order A 
where 
  E.e_num = A.e_num(+)
  and A.accept_date(+) >= to_date('2012/03/01', 'yyyy/mm/dd')
  and A.accept_date(+) <= to_date('2012/03/31', 'yyyy/mm/dd')
  and E.valid_flg = '1'
group by 
  E.e_num
  , E.e_name
order by 
  count_order_num;
  
/*
select E.e_name, count(A.order_num) count_order_num
from employee E left outer join accept_order A on E.e_num = A.e_num and to_char(A.accept_date, 'yyyy/mm') = '2012/03'
where E.valid_flg = '1'
group by E.e_num, E.e_name
order by count_order_num;

select E.e_name, count(A.order_num) count_order_num
from employee E, accept_order A 
where E.e_num = A.e_num(+) and E.valid_flg = '1' and to_char(A.accept_date, 'yyyy/mm') = '2012/03'
group by E.e_num, E.e_name
order by count_order_num;
*/


６．販売管理データベースから、3台以上の自動車を販売した従業員の名前を表示する SQL 文を記述しなさい。

select 
  E.e_name
  , count(A.order_num) count_order_num
from 
  accept_order A 
left outer join 
  employee E 
on 
  E.e_num = A.e_num 
  and E.valid_flg = '1'
where 
  A.o_flg = '1' 
group by 
  E.e_num
  , E.e_name
having 
  count(A.order_num) >= 3
order by 
  count_order_num;

select 
  E.e_name
  , count(A.order_num) count_order_num
from 
  accept_order A
  , employee E 
where 
  A.e_num = E.e_num(+) 
  and E.valid_flg(+) = '1' 
  and A.o_flg = '1' 
group by 
  E.e_num
  , E.e_name
having 
  count(A.order_num) >= 3
order by 
  count_order_num;

/*
select E.e_name, count(A.order_num) count_order_num
from employee E left outer join accept_order A on E.e_num = A.e_num
where E.valid_flg = 1
group by E.e_num, E.e_name
having count(A.order_num) >= 3
order by count_order_num;

select E.e_name, count(A.order_num) count_order_num
from employee E, accept_order A 
where E.e_num = A.e_num(+) and E.valid_flg = 1
group by E.e_num, E.e_name
having count(A.order_num) >= 3
order by count_order_num;
*/

７．販売管理データベースから、1月始めから 3月末までの受注で、対象年月、各月の売上台数を表示させる SQL 文を記述しなさい。

select 
  to_char(A.accept_date, 'yyyy/mm') year_month
  , count(A.order_num) count_order_num
from 
  accept_order A 
where 
  A.o_flg = '1' 
  and A.accept_date >= to_date('2012/01/01','yyyy/mm/dd')
  and A.accept_date <= to_date('2012/03/31','yyyy/mm/dd')
group by 
  to_char(A.accept_date, 'yyyy/mm')
order by 
  year_month;


８．販売管理データベースから、顧客番号が '1007' の顧客と同じ自動車を購入した顧客の顧客番号を参照する SQL 文を記述しなさい。ただし、顧客番号 '1007' は表示しないようにすること。

select 
  A.c_num 
from 
  accept_order A
where 
  A.o_flg = '1' 
  and A.c_num <> '1007' 
  and exists 
    (select 
      p_num 
    from 
      accept_order A2 
    where 
      A2.c_num = '1007' 
      and A.p_num = A2.p_num);

select 
  A.c_num 
from 
  accept_order A
where 
  A.o_flg = '1' 
  and A.c_num <> '1007' 
  and A.p_num in 
    (select 
      p_num 
    from 
      accept_order 
    where 
      c_num = '1007');
  
select 
  A.c_num
from 
  accept_order A
inner join
  accpet_order A2
on
  A.p_num = A2.p_num
  and A2.c_num = '1007'
  and A2.o_flg = '1' 
where 
  A.o_flg = '1' 
and 
  A.c_num <> '1007';



９．販売管理データベースから、1月始めから 3月末までの受注で、対象年月、各月の売上台数及び売上総額を表示させる SQL 文を記述しなさい。一回あたりの販売金額は、題４の計算式で求めるものとする。

select 
  to_char(A.accept_date, 'yyyy/mm') year_month
  , count(A.order_num) count_order_num, 
  sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)) sum_price
from 
  accept_order A 
left outer join 
  product P 
on 
  A.p_num = P.p_num
where 
  A.o_flg = '1' 
  and A.accept_date >= to_date('2012/01/01','yyyy/mm/dd')
  and A.accept_date <= to_date('2012/03/31','yyyy/mm/dd')
group by 
  to_char(A.accept_date, 'yyyy/mm')
order by 
  year_month;

select 
  to_char(A.accept_date, 'yyyy/mm') year_month
  , count(A.order_num) count_order_num, 
  sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)) sum_price
from 
  accept_order A
  , product P 
where 
  A.p_num = P.p_num(+) 
  and A.o_flg = '1' 
  and A.accept_date >= to_date('2012/01/01','yyyy/mm/dd')
  and A.accept_date <= to_date('2012/03/31','yyyy/mm/dd')
group by 
  to_char(A.accept_date, 'yyyy/mm')
order by 
  year_month;

/*
select to_char(A.accept_date, 'yyyy/mm') year_month, count(A.order_num) count_order_num, 
  sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)) sum_price
from accept_order A left outer join product P on A.p_num = P.p_num
where A.o_flg = '1' and to_char(A.accept_date,'yyyy/mm') between '2012/01' and '2012/03'
group by to_char(A.accept_date, 'yyyy/mm')
order by year_month;

select to_char(A.accept_date, 'yyyy/mm') year_month, count(A.order_num) count_order_num, 
  sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)) sum_price
from accept_order A, product P 
where A.p_num = P.p_num(+) and A.o_flg = '1' and to_char(A.accept_date,'yyyy/mm') between '2012/01' and '2012/03'
group by to_char(A.accept_date, 'yyyy/mm')
order by year_month;

select to_char(A.accept_date, 'yyyy/mm') year_month, P.price, A.dc_rate, A.option_price
from accept_order A left outer join product P on A.p_num = P.p_num
where A.o_flg = '1' and to_char(A.accept_date,'yyyy/mm') between '2012/01' and '2012/03'
order by A.accept_date;
*/

１０．販売管理データベースから、自動車販売件数が一番多い従業員の名前を表示させる SQL 文を記述しなさい。

select 
  A.e_num
  , E.e_name
  , count(A.order_num) count_order_num 
from 
  accept_order A 
left outer join 
  employee E 
on 
  A.e_num = E.e_num 
  and E.valid_flg = '1'
where 
  A.o_flg = '1'
group by 
  A.e_num, E.e_name
having 
  count(order_num) = 
    (select 
      max(count(order_num)) 
    from 
      accept_order 
    group by 
      e_num);

select 
  A.e_num
  , E.e_name
  , count(A.order_num) count_order_num 
from 
  accept_order A
  , employee E 
where 
  A.e_num = E.e_num(+)
  and E.valid_flg(+) = '1'
  and A.o_flg = '1'
group by 
  A.e_num
  , E.e_name
having 
  count(A.order_num) =
    (select
      max(count(order_num)) 
    from 
      accept_order
    group by 
      e_num);

/*
select A.e_num, E.e_name, count(A.order_num) count_order_num 
from accept_order A left outer join employee E on A.e_num = E.e_num
group by A.e_num, E.e_name
order by count_order_num desc
*/


１１．販売管理データベースから、顧客別各月集計の顧客名、対象年月、製品名、購入件数、購入金額合計を表示させる SQL 文を記述しなさい。（回あたりの販売金額は、題４の計算式で求めるものとする。）

select 
  C.c_name
  , to_char(A.accept_date, 'yyyy/mm') year_month
  , P.p_name
  , count(A.order_num) count_order_num
  , sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)) sum_price
from 
  customer C 
left outer join 
  accept_order A 
on
  A.c_num = C.c_num 
  and A.o_flg = '1'
left outer join 
  product P 
on 
  A.p_num = P.p_num
group by 
  A.c_num
  , C.c_name
  , to_char(A.accept_date, 'yyyy/mm')
  , A.p_num
  , P.p_name
order by 
  C.c_name
  , year_month
  , sum_price desc;

select 
  C.c_name
  , to_char(A.accept_date, 'yyyy/mm') year_month
  , P.p_name
  , count(A.order_num) count_order_num
  , sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)) sum_price
from 
  customer C
  , accept_order A
  , product P
where 
  C.c_num = A.c_num(+)
  and A.o_flg(+) = '1' 
  and A.p_num = P.p_num(+)
group by 
  A.c_num
  , C.c_name
  , to_char(A.accept_date, 'yyyy/mm')
  , A.p_num
  , P.p_name
order by 
  C.c_name
  , year_month
  , sum_price desc;

/*
select C.c_name, to_char(A.accept_date, 'yyyy/mm') year_month, P.p_name, count(A.order_num) count_order_num, 
  sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)) sum_price
from accept_order A left outer join customer C on A.c_num = C.c_num
  left outer join product P on A.p_num = P.p_num
where A.o_flg = '1'
group by A.c_num, C.c_name, to_char(A.accept_date, 'yyyy/mm'), A.p_num, P.p_name
order by year_month, sum_price desc;

select C.c_name, to_char(A.accept_date, 'yyyy/mm') year_month, P.p_name, count(A.order_num) count_order_num, 
  sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)) sum_price
from accept_order A, customer C, product P 
where A.c_num = C.c_num(+) and A.p_num = P.p_num(+) and A.o_flg = '1'
group by A.c_num, C.c_name, to_char(A.accept_date, 'yyyy/mm'), A.p_num, P.p_name
order by year_month, sum_price desc;

select C.c_name, to_char(A.accept_date, 'yyyy/mm') year_month, P.p_name, count(A.order_num) count_order_num, 
  sum((P.price * (100 - A.dc_rate) / 100 + A.option_price)) sum_price
from customer C, accept_order A, product P 
where C.c_num = A.c_num(+) and A.p_num = P.p_num(+) and A.o_flg = '1'
group by A.c_num, C.c_name, to_char(A.accept_date, 'yyyy/mm'), A.p_num, P.p_name
order by year_month, sum_price desc;
*/
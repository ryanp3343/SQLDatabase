#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H

/*
 * SQL>exec _!sample2.txt
//****************************************************************************
//              CREATE TABLES AND INSERT RECORDS
//****************************************************************************
0: make table employee fields  last,            first,                  dep,            salary,         year
record  last                first               dep                 salary              year

SQL: DONE.

1: insert into employee values Blow,            Joe,                    CS,                     100000,         2018
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
SQL: DONE.

2: insert into employee values Blow,            JoAnn,                  Physics,        200000,         2016
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
SQL: DONE.

3: insert into employee values Johnson,         Jack,                   HR,             150000,         2014
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Johnson             Jack                HR                  150000              2014
SQL: DONE.

4: insert into employee values Johnson,         "Jimmy",                Chemistry,      140000,         2018
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Johnson             Jack                HR                  150000              2014
3       Johnson             Jimmy               Chemistry           140000              2018
SQL: DONE.

5: insert into employee values Yao,             Jimmy,                  Math,           145000,         2014
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Johnson             Jack                HR                  150000              2014
3       Johnson             Jimmy               Chemistry           140000              2018
4       Yao                 Jimmy               Math                145000              2014
SQL: DONE.

6: insert into employee values "Yao",           Flo,                    CS,                     147000,         2012
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Johnson             Jack                HR                  150000              2014
3       Johnson             Jimmy               Chemistry           140000              2018
4       Yao                 Jimmy               Math                145000              2014
5       Yao                 Flo                 CS                  147000              2012
SQL: DONE.

7: insert into employee values Yang,            Bo,                     CS,                     160000,         2013
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Johnson             Jack                HR                  150000              2014
3       Johnson             Jimmy               Chemistry           140000              2018
4       Yang                Bo                  CS                  160000              2013
5       Yao                 Jimmy               Math                145000              2014
6       Yao                 Flo                 CS                  147000              2012
SQL: DONE.

8: insert into employee values Jackson, "Flo",                  Math,           165000,         2017
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Johnson             Jack                HR                  150000              2014
4       Johnson             Jimmy               Chemistry           140000              2018
5       Yang                Bo                  CS                  160000              2013
6       Yao                 Jimmy               Math                145000              2014
7       Yao                 Flo                 CS                  147000              2012
SQL: DONE.

9: insert into employee values Jackson, Bo,                             Chemistry,      130000,         2011
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Johnson             Jack                HR                  150000              2014
5       Johnson             Jimmy               Chemistry           140000              2018
6       Yang                Bo                  CS                  160000              2013
7       Yao                 Jimmy               Math                145000              2014
8       Yao                 Flo                 CS                  147000              2012
SQL: DONE.

10: insert into employee values "Jackson",      Billy,                  Math,           170000,         2017
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Yang                Bo                  CS                  160000              2013
8       Yao                 Jimmy               Math                145000              2014
9       Yao                 Flo                 CS                  147000              2012
SQL: DONE.

11: insert into employee values Johnson,        "Mary Ann",     Math,           165000,         2014
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Johnson             Mary Ann            Math                165000              2014
8       Yang                Bo                  CS                  160000              2013
9       Yao                 Jimmy               Math                145000              2014
10      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

12: insert into employee values Johnson,        "Billy Bob",    Physics,        142000,         2014
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Johnson             Mary Ann            Math                165000              2014
8       Johnson             Billy Bob           Physics             142000              2014
9       Yang                Bo                  CS                  160000              2013
10      Yao                 Jimmy               Math                145000              2014
11      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

13: insert into employee values Johnson,        Billy,                  "Phys Ed",      102000,         2014
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Johnson             Mary Ann            Math                165000              2014
8       Johnson             Billy Bob           Physics             142000              2014
9       Johnson             Billy               Phys Ed             102000              2014
10      Yang                Bo                  CS                  160000              2013
11      Yao                 Jimmy               Math                145000              2014
12      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

14: insert into employee values "Van Gogh",     Vincent,                Art,            240000,         2015
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Johnson             Mary Ann            Math                165000              2014
8       Johnson             Billy Bob           Physics             142000              2014
9       Johnson             Billy               Phys Ed             102000              2014
10      Van Gogh            Vincent             Art                 240000              2015
11      Yang                Bo                  CS                  160000              2013
12      Yao                 Jimmy               Math                145000              2014
13      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

15: insert into employee values "Van Gogh",     Vincent,                CS,                     245000,         2015
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Johnson             Mary Ann            Math                165000              2014
8       Johnson             Billy Bob           Physics             142000              2014
9       Johnson             Billy               Phys Ed             102000              2014
10      Van Gogh            Vincent             Art                 240000              2015
11      Van Gogh            Vincent             CS                  245000              2015
12      Yang                Bo                  CS                  160000              2013
13      Yao                 Jimmy               Math                145000              2014
14      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

16: insert into employee values "Van Gogh",     "Jim Bob",              "Phys Ed",      230000,         2010
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Johnson             Mary Ann            Math                165000              2014
8       Johnson             Billy Bob           Physics             142000              2014
9       Johnson             Billy               Phys Ed             102000              2014
10      Van Gogh            Vincent             Art                 240000              2015
11      Van Gogh            Vincent             CS                  245000              2015
12      Van Gogh            Jim Bob             Phys Ed             230000              2010
13      Yang                Bo                  CS                  160000              2013
14      Yao                 Jimmy               Math                145000              2014
15      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

17: select * from employee
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Johnson             Mary Ann            Math                165000              2014
8       Johnson             Billy Bob           Physics             142000              2014
9       Johnson             Billy               Phys Ed             102000              2014
10      Van Gogh            Vincent             Art                 240000              2015
11      Van Gogh            Vincent             CS                  245000              2015
12      Van Gogh            Jim Bob             Phys Ed             230000              2010
13      Yang                Bo                  CS                  160000              2013
14      Yao                 Jimmy               Math                145000              2014
15      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

18: make table student fields fname, lname, major, age, company
record  fname               lname               major               age                 company

SQL: DONE.

19: insert into student values Flo,                     Yao,            CS,                             20,     Google
record  fname               lname               major               age                 company

0       Flo                 Yao                 CS                  20                  Google
SQL: DONE.

20: insert into student values Bo,                              Yang,           CS,                             28,
                Microsoft
record  fname               lname               major               age                 company

0       Bo                  Yang                CS                  28                  Microsoft
1       Flo                 Yao                 CS                  20                  Google
SQL: DONE.

21: insert into student values "Sammuel L.",    Jackson,        CS,                             40,             Uber
record  fname               lname               major               age                 company

0       Bo                  Yang                CS                  28                  Microsoft
1       Flo                 Yao                 CS                  20                  Google
2       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

22: insert into student values "Flo",                   "Jackson",      Math,                           21,
        Google
record  fname               lname               major               age                 company

0       Bo                  Yang                CS                  28                  Microsoft
1       Flo                 Yao                 CS                  20                  Google
2       Flo                 Jackson             Math                21                  Google
3       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

23: insert into student values "Greg",                  "Pearson",      Physics,                        20,
        Amazon
record  fname               lname               major               age                 company

0       Bo                  Yang                CS                  28                  Microsoft
1       Flo                 Yao                 CS                  20                  Google
2       Flo                 Jackson             Math                21                  Google
3       Greg                Pearson             Physics             20                  Amazon
4       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

24: insert into student values "Jim Bob",               Smith,          Math,                           23,
        Verizon
record  fname               lname               major               age                 company

0       Bo                  Yang                CS                  28                  Microsoft
1       Flo                 Yao                 CS                  20                  Google
2       Flo                 Jackson             Math                21                  Google
3       Greg                Pearson             Physics             20                  Amazon
4       Jim Bob             Smith               Math                23                  Verizon
5       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

25: insert into student values Calvin,                  Woo,            Physics,                        22,
        Uber
record  fname               lname               major               age                 company

0       Bo                  Yang                CS                  28                  Microsoft
1       Calvin              Woo                 Physics             22                  Uber
2       Flo                 Yao                 CS                  20                  Google
3       Flo                 Jackson             Math                21                  Google
4       Greg                Pearson             Physics             20                  Amazon
5       Jim Bob             Smith               Math                23                  Verizon
6       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

26: insert into student values "Anna Grace",    "Del Rio",      CS,                                     22,
        USAF
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
1       Bo                  Yang                CS                  28                  Microsoft
2       Calvin              Woo                 Physics             22                  Uber
3       Flo                 Yao                 CS                  20                  Google
4       Flo                 Jackson             Math                21                  Google
5       Greg                Pearson             Physics             20                  Amazon
6       Jim Bob             Smith               Math                23                  Verizon
7       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

27: insert into student values "Teresa Mae",    Gowers,         Chemistry,                      22,             Verizon
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
1       Bo                  Yang                CS                  28                  Microsoft
2       Calvin              Woo                 Physics             22                  Uber
3       Flo                 Yao                 CS                  20                  Google
4       Flo                 Jackson             Math                21                  Google
5       Greg                Pearson             Physics             20                  Amazon
6       Jim Bob             Smith               Math                23                  Verizon
7       Sammuel L.          Jackson             CS                  40                  Uber
8       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

28: insert into student values Alex,                    Smith,          "Gender Studies",       53,             Amazon
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Anna Grace          Del Rio             CS                  22                  USAF
2       Bo                  Yang                CS                  28                  Microsoft
3       Calvin              Woo                 Physics             22                  Uber
4       Flo                 Yao                 CS                  20                  Google
5       Flo                 Jackson             Math                21                  Google
6       Greg                Pearson             Physics             20                  Amazon
7       Jim Bob             Smith               Math                23                  Verizon
8       Sammuel L.          Jackson             CS                  40                  Uber
9       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

29: select * from student
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Anna Grace          Del Rio             CS                  22                  USAF
2       Bo                  Yang                CS                  28                  Microsoft
3       Calvin              Woo                 Physics             22                  Uber
4       Flo                 Yao                 CS                  20                  Google
5       Flo                 Jackson             Math                21                  Google
6       Greg                Pearson             Physics             20                  Amazon
7       Jim Bob             Smith               Math                23                  Verizon
8       Sammuel L.          Jackson             CS                  40                  Uber
9       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

//****************************************************************************
//              SIMPLE SELECT:
//****************************************************************************
30: select * from student
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Anna Grace          Del Rio             CS                  22                  USAF
2       Bo                  Yang                CS                  28                  Microsoft
3       Calvin              Woo                 Physics             22                  Uber
4       Flo                 Yao                 CS                  20                  Google
5       Flo                 Jackson             Math                21                  Google
6       Greg                Pearson             Physics             20                  Amazon
7       Jim Bob             Smith               Math                23                  Verizon
8       Sammuel L.          Jackson             CS                  40                  Uber
9       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

//------- simple strings -------------------
31: select * from student where lname = Jackson
record  fname               lname               major               age                 company

0       Flo                 Jackson             Math                21                  Google
1       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

32: select * from student where major = CS
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
1       Bo                  Yang                CS                  28                  Microsoft
2       Flo                 Yao                 CS                  20                  Google
3       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

33: select * from student where company = Uber
record  fname               lname               major               age                 company

0       Calvin              Woo                 Physics             22                  Uber
1       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

//----- quoted strings ---------------------
34: select * from student where lname = "Del Rio"
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
SQL: DONE.

35: select * from student where fname = "Jim Bob"
record  fname               lname               major               age                 company

0       Jim Bob             Smith               Math                23                  Verizon
SQL: DONE.

36: select * from student where fname = "Anna Grace"
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
SQL: DONE.

37: select * from student where fname = "Teresa Mae"
record  fname               lname               major               age                 company

0       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

//-------- non-existing string ------------------
38: select * from student where lname = "Does Not Exist"
record  fname               lname               major               age                 company

SQL: DONE.

//****************************************************************************
//              RELATIONAL OPERATORS:
//****************************************************************************
//.................
//:Greater Than   :
//.................
39: select * from student where lname > Yang
record  fname               lname               major               age                 company

0       Flo                 Yao                 CS                  20                  Google
SQL: DONE.

40: select * from student where major > Math
record  fname               lname               major               age                 company

0       Calvin              Woo                 Physics             22                  Uber
1       Greg                Pearson             Physics             20                  Amazon
SQL: DONE.

41: select * from student where fname > "Sammuel L."
record  fname               lname               major               age                 company

0       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

42: select * from employee where salary > 200000
record  last                first               dep                 salary              year

0       Van Gogh            Jim Bob             Phys Ed             230000              2010
1       Van Gogh            Vincent             Art                 240000              2015
2       Van Gogh            Vincent             CS                  245000              2015
SQL: DONE.

43: select * from employee where dep > Chemistry
record  last                first               dep                 salary              year

0       Blow                JoAnn               Physics             200000              2016
1       Jackson             Flo                 Math                165000              2017
2       Jackson             Billy               Math                170000              2017
3       Johnson             Jack                HR                  150000              2014
4       Johnson             Mary Ann            Math                165000              2014
5       Johnson             Billy               Phys Ed             102000              2014
6       Johnson             Billy Bob           Physics             142000              2014
7       Van Gogh            Jim Bob             Phys Ed             230000              2010
8       Yao                 Jimmy               Math                145000              2014
SQL: DONE.

44: select * from employee where last > Jackson
record  last                first               dep                 salary              year

0       Johnson             Jack                HR                  150000              2014
1       Johnson             Jimmy               Chemistry           140000              2018
2       Johnson             Mary Ann            Math                165000              2014
3       Johnson             Billy Bob           Physics             142000              2014
4       Johnson             Billy               Phys Ed             102000              2014
5       Van Gogh            Vincent             Art                 240000              2015
6       Van Gogh            Vincent             CS                  245000              2015
7       Van Gogh            Jim Bob             Phys Ed             230000              2010
8       Yang                Bo                  CS                  160000              2013
9       Yao                 Jimmy               Math                145000              2014
10      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

45: select * from employee where first > "Billy Bob"
record  last                first               dep                 salary              year

0       Blow                JoAnn               Physics             200000              2016
1       Blow                Joe                 CS                  100000              2018
2       Jackson             Bo                  Chemistry           130000              2011
3       Jackson             Flo                 Math                165000              2017
4       Johnson             Jack                HR                  150000              2014
5       Johnson             Jimmy               Chemistry           140000              2018
6       Johnson             Mary Ann            Math                165000              2014
7       Van Gogh            Jim Bob             Phys Ed             230000              2010
8       Van Gogh            Vincent             Art                 240000              2015
9       Van Gogh            Vincent             CS                  245000              2015
10      Yang                Bo                  CS                  160000              2013
11      Yao                 Flo                 CS                  147000              2012
12      Yao                 Jimmy               Math                145000              2014
SQL: DONE.

//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
46: select * from student where age > 50
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
SQL: DONE.

47: select * from student where age > 35
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

48: select * from student where fname > T
record  fname               lname               major               age                 company

0       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

49: select * from employee where salary > 130000
record  last                first               dep                 salary              year

0       Blow                JoAnn               Physics             200000              2016
1       Jackson             Flo                 Math                165000              2017
2       Jackson             Billy               Math                170000              2017
3       Johnson             Jimmy               Chemistry           140000              2018
4       Johnson             Billy Bob           Physics             142000              2014
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Mary Ann            Math                165000              2014
7       Van Gogh            Jim Bob             Phys Ed             230000              2010
8       Van Gogh            Vincent             Art                 240000              2015
9       Van Gogh            Vincent             CS                  245000              2015
10      Yang                Bo                  CS                  160000              2013
11      Yao                 Jimmy               Math                145000              2014
12      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

50: select * from employee where  year > 2009
record  last                first               dep                 salary              year

0       Blow                JoAnn               Physics             200000              2016
1       Blow                Joe                 CS                  100000              2018
2       Jackson             Bo                  Chemistry           130000              2011
3       Jackson             Flo                 Math                165000              2017
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Mary Ann            Math                165000              2014
7       Johnson             Billy Bob           Physics             142000              2014
8       Johnson             Billy               Phys Ed             102000              2014
9       Johnson             Jimmy               Chemistry           140000              2018
10      Van Gogh            Jim Bob             Phys Ed             230000              2010
11      Van Gogh            Vincent             Art                 240000              2015
12      Van Gogh            Vincent             CS                  245000              2015
13      Yang                Bo                  CS                  160000              2013
14      Yao                 Flo                 CS                  147000              2012
15      Yao                 Jimmy               Math                145000              2014
SQL: DONE.

//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .
51: select * from student where age  > 53
record  fname               lname               major               age                 company

SQL: DONE.

52: select * from student where lname > Yao
record  fname               lname               major               age                 company

SQL: DONE.

53: select * from student where fname > "Teresa Mae"
record  fname               lname               major               age                 company

SQL: DONE.

54: select * from employee where last > "Van Gogh"
record  last                first               dep                 salary              year

0       Yang                Bo                  CS                  160000              2013
1       Yao                 Jimmy               Math                145000              2014
2       Yao                 Flo                 CS                  147000              2012
SQL: DONE.

55: select * from employee where first > Vincent
record  last                first               dep                 salary              year

SQL: DONE.

56: select * from employee where salary > 260000
record  last                first               dep                 salary              year

SQL: DONE.

//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . .
57: select * from student where age > 54
record  fname               lname               major               age                 company

SQL: DONE.

58: select * from student where lname > Zoolander
record  fname               lname               major               age                 company

SQL: DONE.

59: select * from employee where last > Zoolaner
record  last                first               dep                 salary              year

SQL: DONE.

60: select * from employee where first > Xu
record  last                first               dep                 salary              year

SQL: DONE.

//.................
//:Greater Equal  :
//.................
61: select * from student where lname >= Yang
record  fname               lname               major               age                 company

0       Bo                  Yang                CS                  28                  Microsoft
1       Flo                 Yao                 CS                  20                  Google
SQL: DONE.

62: select * from student where fname >= "Sammuel L."
record  fname               lname               major               age                 company

0       Sammuel L.          Jackson             CS                  40                  Uber
1       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

63: select * from student where age >= 40
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . .
64: select * from employee where last >= Jack
record  last                first               dep                 salary              year

0       Jackson             Flo                 Math                165000              2017
1       Jackson             Bo                  Chemistry           130000              2011
2       Jackson             Billy               Math                170000              2017
3       Johnson             Jack                HR                  150000              2014
4       Johnson             Jimmy               Chemistry           140000              2018
5       Johnson             Mary Ann            Math                165000              2014
6       Johnson             Billy Bob           Physics             142000              2014
7       Johnson             Billy               Phys Ed             102000              2014
8       Van Gogh            Vincent             Art                 240000              2015
9       Van Gogh            Vincent             CS                  245000              2015
10      Van Gogh            Jim Bob             Phys Ed             230000              2010
11      Yang                Bo                  CS                  160000              2013
12      Yao                 Jimmy               Math                145000              2014
13      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

65: select * from employee where first >= Bill
record  last                first               dep                 salary              year

0       Blow                JoAnn               Physics             200000              2016
1       Blow                Joe                 CS                  100000              2018
2       Jackson             Billy               Math                170000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Flo                 Math                165000              2017
5       Johnson             Billy               Phys Ed             102000              2014
6       Johnson             Billy Bob           Physics             142000              2014
7       Johnson             Jack                HR                  150000              2014
8       Johnson             Jimmy               Chemistry           140000              2018
9       Johnson             Mary Ann            Math                165000              2014
10      Van Gogh            Jim Bob             Phys Ed             230000              2010
11      Van Gogh            Vincent             Art                 240000              2015
12      Van Gogh            Vincent             CS                  245000              2015
13      Yang                Bo                  CS                  160000              2013
14      Yao                 Flo                 CS                  147000              2012
15      Yao                 Jimmy               Math                145000              2014
SQL: DONE.

66: select * from employee where salary >= 235000
record  last                first               dep                 salary              year

0       Van Gogh            Vincent             Art                 240000              2015
1       Van Gogh            Vincent             CS                  245000              2015
SQL: DONE.

//.................
//:Less Than      :
//.................
//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .
67: select * from student where lname < Jackson
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
1       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

68: select * from student where major < Math
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Anna Grace          Del Rio             CS                  22                  USAF
2       Bo                  Yang                CS                  28                  Microsoft
3       Flo                 Yao                 CS                  20                  Google
4       Sammuel L.          Jackson             CS                  40                  Uber
5       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

69: select * from student where fname < "Jim Bob"
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Anna Grace          Del Rio             CS                  22                  USAF
2       Bo                  Yang                CS                  28                  Microsoft
3       Calvin              Woo                 Physics             22                  Uber
4       Flo                 Yao                 CS                  20                  Google
5       Flo                 Jackson             Math                21                  Google
6       Greg                Pearson             Physics             20                  Amazon
SQL: DONE.

70: select * from employee where salary < 200000
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Jackson             Bo                  Chemistry           130000              2011
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Billy               Math                170000              2017
4       Johnson             Billy               Phys Ed             102000              2014
5       Johnson             Jimmy               Chemistry           140000              2018
6       Johnson             Billy Bob           Physics             142000              2014
7       Johnson             Jack                HR                  150000              2014
8       Johnson             Mary Ann            Math                165000              2014
9       Yang                Bo                  CS                  160000              2013
10      Yao                 Jimmy               Math                145000              2014
11      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

71: select * from employee where dep < CS
record  last                first               dep                 salary              year

0       Van Gogh            Vincent             Art                 240000              2015
SQL: DONE.

72: select * from employee where last < Jackson
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
SQL: DONE.

73: select * from employee where first < "Billy Bob"
record  last                first               dep                 salary              year

0       Jackson             Billy               Math                170000              2017
1       Johnson             Billy               Phys Ed             102000              2014
SQL: DONE.

//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .
74: select * from student where age  < 20
record  fname               lname               major               age                 company

SQL: DONE.

75: select * from student where lname < "Del Rio"
record  fname               lname               major               age                 company

SQL: DONE.

76: select * from student where fname < Alex
record  fname               lname               major               age                 company

SQL: DONE.

77: select * from employee where last < Blow
record  last                first               dep                 salary              year

SQL: DONE.

78: select * from employee where first < Billy
record  last                first               dep                 salary              year

SQL: DONE.

79: select * from employee where salary < 100000
record  last                first               dep                 salary              year

SQL: DONE.

//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . .
80: select * from student where age  < 19
record  fname               lname               major               age                 company

SQL: DONE.

81: select * from student where lname < Adams
record  fname               lname               major               age                 company

SQL: DONE.

82: select * from student where fname < Adam
record  fname               lname               major               age                 company

SQL: DONE.

83: select * from employee where last < Alex
record  last                first               dep                 salary              year

SQL: DONE.

84: select * from employee where first < Avory
record  last                first               dep                 salary              year

SQL: DONE.

85: select * from employee where dep < Alchemy
record  last                first               dep                 salary              year

SQL: DONE.

//.................
//:Less Equal     :
//.................
86: select * from student where lname <= Smith
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Anna Grace          Del Rio             CS                  22                  USAF
2       Flo                 Jackson             Math                21                  Google
3       Greg                Pearson             Physics             20                  Amazon
4       Jim Bob             Smith               Math                23                  Verizon
5       Sammuel L.          Jackson             CS                  40                  Uber
6       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

87: select * from student where fname <= Greg
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Anna Grace          Del Rio             CS                  22                  USAF
2       Bo                  Yang                CS                  28                  Microsoft
3       Calvin              Woo                 Physics             22                  Uber
4       Flo                 Yao                 CS                  20                  Google
5       Flo                 Jackson             Math                21                  Google
6       Greg                Pearson             Physics             20                  Amazon
SQL: DONE.

88: select * from student where age <= 40
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
1       Bo                  Yang                CS                  28                  Microsoft
2       Calvin              Woo                 Physics             22                  Uber
3       Flo                 Yao                 CS                  20                  Google
4       Flo                 Jackson             Math                21                  Google
5       Greg                Pearson             Physics             20                  Amazon
6       Jim Bob             Smith               Math                23                  Verizon
7       Sammuel L.          Jackson             CS                  40                  Uber
8       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . .
89: select * from employee where last <= Peach
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Bo                  Chemistry           130000              2011
4       Jackson             Billy               Math                170000              2017
5       Johnson             Jack                HR                  150000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Johnson             Mary Ann            Math                165000              2014
8       Johnson             Billy Bob           Physics             142000              2014
9       Johnson             Billy               Phys Ed             102000              2014
SQL: DONE.

90: select * from employee where first <= Gary
record  last                first               dep                 salary              year

0       Jackson             Billy               Math                170000              2017
1       Jackson             Bo                  Chemistry           130000              2011
2       Jackson             Flo                 Math                165000              2017
3       Johnson             Billy               Phys Ed             102000              2014
4       Johnson             Billy Bob           Physics             142000              2014
5       Yang                Bo                  CS                  160000              2013
6       Yao                 Flo                 CS                  147000              2012
SQL: DONE.

91: select * from employee where salary <= 23500
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Bo                  Chemistry           130000              2011
3       Jackson             Flo                 Math                165000              2017
4       Jackson             Billy               Math                170000              2017
5       Johnson             Billy               Phys Ed             102000              2014
6       Johnson             Jimmy               Chemistry           140000              2018
7       Johnson             Billy Bob           Physics             142000              2014
8       Johnson             Jack                HR                  150000              2014
9       Johnson             Mary Ann            Math                165000              2014
10      Van Gogh            Jim Bob             Phys Ed             230000              2010
11      Yang                Bo                  CS                  160000              2013
12      Yao                 Jimmy               Math                145000              2014
13      Yao                 Flo                 CS                  147000              2012
SQL: DONE.

//****************************************************************************
//              LOGICAL OPERATORS
//****************************************************************************
//.................
//:AND            :
//.................
92: select * from student where fname = "Flo" and lname = "Yao"
record  fname               lname               major               age                 company

0       Flo                 Yao                 CS                  20                  Google
SQL: DONE.

93: select * from student where major = "CS" and age < 25
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
1       Flo                 Yao                 CS                  20                  Google
SQL: DONE.

94: select * from student where major < Math and age > 25
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Bo                  Yang                CS                  28                  Microsoft
2       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

95: select * from employee where dep = CS and salary > 150000
record  last                first               dep                 salary              year

0       Van Gogh            Vincent             CS                  245000              2015
1       Yang                Bo                  CS                  160000              2013
SQL: DONE.

96: select * from employee where last = Jackson and year < 2015
record  last                first               dep                 salary              year

0       Jackson             Bo                  Chemistry           130000              2011
SQL: DONE.

97: select * from employee where last = Johnson and year >=2014
record  last                first               dep                 salary              year

0       Johnson             Jack                HR                  150000              2014
1       Johnson             Jimmy               Chemistry           140000              2018
2       Johnson             Mary Ann            Math                165000              2014
3       Johnson             Billy Bob           Physics             142000              2014
4       Johnson             Billy               Phys Ed             102000              2014
SQL: DONE.

//.................
//:OR            :
//.................
98: select * from student where fname = Flo or lname = Jackson
record  fname               lname               major               age                 company

0       Flo                 Yao                 CS                  20                  Google
1       Flo                 Jackson             Math                21                  Google
2       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

99: select * from student where age >=40  or company = Verizon
record  fname               lname               major               age                 company

0       Alex                Smith               Gender Studies      53                  Amazon
1       Jim Bob             Smith               Math                23                  Verizon
2       Sammuel L.          Jackson             CS                  40                  Uber
3       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

100: select * from employee where first = Bo or last = Johnson
record  last                first               dep                 salary              year

0       Jackson             Bo                  Chemistry           130000              2011
1       Johnson             Jack                HR                  150000              2014
2       Johnson             Jimmy               Chemistry           140000              2018
3       Johnson             Mary Ann            Math                165000              2014
4       Johnson             Billy Bob           Physics             142000              2014
5       Johnson             Billy               Phys Ed             102000              2014
6       Yang                Bo                  CS                  160000              2013
SQL: DONE.

101: select * from employee where year >= 2015 or dep = CS
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Billy               Math                170000              2017
4       Johnson             Jimmy               Chemistry           140000              2018
5       Van Gogh            Vincent             Art                 240000              2015
6       Van Gogh            Vincent             CS                  245000              2015
7       Yang                Bo                  CS                  160000              2013
8       Yao                 Flo                 CS                  147000              2012
SQL: DONE.

//.................
//:OR AND         :
//.................
102: select * from student where fname = Flo or major = CS and age <= 23
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
1       Flo                 Yao                 CS                  20                  Google
2       Flo                 Jackson             Math                21                  Google
SQL: DONE.

103: select * from student where lname = Jackson or age < 23 and company > Uber
record  fname               lname               major               age                 company

0       Flo                 Jackson             Math                21                  Google
1       Sammuel L.          Jackson             CS                  40                  Uber
2       Teresa Mae          Gowers              Chemistry           22                  Verizon
SQL: DONE.

104: select * from employee where last = "Van Gogh" or last = Jackson and salary >= 165000
record  last                first               dep                 salary              year

0       Jackson             Flo                 Math                165000              2017
1       Jackson             Billy               Math                170000              2017
2       Van Gogh            Vincent             Art                 240000              2015
3       Van Gogh            Vincent             CS                  245000              2015
4       Van Gogh            Jim Bob             Phys Ed             230000              2010
SQL: DONE.

//.................
//:AND OR AND     :
//.................
105: select * from student where age <30 and major=CS or major = Physics and company = Amazon
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
1       Bo                  Yang                CS                  28                  Microsoft
2       Flo                 Yao                 CS                  20                  Google
3       Greg                Pearson             Physics             20                  Amazon
SQL: DONE.

106: select * from student where age <=40 and company=Uber or major = CS and company = Google
record  fname               lname               major               age                 company

0       Calvin              Woo                 Physics             22                  Uber
1       Flo                 Yao                 CS                  20                  Google
2       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

107: select * from employee where dep = CS and salary >= 160000 or year > 2014 and last = "Van Gogh"
record  last                first               dep                 salary              year

0       Van Gogh            Vincent             Art                 240000              2015
1       Van Gogh            Vincent             CS                  245000              2015
2       Yang                Bo                  CS                  160000              2013
SQL: DONE.

//.................
//:OR AND OR      :
//.................
108: select * from student where lname = Yang or major = CS and age < 23 or company = Google
record  fname               lname               major               age                 company

0       Anna Grace          Del Rio             CS                  22                  USAF
1       Bo                  Yang                CS                  28                  Microsoft
2       Flo                 Yao                 CS                  20                  Google
3       Flo                 Jackson             Math                21                  Google
SQL: DONE.

109: select * from student where major = Physics or major = Math and company = Google or lname = Jackson
record  fname               lname               major               age                 company

0       Calvin              Woo                 Physics             22                  Uber
1       Flo                 Jackson             Math                21                  Google
2       Greg                Pearson             Physics             20                  Amazon
3       Sammuel L.          Jackson             CS                  40                  Uber
SQL: DONE.

110: select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000
record  last                first               dep                 salary              year

0       Blow                Joe                 CS                  100000              2018
1       Blow                JoAnn               Physics             200000              2016
2       Jackson             Flo                 Math                165000              2017
3       Jackson             Billy               Math                170000              2017
4       Van Gogh            Vincent             Art                 240000              2015
5       Van Gogh            Vincent             CS                  245000              2015
6       Yang                Bo                  CS                  160000              2013
7       Yao                 Flo                 CS                  147000              2012
SQL: DONE.

SQL>exit
Press <RETURN> to close this window...
 */

#endif // Z_OUTPUT_H

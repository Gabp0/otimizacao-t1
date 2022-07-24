min: 0.005x1 + 0.005z1 + 0.2t1 + 0.005x2 + 0.005z2 + 0.2t2 + 0.005x3 + 0.005z3 + 0.2t3 + 0.005x4 + 0.005z4 + 0.2t4 + 0.005x5 + 0.005z5 + 0.2t5;

/* restricoes para a retirada do modulo */
x1 - z1 = 500 - h1;
x2 - z2 = 500 - h2;
x3 - z3 = 500 - h3;
x4 - z4 = 500 - h4;
x5 - z5 = 500 - h5;

/* volume do mes atual */
v1 = 500 + 500;
v2 = v1 + 500 - h1;
v3 = v2 + 500 - h2;
v4 = v3 + 500 - h3;
v5 = v4 + 500 - h4;

/* restricoes para o volume minimo e maximo da hidroeletrica */
v1 - h1 <= 1000;
v2 - h2 <= 1000;
v3 - h3 <= 1000;
v4 - h4 <= 1000;
v5 - h5 <= 1000;

v1 - h1 >= 200;
v2 - h2 >= 200;
v3 - h3 >= 200;
v4 - h4 >= 200;
v5 - h5 >= 200;

/* restricoes para o consumo maximo de agua */
h1 <= v1;
h2 <= v2;
h3 <= v3;
h4 <= v4;
h5 <= v5;

/* demanda minima de energia */
2.0h1 + t1 >= 1000;
2.0h2 + t2 >= 1000;
2.0h3 + t3 >= 1000;
2.0h4 + t4 >= 1000;
2.0h5 + t5 >= 1000;

/* geracao maxima da termoeletrica */
t1 <= 1000;
t2 <= 1000;
t3 <= 1000;
t4 <= 1000;
t5 <= 1000;

/* restricoes de nao negativade */
x1 >= 0;
x2 >= 0;
x3 >= 0;
x4 >= 0;
x5 >= 0;
z1 >= 0;
z2 >= 0;
z3 >= 0;
z4 >= 0;
z5 >= 0;
h1 >= 0;
h2 >= 0;
h3 >= 0;
h4 >= 0;
h5 >= 0;
t1 >= 0;
t2 >= 0;
t3 >= 0;
t4 >= 0;
t5 >= 0;

Consumo_agua_mes_1 = h1;
Consumo_agua_mes_2 = h2;
Consumo_agua_mes_3 = h3;
Consumo_agua_mes_4 = h4;
Consumo_agua_mes_5 = h5;

Geracao_termoeletrica_mes_1 = t1;
Geracao_termoeletrica_mes_2 = t2;
Geracao_termoeletrica_mes_3 = t3;
Geracao_termoeletrica_mes_4 = t4;
Geracao_termoeletrica_mes_5 = t5;
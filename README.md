# Compilação

- O comando **make** gera o executável **despacho**
- A flag **clean** remove os arquivos **.o**
- A flag **purge** remove os arquivos **.o** e o executável **despacho**

# Execução

- **./despacho** lê da entrada padrão *stdin* e escreve no arquivo de saída **lp_output.txt**
- **./despacho [entrada]** lê do arquivo passado como argumento e escreve no arquivo de saída **lp_output.txt**

# Formato da entrada

**[número de meses]** <br>
**[demanda em cada um dos meses]** <br>
**[afluência em cada um dos meses]**  <br>
**[volume inicial] [volume minímo] [volume máximo] [coeficiente de geração]**<br>
**[custo de geracao]** <br>
**[custo ambiental]** <br>

## Exemplos

Para um período de **3** meses; com as demandas de **900**, **1000** e **950**; afluências de **500**, **800** e **200**; volume inicial da hidroelétrica de **500**; volume minímo de **200**; volume máximo de **1000**; coeficiente de geração da hidroelétrica de **1.1**; geração máxima da termoeletrica de **1000**; custo de geração da termoelétrica de **0.2**; custo ambiental da hidroelétrica de **0.005**, temos a entrada de:

**3 <br>
900 1000 950 <br>
500 800 200 <br>
500 200 1000 1.1 <br>
1000 0.2 <br>
0.005 <br>**

A qual gera no arquivo de saída **lp_output.txt**:

<div>
min: 0.005x1 + 0.005z1 + 0.2t1 + 0.005x2 + 0.005z2 + 0.2t2 + 0.005x3 + 0.005z3 + 0.2t3;<br>
<br>
/* restricoes para a retirada do modulo */ <br>
x1 - z1 = 500 - h1;<br>
x2 - z2 = 800 - h2;<br>
x3 - z3 = 200 - h3;<br>
<br>
/* volume do mes atual */<br>
v1 = 500 + 500;<br>
v2 = v1 + 800 - h1;<br>
v3 = v2 + 200 - h2;<br>
<br>
/* restricoes para o volume minimo e maximo da hidroeletrica */<br>
v1 - h1 <= 1000;<br>
v2 - h2 <= 1000;<br>
v3 - h3 <= 1000;<br>
v1 - h1 >= 200;<br>
v2 - h2 >= 200;<br>
v3 - h3 >= 200;<br>
<br>
/* restricoes para o consumo maximo de agua */<br>
h1 <= v1;<br>
h2 <= v2;<br>
h3 <= v3;<br>
<br>
/* geracao maxima da termoeletrica */<br>
t1 <= 1000;<br>
t2 <= 1000;<br>
t3 <= 1000;<br>
<br>
/* demanda minima de energia */<br>
1.1h1 + t1 >= 900;<br>
1.1h2 + t2 >= 1000;<br>
1.1h3 + t3 >= 950;<br>
<br>
/* restricoes de nao negativade */<br>
x1 >= 0;<br>
z1 >= 0;<br>
h1 >= 0;<br>
t1 >= 0;<br>
x2 >= 0;<br>
z2 >= 0;<br>
h2 >= 0;<br>
t2 >= 0;<br>
x3 >= 0;<br>
z3 >= 0;<br>
h3 >= 0;<br>
t3 >= 0;<br>
<br>
<br>
Consumo_agua_mes_1 = h1;<br>
Geracao_termo_mes_1 = t1;<br>
Consumo_agua_mes_2 = h2;<br>
Geracao_termo_mes_2 = t2;<br>
Consumo_agua_mes_3 = h3;<br>
Geracao_termo_mes_3 = t3; <br>
<div>


Para um período de **4** meses; com as demandas de **900**, **1000** e **950**; nenhuma afluência durante os meses; volume inicial da hidroelétrica de **500**; volume minímo de **500**; volume máximo de **1000**; coeficiente de geração da hidroelétrica de **1.1**; geração máxima da termoeletrica de **1000**; custo de geração da termoelétrica de **0.2**; custo ambiental da hidroelétrica de **0.005**, temos a entrada de:

**3 <br>
900 1000 950 <br>
0 0 0 <br>
500 200 1000 1.1 <br>
1000 0.2 <br>
0.005 <br>**

A qual gera no arquivo de saída **lp_output.txt**:

<div>
min: 0.005x1 + 0.005z1 + 0.2t1 + 0.005x2 + 0.005z2 + 0.2t2 + 0.005x3 + 0.005z3 + 0.2t3;<br>
<br>
/* restricoes para a retirada do modulo */<br>
x1 - z1 = 0 - h1;<br>
x2 - z2 = 0 - h2;<br>
x3 - z3 = 0 - h3;<br>
<br>
/* volume do mes atual */<br>
v1 = 500 + 0;<br>
v2 = v1 + 0 - h1;<br>
v3 = v2 + 0 - h2;<br>
<br>
/* restricoes para o volume minimo e maximo da hidroeletrica */<br>
v1 - h1 <= 1000;<br>
v2 - h2 <= 1000;<br>
v3 - h3 <= 1000;<br>
v1 - h1 >= 500;<br>
v2 - h2 >= 500;<br>
v3 - h3 >= 500;<br>
<br>
/* restricoes para o consumo maximo de agua */<br>
h1 <= v1;<br>
h2 <= v2;<br>
h3 <= v3;<br>
<br>
/* geracao maxima da termoeletrica */<br>
t1 <= 1000;<br>
t2 <= 1000;<br>
t3 <= 1000;<br>
<br>
/* demanda minima de energia */<br>
1.1h1 + t1 >= 900;<br>
1.1h2 + t2 >= 1000;<br>
1.1h3 + t3 >= 950;<br>
<br>
/* restricoes de nao negativade */<br>
x1 >= 0;<br>
z1 >= 0;<br>
h1 >= 0;<br>
t1 >= 0;<br>
x2 >= 0;<br>
z2 >= 0;<br>
h2 >= 0;<br>
t2 >= 0;<br>
x3 >= 0;<br>
z3 >= 0;<br>
h3 >= 0;<br>
t3 >= 0;<br>
<br>
<br>
Consumo_agua_mes_1 = h1;<br>
Geracao_termo_mes_1 = t1;<br>
Consumo_agua_mes_2 = h2;<br>
Geracao_termo_mes_2 = t2;<br>
Consumo_agua_mes_3 = h3;<br>
Geracao_termo_mes_3 = t3;<br>
<div>
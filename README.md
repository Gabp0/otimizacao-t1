# Compilação

- O comando **make** gera o executável **lp_gen**
- A flag **clean** remove os arquivos **.o**
- A flag **purge** remove os arquivos **.o** e o executável **lp_gen**

# Execução

- **./lp_gen** lê da entrada padrão *stdin* e escreve no arquivo de saída **lp_output.txt**
- **./lp_gen [entrada]** lê do arquivo passado como argumento e escreve no arquivo de saída **lp_output.txt**

# Formato da entrada

**[número de meses]** <br>
**[demanda em cada um dos meses]** <br>
**[afluência em cada um dos meses]**  <br>
**[volume inicial] [volume minímo] [volume máximo] [coeficiente de geração]**<br>
**[custo de geracao]** <br>
**[custo ambiental]** <br>

## Exemplo

Para um período de **3** meses; com as demandas de **900**, **1000** e **950**; afluências de **500**, **800** e **200**; volume inicial da hidroelétrica de **500**; volume minímo de **200**; volume máximo de **1000**; coeficiente de geração da hidroelétrica de **1.1**; geração máxima da termoeletrica de **1000**; custo de geração da termoelétrica de **0.2**; custo ambiental da hidroelétrica de **0.005**, temos a entrada de:

**3 <br>
900 1000 950 <br>
500 800 200 <br>
500 200 1000 1.1 <br>
1000 0.2 <br>
0.005 <br>**

A qual gera no arquivo de saída **lp_output.txt**:


min: 0.005x1 + 0.005z1 + 0.2t1 + 0.005x2 + 0.005z2 + 0.2t2 + 0.005x3 + 0.005z3 + 0.2t3;

/* restricoes para a retirada do modulo */
x1 - z1 = 500 - h1;
x2 - z2 = 800 - h2;
x3 - z3 = 200 - h3;

/* volume do mes atual */
v1 = 500 + 500;
v2 = v1 + 800 - h1;
v3 = v2 + 200 - h2;

/* restricoes para o volume minimo e maximo da hidroeletrica */
v1 - h1 <= 1000;
v2 - h2 <= 1000;
v3 - h3 <= 1000;
v1 - h1 >= 200;
v2 - h2 >= 200;
v3 - h3 >= 200;

/* restricoes para o consumo maximo de agua */
h1 <= v1;
h2 <= v2;
h3 <= v3;

/* geracao maxima da termoeletrica */
t1 <= 1000;
t2 <= 1000;
t3 <= 1000;

/* demanda minima de energia */
1.1h1 + t1 >= 900;
1.1h2 + t2 >= 1000;
1.1h3 + t3 >= 950;

/* restricoes de nao negativade */
x1 >= 0;
z1 >= 0;
h1 >= 0;
t1 >= 0;
x2 >= 0;
z2 >= 0;
h2 >= 0;
t2 >= 0;
x3 >= 0;
z3 >= 0;
h3 >= 0;
t3 >= 0;


Consumo_agua_mes_1 = h1;
Geracao_termo_mes_1 = t1;
Consumo_agua_mes_2 = h2;
Geracao_termo_mes_2 = t2;
Consumo_agua_mes_3 = h3;
Geracao_termo_mes_3 = t3; 

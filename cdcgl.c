

void jogo()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30.0, 30., -30.00, 30.0,1,100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);


	// este switch decide qual "cena" sera desenhada na tela
	switch(seletor_tela)
	{
		// tela inicial, contem o prologo do jogo
		case -2:

			{char prologo[3][350]=
			{
				"A CIDADELA DO CAOS",

				"Nas profundezas da Cidadela do Caos, o terrivel feiticeiro Balthus Dire esta conspirando e planejando a derrocada do povo generoso do Vale dos Homossexuais. Seus planos de combate estao prontos, seu exercito assustador equipado, e o ataque e indiscutivelmente iminente.",

				"Convocado por uma suplica desesperada de ajuda, voce e a unica esperanca do Vale dos Homossexuais. Aluno brilhante do Grande Mago de Yore e um mestre da magia, so voce pode empreender uma missao que atinja o proprio coracao do mundo de pesadelo de Balthus Dire. Que criaturas monstruosas esperam por voce la, poc?"};

			glColor3f(0.0, 0.0, 0.5);
			// Mostra as strings em 'prologo' uma a uma na tela
			if(anima>-1)
			{
				escritoura(prologo[0], GRANDE_X, 28.0, vetorcor1, vetorcor2);
			}
			if(anima>0)
			{
				escritoura(prologo[1], GRANDE_X, 26.0, vetorcor1, vetorcor2);
			}
			if(anima>1)
			{
				escritoura(prologo[2], GRANDE_X, 20.0, vetorcor1, vetorcor2);
			}
			// Quando todas as strings são mostradas, a próxima tela sera exibida e a variável limite é alterada pra fornecer as 13 opções possíveis
			if(anima==3)
			{
				anima=-40.0;
				seletor_teclado=2;
				troca_tela(-1);
			}
		break;}
	


		/* tela de escolha de magias. Podemos listar apenas os nomes das magias e dar a opção de pedir detalhes */



		case -1:
		{
			char escolha_de_magias[]={"Escolha suas magias. Voce tem direito a 00 magias, pressione ENTER selecionar a magia e DELETE para exclui-la:@1-Cópia de Criatura: Faz uma replica perfeita de qualquer criatura contra a qual voce esteja lutando. A replica tera os mesmos poderes do orignal, mas estara sob seu controle@2-Percepcao Extra-Sensorial: Sintoniza ondas psiquicas. Isso podera ajuda-lo a ler a mente de uma criatura ou descobrir o que esta por tras de uma porta trancada. Mas este encanto pode dar informacoes equivokdas, se houver + de a font psikica perto de uma outra.@3-Fogo: Tds as criaturas tm medo d fogo, e ste enknto da o podr d fazr aparecr fogo o sua vontad. Vc pdera causr a pkena xplosao n chao q keimara pr varios os ou criar a brreira d fogo p mantr criaturas a dstancia.@4-Ouro dos Tolos: Trnsforma pdra comum em a plha do q parece sr ouro. Mas eh apnas a ilusao - embora + confiavl q o Enknto d ilusao abaixo - e a plha d ouro logo voltara a sr pdra.@5-Ilusao: Ste e  enknto podroso, mas q n e mto confiavl. Prmit criar a ilusao convncnte (pr exemplo, q o chao sta cobrto d krvao em brasa) p enganr a criatura. O enknto fikra imediatamnt sm efeito s acontcr qlqr coisa q dsfaca a ilusao (pr exemplo, vc convnc a criatura q s trnsformou em a serpnt e entao imediatamnt atnge sua kbca c  golp d spada!). e efcient sbre td c criaturas intlignts.@6-Levitacao: Vc pde lancr ste enknto sbre objtos, advrsarios ou ate sbre si msm. Fara cm q tdo q estja sob sua influencia flutue livremnt no ar, sob o seu cntrole.@7-Escudo: Cria um scudo invsivl à sua frent q o protgera d objtos fsicos, cm flechas, spadas ou criaturas. O scudo n tm efeito cntra a magia e, evdntmnte, s nd fora dle pod tokr em vc, vc tbm n podra tokr em nd fora dle.@8-Sorte: Este enknto e spcial pq pod sr lancado a qlqr momnto durante a sua avntura, a n sr durant a batalha. a vz lancado, recuperara o seu indce d SORTE em metad d seu indce d SORTE Inicial, arredondado p baixo. Ste enknto nunk lvara o seu indce d SORTE a  nmro suprior a seu nivl Inicial.@9-Habilidade: Restabelecera o seu indce d HABILIDADE. Funciona exatamnt cm o enknto d Sort.@10-Energia: Recuperara o seu indce d Energia, aumentando-o em metad d seu vlr Inicial. Funciona cmo o enknto d Sort@11-Forca: Ste enknto tm o efeito d aumentr mto a sua frca, e e mto utl qnd s luta cntra criaturas forts. Porm, dv sr utlizado c cautla, ja q e dfcil controlr a sua prpria frca qnd ela aumnta d+@12-Fraqueza: N tm efeito cntra tds as criatras, ms qnd tm, a criatra s trna fragl e mto mnos prigosa em a btalha@Finalizar"};

		/* ESCREVENDO NA STRING 'escolha_de_magias' A QUANTIDADE DE MAGIAS QUE USUÁRIO TEM DIREITO */

		int substituidor=0;

		while(escolha_de_magias[substituidor]!='0')
		{
			substituidor++;
		}

		if(magia<10)
		{
			escolha_de_magias[substituidor+1]=(char)(magia+48);
		}
		else
		{
			escolha_de_magias[substituidor]='1';
			escolha_de_magias[substituidor+1]=(char)(magia+38);
		}

			glTranslatef(0.0, translacao, 0.0);/* serve para subir o texto na tela de magias*/
			escritoura(escolha_de_magias, GRANDE_X, 28.0, vetorcor1, vetorcor2);

			glLoadIdentity();
			glTranslatef(0.0, 0.0, -5.0);

	
			/* ESTE TRECHO DESENHARA UMA AREA NA TELA QUE MOSTRARA AO USUARIO QUAIS MAGIAS ELE JA ESCOLHEU */
			glColor3f(1.0, 0.549, 0.0);
			glBegin(GL_POLYGON);
				glVertex3d(-25.0, -12.0, 0.0);
				glVertex3d(30.0, -12.0, 0.0);
				glVertex3d(30.0, -30.0, 0.0);
				glVertex3d(-25.0, -30.0, 0.0);
			glEnd();
	
			float coluna= -24.0, linha=-14.0; int seis=0, i=0;

			// Desenha as magias escolhidas na tela
			for(; i<18; i++)
			{
				// Quando o último encanto registrado é escrito, o laço para
				if(*ponteiro_encantos==0)
				{
					break;
				}
				// Conta quantos feitiços já foram escritos na tela, a cada seis feitiços, se inicia uma nova coluna e linha retorna para o topo da coluna
				if(seis==6)
				{
					linha=-14.0;
					coluna=coluna+10.0;
					seis=0;
				}
				// escreve as magias na tela, usando a matriz 'lista_de_magias'. 'ponteiro_encantos' aponta para uma das posições do veotr encantos, onde estão armazenados valores da variável 'seletor'. No caso da listagem de magias, esses valores vão de 1 a 12, e se relacionam com cada uma das magias listadas em 'lista_de_magias', na ordem em que aparecem na matriz. Como essas posições da matriz vão de zero a 11, é necessário subtrair 1 de cada valor encontrado na posição apontada por 'ponteiro_encantos' para indexar adequadamente a matriz 'lista_de_magias'. 'linha' é decrementada e o próximo feitiço será escrito abaixo do anterior
				escritoura(lista_de_magias[*ponteiro_encantos-1], coluna, linha, vetorcor1, vetorcor2);
				ponteiro_encantos++;
				linha--;
				seis++;
			}
		}
		break;

		case 0://tela com a introducao da historia
		{
			char introducao[5000]=
			{
				"O ordeiro e generoso povo do Vale dos Salgueiros vive há oito anos sob o terror e medo do feiticeiro Balthus Dire. Terror – porque o poder dele é realmente aterrorizante - e medo causados pela notícia que acabou chegando aos ouvidos desse povo, vinda dos domínios do feiticeiro, de que seus ambiciosos planos de conquista começariam pelo próprio Vale.@Um fiel Semi-Elfo enviado em uma missão de espionagem à Torre Negra voltou galopando para o Vale há três dias com uma mensagem desesperada. Do interior das cavernas de Rocha Escarpada, Balthus Dire tinha recrutado um exército de Caóticos e se preparava para atacar com eles o Vale dentro de uma semana.@O bom Rei Salamon era um homem de ação. Foram enviados mensageiros por todo o Vale no mesmo dia para preparar as defesas e convocar os homens para a guerra. Foram enviados também cavaleiros à Grande Floresta de Yore para avisar aos Semi-Elfos que moravam lá e fazer um apelo para que se aliassem às forças. O Rei Salamon era também um homem sábio. Ele sabia muito bem que as notícias inevitavelmente chegariam aos ouvidos do Grande Mago de Yore, um mestre da magia branca de grandes poderes, que vivia nas profundezas da floresta.@O mago era velho e não resistiria a uma batalha destas proporções. Mas ele havia ensinado suas artes a vários jovens magos, e talvez um de seus discípulos de magia ajudasse o rei e seus súditos com coragem e ambição. Você é o aluno brilhante do Grande Mago de Yore. Ele tem sido um Mestre duro, e sua própria impaciência muitas vezes foi mais forte do que você. Talvez um pouco precipitadamente, vocêpartiu de imediato para a corte de Salamon.@O rei recebeu-o entusiasticamente e explicou seu plano. A batalha poderia ser evitada sem derramamento de sangue se Balthus fosse assassinado antes que seu exército pudesse ser reunido. A missão que você tem pela frente é extremamente perigosa. Balthus Dire está cercado, em sua Cidadela, por uma multidão de criaturas assombrosas. Embora a Magia seja a sua arma mais forte, haverá momentos em que você terá que confiar em sua espada para sobreviver.@O Rei Salamon expôs a você como seria a sua missão e o advertiu dos perigos que estavam à sua frente. Há um caminho melhor para atravessar a Cidadela. Se você o descobrir, terá êxito com um mínimo de risco para a sua pessoa. Talvez você precise de várias viagens para descobrir o caminho mais fácil para atravessar a Cidadela.@Você deixa o Vale dos Salgueiros na longa caminhada para a Torre Negra. No sopé da colina de Rocha Escarpada, você pode ver sua silhueta contra o céu escuro..."};
			// inicia a animação desta tela. Os texto vai subindo no visor

			
			glTranslatef(0.0, anima, 0.0);
			escritoura(introducao, GRANDE_X, 28.0, vetorcor1, vetorcor2);

			if(anima==-40.0)
			{
				glutTimerFunc(16, animacao, 1);
			}
			// encerra animação
			if(anima>=80)
			{
				resolver_etapa=0;// 'resolver_etapa' é zerada para evitar que a próxima tela não seja desenhada
				troca_tela(1);
			}
		}
		break;

		case 1:
		{

			// altera o número de escolhas do usuário e coloca a variável 'seletor' de volta para a primeira opção
			limite=3;
			char paragrafo_1[2000]={"O sol se põe. Enquanto o crepúsculo se transforma em escuridão, você começa a subir a colina na direção da ameaçadora forma que se desenha contra o céu noturno. A Cidadela fica a menos de uma hora de escalada. A uma certa distância de seus muros, você pára para descansar - um erro, uma vez que, dessa posição, ela parece um espectro medonho do qual não se pode escapar. Os cabelos no seu pescoço se arrepiam enquanto você a observa. Mas você se envergonha de seus medos. Com inflexível decisão, você marcha adiante na direção do portão principal, onde você sabe que encontrará guardas à sua espera. Você considera suas opções. Já pensou em se apresentar como um especialista em plantas medicinais que veio tratar de um guarda com febre. Poderia também se dizer um comerciante ou artesão - talvez um carpinteiro. Poderia até mesmo ser um nômade que buscasse abrigo para a noite. Enquanto você pondera as possibilidades, e as histórias que terá que contar aos guardas, acaba chegando à trilha principal que conduz aos portões. Duas lanternas brilham em cada um dos lados da porta levadiça.Você ouve grunhidos abafados ao se aproximar, e vê duas criaturas de aparência absurda. Do lado esquerdo está uma criatura horrível, com a cabeça de um cachorro e o corpo de um grande macaco, flexionando seus braços fortíssimos. Do outro lado, encontra-se de fato o seu oposto, com a cabeça de um macaco no corpo de um cachorro grande. Este último guarda se aproxima nas suas quatro patas. Pára a alguns metros de distância diante de você, ergue-se sobre as patas traseiras e dirige a palavra a você. Por qual das histórias você optará?\
\
@1-Você se apresentará como um especialista em plantas medicinais?\
@2-Você dirá que é um comerciante?\
@3-Você pedirá abrigo para pernoitar?"}; /* a string paragrafo_1 termina aqui */

			escritoura(paragrafo_1, GRANDE_X, 28.0, vetorcor1, vetorcor2);
			
			if(resolver_etapa)
			{
				switch (seletor)
				{
					case 1:
						troca_tela(261);
					break;

					case 2:
						troca_tela(230);
					break;

					case 3:
						troca_tela(20);
					break;
				}
			}
		}
		break;// case 1

		case 20:
		{
			limite=2;
			char paragrafo_20 [500]={"O Macaco-Cachorro diz que não é permitido a ninguém entrar na Torre Negra depois que anoitece - você terá que procurar abrigo em outro lugar. Você pode:\
		@1-Lutar\
		@2-Pegar uma pedra e lançar um Encanto do Ouro dos Tolos sobre ela, oferecendo-a como uma pepita de ouro, para suborná-los, convencendo-os a deixar você entrar"};

			escritoura(paragrafo_20, GRANDE_X, GRANDE_Y, vetorcor1, vetorcor2);

			if(resolver_etapa)
			{
				switch(seletor)
				{
					case 1:
						troca_tela(288);
						anima=0;//sempre que uma funcao envolvendo animacao corre o risco de ser chamada, essa variavel e zerada
					break;
	
					case 2:
					{
						usar_magia(4, 96);
					}
					break;
				}
			}
		}
		break;//case 20

		case 96:
		{
			limite=1;
			char paragrafo_96 [500]={"Eles aceitam a sua oferta e convocam o porteiro, que abre uma pequena porta dentro da porta levadiça para deixar você entrar. Você os deixa discutindo por causa da pepita de ouro.\
					@Continuar"};

			escritoura(paragrafo_96, GRANDE_X, GRANDE_Y, vetorcor1, vetorcor2);

			if(resolver_tela)
			{
				troca_tela(251);
			}

		}
		break;// case 96

		case 125:
		{
			limite=1;
			char paragrafo_125 [500]={"Quando você começa a correr, três flechas partem na sua direção, vindas de nenhum lugar. Teste a sua Sorte. Se tiver sorte, todas elas erram o alvo, e você chega até o monumento e se abaixa atrás da pedra. Se não tiver sorte, uma das flechas penetra em seu ombro, fazendo com que você perca cinco pontos de ENERGIA antes de chegar ao abrigo do monumento. Vá para 209\
							@Testar sorte"};

			escritoura(paragrafo_125, GRANDE_X, GRANDE_Y, vetorcor1, vetorcor2);

			if(resolver_etapa)
			{
				int teste=testar_sorte();
				if(!teste)
				{
					enrg_atual-=5;
				}
				seletor=1;
				resolver_etapa=0;
				seletor_tela=209;// troca_tela nao e chamada para evitar que a mensagem de sorte nao seja exibida. De novo, a chamada a glutPostRedisplay na funcao 'aviso' garante a mudanca da tela
			}
		}
		break;// case 125

		case 156:
		{
			limite=3;
			char paragrafo_156 [1000]={"Enquanto você caminha pelo pátio ao ar livre, repara que está andando ao longo de uma pequena elevação, quase que como um encanamento enterrado que fosse da Torre Negra para o templo. Você se abaixa para investigar isso; poderia ter sido feito por algum tipo de toupeira? Quando você toca na elevação, ela se retrai e, para seu horror, um longo tentáculo cinzento irrompe do solo e se enrosca em torno de sua perna! Como você lutará contra esta \"coisa\":\
							@1-Desembainhará a sua espada?(71)\
							@2-Lançará um Encanto da Levitação?(284)\
							@3-Lançará um Encanto do Fogo?(114)"};
			if(resolver_tela)
			{
				switch(seletor)
				{
					case 1:
						troca_tela(71);
					break;

					case 2:
						usar_magia(6, 284);
					break;

					case 3:
						usar_magia(3, 114);
					break;
				}
			}

		}
		break;// case 156

		case 179:
		{
			limite=
			char paragrafo_179 [1000]={"Quando você sai das sombras na direção do centro do pátio, uma voz no vento grita: \"Pare! Fique onde está!\". Você olha à sua volta, mas não consegue ver ninguém que esteja se dirigindo a você. Você dá mais dois passos. A voz sinistra ordena de novo que você pare, e dessa vez uma flecha zune pelo ar e cai próximo a seu pé esquerdo. Você pula para trás. Mas ainda assim não vê ninguém. Porém, não pode se mexer. Você:\
							@1-Seguirá adiante, muito cuidadosamente?\
							@2-Disparará na direção do monumento, no centro do pátio?\
							@3-Lançará um Encanto do Escudo à sua volta e seguirá avançando?"};

			escritoura(paragrafo_96, GRANDE_X, GRANDE_Y, vetorcor1, vetorcor2);

			if(resolver_tela)
			{
				switch(seletor)
				{
					case 1:
						troca_tela(378);
					break;

					case 2:
						troca_tela(125);
					break;

					case 3:
						usar_magia(7, 341);
					break;
				}
			}

		}
		break;// case 179

		case 209:
		{
			limite=2;
			char paragrafo_209 [500]={"Você pousa os olhos sobre a estranha estrutura. Não parece ser uma fonte, mas alguma espécie de templo. De um lado há uma porta, que você pode investigar, ou você poderá também seguir em frente para a Cidadela propriamente dita.\
						@1-Ir em frente (156).\
						@2-Se quiser investigar(362)"};

			if(resolver_etapa)
			{
				switch(seletor)
				{
					case 1:
						troca_tela(156);
					break;

					case 2:
						troca_tela(362);
					break;
				}
			}
		}
		break;// case 209

		case 251:
		{
			limite=3;
			char paragrafo_251 [500]={"Você caminha em frente, entrando em um pátio aberto e espaçoso, circundado por grandes muros. Há várias tochas queimando, e grupos de figuras se movimentam na escuridão. Há um monumento de algum tipo no centro do pátio - talvez uma fonte. Olhando para o outro lado do pátio, você consegue ver o que parece ser a entrada principal da torre. Você:\
						@1-Esgueira-se pela parede na direção da torre, contornando o pátio?\
						@2-Caminha decididamente, atravessando o pátio?\
						@3-Vai na ponta dos pés pelas sombras, na direção de um dos grupos?"};

			escritoura(paragrafo_96, GRANDE_X, GRANDE_Y, vetorcor1, vetorcor2);

			if(resolver_etapa)
			{
				switch(seletor)
				{
					case 1:
						troca_tela(222);
					break;

					case 2:
						troca_tela=(179);
					break;

					case 3:
						troca_tela(321);
					break;
				}
			}
		}
		break;// case 251



	}// o switch principal termina aqui



	


		

	glFlush();

}



int main(int argc, char **argv)
{
	/*GERANDO HABILIDADE, ENERGIA, MAGIA E SORTE */

	magia=d6();
	hab=d6()+6;
	enrg=d6()+d6()+12;
	magia=magia+d6()+6;
	sort=d6()+6;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000,700);
	glutCreateWindow("Alo!");
	glutDisplayFunc(jogo);
	glutKeyboardFunc(teclado_2);
	glutSpecialFunc(teclado);
	glutTimerFunc(2000, animacao, 0);
	glutMainLoop();
}

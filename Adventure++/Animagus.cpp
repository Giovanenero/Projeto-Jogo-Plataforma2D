#include "Animagus.h"

#define VELOCIDADE_ANIMAGUS_X 80.0f
#define PONTUACAO_ANIMAGUS 5000
#define CARREGAR_TOMAR_DANO_ANIMAGUS 0.5f
#define CARREGAR_MORRER_ANIMAGUS 0.55f
#define CARREGAR_ATAQUE_ANIMAGUS 2.5f
#define TEMPO_ATAQUE_ANIMAGUS 0.5f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Animagus::Animagus(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo) :
                Chefao(posInicio, pOriana, pHideo, Ids::Ids::animagus)
            {
                this->inicializacao();
            }
            Animagus::~Animagus() { }

            void Animagus::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusAndando.png", 8, Ids::Ids::animagus_anda, tamanho, Matematica::CoordenadaF(3.2f, 1.5f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusAtacando1.png", 8, Ids::Ids::animagus_ataca1, tamanho, Matematica::CoordenadaF(2.5f, 3.45f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusAtacando2.png", 8, Ids::Ids::animagus_ataca2, tamanho, Matematica::CoordenadaF(3.2f, 3.45f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusDano.png", 3, Ids::Ids::animagus_tomaDano, tamanho, Matematica::CoordenadaF(3.4f, 1.45f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusMorrendo.png", 7, Ids::Ids::animagus_morre, tamanho, Matematica::CoordenadaF(3.1f, 3.75f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Animagus/animagusParado.png", 8, Ids::Ids::animagus_para, tamanho, Matematica::CoordenadaF(3.1f, 3.65f));
				carregarTomarDano = CARREGAR_TOMAR_DANO_ANIMAGUS;
				carregarMorrer = CARREGAR_MORRER_ANIMAGUS;
				carregarAtaque = CARREGAR_ATAQUE_ANIMAGUS;
				tempoAtaque = TEMPO_ATAQUE_ANIMAGUS;
            }

            void Animagus::atualizarImagem(const float tempo) {
				if (morrer) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::animagus_morre);
					carregandoMorrendo += tempo;
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.5f, Ids::Ids::animagus_tomaDano);
					carregaTomarDano(tempo);
				}
				else if (atacando) {
					if (mudarAtaque == 0) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_ataca1);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_ataca2);
					}
					desligarAtacar();
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::animagus_para);
					mudarAtaque = rand() % 2;
				}
            }

			const float Animagus::getVelocidadeEspecifica() const {
				return VELOCIDADE_ANIMAGUS_X;
			}

			const short Animagus::getPontuacao() const {
				return PONTUACAO_ANIMAGUS;
			}
        }
    }
}
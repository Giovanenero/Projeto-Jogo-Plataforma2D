#pragma once
#include "Personagem.h"
#include "Oriana.h"
#include "Hideo.h"

#include <time.h>

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			class Inimigo : public Personagem
			{
			protected:
				Jogador::Oriana* pOriana;
				Jogador::Hideo* pHideo;
				const Matematica::CoordenadaF distanciaJogador;
				unsigned int contAleatorio;
				short aleatorio;
			public:
				Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Matematica::CoordenadaF distanciaJogador, const int vida, const int dano);
				~Inimigo();

				const Matematica::CoordenadaF getDistanciaJogador();
				void colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade);
				void movimentoAleatorio(const float tempo);
                void setJogadores(Jogador::Oriana *pOriana, Jogador::Hideo *pHideo);
                const bool perseguirJogadores(const float tempo);
				const bool perseguirJogador(Jogador::Jogador* pJogador, const float tempo);
				virtual void atualizar(const float tempo);

				virtual const short getPontuacao() const = 0;
				virtual const float getVelocidadeEspecifica() const = 0;
				virtual void atualizarImagem(const float tempo) = 0;
			};
		} //namespace Inimigo
	} //namespace Personagem
} //namespace Entidade


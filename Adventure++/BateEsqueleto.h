#pragma once

#include "Esqueleto.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			class BateEsqueleto: public Esqueleto
			{
			private:
				short mudarAtaque;
			public:
				BateEsqueleto(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo);
				~BateEsqueleto();
				void inicializacao();
				void atualizarImagem(const float tempo);
				const short getPontuacao() const;
			};
		}
	}
}


#pragma once

#include "Goblin.h"
#include "Atirador.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class AtiraGoblin: public Goblin, public Atirador
            {
            public:
                AtiraGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Lista::ListaEntidade* ListaEntidadeMovimento);
                ~AtiraGoblin();
                void inicializacao();
                void atualizar(const float tempo);
                void atualizarImagem(const float tempo);
                const short getPontuacao() const;
            };
        }
    }
}


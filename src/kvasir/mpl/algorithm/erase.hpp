//          Copyright Odin Holmes 2017.
// Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once
#include "rotate.hpp"
#include "../functional/call.hpp"
#include "../sequence/pop_front.hpp"
#include "../sequence/size.hpp"
#include "../types/int.hpp"

namespace kvasir {
	namespace mpl {
		template <typename Index, typename C = listify>
		struct erase {
			template <typename... Ts>
			using f = typename rotate<
			        Index, pop_front<rotate<mpl::uint_<(sizeof...(Ts)-Index::value - 1)>, C>>>::
			        template f<Ts...>;
		};
		namespace eager {
			template <typename List, unsigned Index>
			using erase = call<unpack<mpl::erase<uint_<Index>>>, List>;
		}
	}
}

//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/algorithm/flatten.hpp>
#include <kvasir/mpl/types/list.hpp>

namespace flatten_test {
	namespace mpl = kvasir::mpl;
	static_assert(std::is_same<
		              mpl::eager::flatten<mpl::list<mpl::list<float>, mpl::list<int>>>, mpl::list<float, int>>{},
	              "flatten test failed");
}

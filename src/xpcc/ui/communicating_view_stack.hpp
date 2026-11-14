/*
 * Copyright (c) 2009, Martin Rosekeit
 * Copyright (c) 2009-2012, Fabian Greif
 * Copyright (c) 2011, Georgi Grinshpun
 * Copyright (c) 2012, Sascha Schade
 * Copyright (c) 2012-2013, 2017-2018, Niklas Hauser
 * Copyright (c) 2013, Kevin Läufer
 * Copyright (c) 2013, Thorsten Lajewski
 * Copyright (c) 2020, Matthew Arnold
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef XPCC_COMMUNICATING_VIEW_STACK_HPP
#define XPCC_COMMUNICATING_VIEW_STACK_HPP

#include <xpcc/communicator.hpp>
#include <xpcc/communicatable.hpp>

#include <modm/ui/menu/view_stack.hpp>

namespace xpcc
{
	/// @ingroup xpcc
	template<typename Allocator = std::allocator<modm::IAbstractView> >
	class CommunicatingViewStack : public modm::ViewStack<Allocator>
	{
	public:
		constexpr CommunicatingViewStack(modm::GraphicDisplay* display, xpcc::Communicator* communicator) :
			modm::ViewStack<Allocator>(display),
			communicator(communicator)
		{
		}

		inline xpcc::Communicator*
		getCommunicator()
		{
			return communicator;
		}

	protected:
		xpcc::Communicator* communicator;
	};
}

#endif // XPCC_COMMUNICATING_VIEW_STACK_HPP

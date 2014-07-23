/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test_suite.hpp>
#include <sx/sx.hpp>
#include "command.hpp"

SX_USING_NAMESPACES()

// This is a namespace for tests by class/file__method/function.
BOOST_AUTO_TEST_SUITE(sha512__invoke)

BOOST_AUTO_TEST_CASE(sha1512__invoke__always__okay_output)
{
    // $ sx sha512 900df00d
    SX_DECLARE_COMMAND(sha512);
    command.set_hex_argument({ "900df00d" });
    SX_REQUIRE_OKAY(command.invoke(input, output, error));
    auto foo = output.str();
    SX_REQUIRE_OUTPUT("d1f51c57b00d399be4e708bfd1d76d711bbbdda534383df4f06933187bce41fdfdaa6385cfa960f68abcd33ae0573deb39503f73e8e2b7645845671f11855f8e\n");
}

BOOST_AUTO_TEST_SUITE_END()
// Copyright (c) Glyn Matthews 2011, 2012.
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <gtest/gtest.h>
#include <network/uri/encode.hpp>
#include <network/uri/decode.hpp>
#include <iterator>


TEST(uri_encoding_test, encode_user_info_iterator) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");

  std::string instance;
  network::encode_user_info(std::begin(unencoded), std::end(unencoded),
			    std::back_inserter(instance));
  ASSERT_EQ(instance, "%21%23%24%26%27%28%29%2A%2B%2C%2F:%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_user_info) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");
  ASSERT_EQ(network::encode_user_info(unencoded),
	    "%21%23%24%26%27%28%29%2A%2B%2C%2F:%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_host_iterator) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");

  std::string instance;
  network::encode_host(std::begin(unencoded), std::end(unencoded),
		       std::back_inserter(instance));
  ASSERT_EQ(instance, "%21%23%24%26%27%28%29%2A%2B%2C%2F%3A%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_host) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");
  ASSERT_EQ(network::encode_host(unencoded),
	    "%21%23%24%26%27%28%29%2A%2B%2C%2F%3A%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_port_iterator) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");

  std::string instance;
  network::encode_port(std::begin(unencoded), std::end(unencoded),
		       std::back_inserter(instance));
  ASSERT_EQ(instance, "%21%23%24%26%27%28%29%2A%2B%2C%2F%3A%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_port) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");
  ASSERT_EQ(network::encode_port(unencoded),
	    "%21%23%24%26%27%28%29%2A%2B%2C%2F%3A%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_path_iterator) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");

  std::string instance;
  network::encode_path(std::begin(unencoded), std::end(unencoded),
		       std::back_inserter(instance));
  ASSERT_EQ(instance, "%21%23%24%26%27%28%29%2A%2B%2C/%3A%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_path) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");
  ASSERT_EQ(network::encode_path(unencoded),
	    "%21%23%24%26%27%28%29%2A%2B%2C/%3A%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_query_iterator) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");

  std::string instance;
  network::encode_query(std::begin(unencoded), std::end(unencoded),
			std::back_inserter(instance));
  ASSERT_EQ(instance, "%21%23%24&%27%28%29%2A%2B%2C%2F%3A;=%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_query) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");
  ASSERT_EQ(network::encode_query(unencoded),
	    "%21%23%24&%27%28%29%2A%2B%2C%2F%3A;=%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_fragment_iterator) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");

  std::string instance;
  network::encode_fragment(std::begin(unencoded), std::end(unencoded),
			   std::back_inserter(instance));
  ASSERT_EQ(instance, "%21%23%24%26%27%28%29%2A%2B%2C%2F%3A%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, encode_fragment) {
  const std::string unencoded("!#$&\'()*+,/:;=?@[]");
  ASSERT_EQ(network::encode_fragment(unencoded),
	    "%21%23%24%26%27%28%29%2A%2B%2C%2F%3A%3B%3D%3F%40%5B%5D");
}

TEST(uri_encoding_test, decode_iterator) {
  const std::string encoded("%21%23%24%26%27%28%29%2A%2B%2C%2F%3A%3B%3D%3F%40%5B%5D");

  std::string instance;
  network::decode(std::begin(encoded), std::end(encoded),
		       std::back_inserter(instance));
  ASSERT_EQ(instance, "!#$&\'()*+,/:;=?@[]");
}

TEST(uri_encoding_test, decode) {
  const std::string encoded("%21%23%24%26%27%28%29%2A%2B%2C%2F%3A%3B%3D%3F%40%5B%5D");
  ASSERT_EQ(network::decode(encoded), "!#$&\'()*+,/:;=?@[]");
}

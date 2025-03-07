#include <crails/cookie_data.hpp>
#include <iostream>

#undef NDEBUG
#include <cassert>

using namespace std;

const string password("4GS3s2ngF_ui_n6i2yglNito1PPTjggoSf1lo0ZaWWVTZerRgb");
const string salt("wBVoCHAZ");

int main()
{
  // Can encode and decode a Data object into a cookie string
  {
    string cookie_string;

    {
      Crails::CookieData data(password, salt);
      data["keyA"] = 42;
      data["keyB"] = "Hi";
      cookie_string = data.serialize();
    }

    {
      Crails::CookieData data(password, salt);
      data.unserialize(cookie_string);
      assert(data.as_data().count() == 2);
      assert(data["keyA"].as<short>() == 42);
      assert(data["keyB"].as<string>() == "Hi");
    }
  }

  // Doesn't allow external agents to read the data
  {
    string cookie_string;

    {
      Crails::CookieData data(password, salt);
      data["password"] = "secret";
      cookie_string = data.serialize();
    }
    assert(cookie_string.find("password") == string::npos);
    assert(cookie_string.find("secret") == string::npos);
  }
  return 0;
}

#include "cookie_store.hpp"

using namespace std;
using namespace Crails;

CookieStore::CookieStore(const string& password, const string& salt) :
  cookies(password, salt)
{
}

void CookieStore::load(const HttpRequest& request)
{
  auto cookie_header = request.find(HttpHeader::cookie);

  if (cookie_header != request.end())
    cookies.unserialize(std::string(cookie_header->value()));
}

void CookieStore::finalize(BuildingResponse& response)
{
  if (cookies.as_data().count() > 0)
    response.set_header(HttpHeader::set_cookie, cookies.serialize());
}

Data CookieStore::to_data(void)
{
  return (cookies.as_data());
}

const Data CookieStore::to_data(void) const
{
  return (cookies.as_data());
}

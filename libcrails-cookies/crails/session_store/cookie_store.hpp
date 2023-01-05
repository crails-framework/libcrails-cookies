#ifndef  COOKIE_STORE_HPP
# define COOKIE_STORE_HPP

# include "../cookie_data.hpp"
# include <crails/http_response.hpp>
# include <crails/session_store.hpp>

namespace Crails
{
  class CookieStore : public SessionStore
  {
    SESSION_STORE_IMPLEMENTATION(CookieStore)
  public:
    void       load(const HttpRequest&) override;
    void       finalize(BuildingResponse&) override;
    Data       to_data(void) override;
    const Data to_data(void) const override;

  private:
    CookieData cookies;
  };
}

#endif

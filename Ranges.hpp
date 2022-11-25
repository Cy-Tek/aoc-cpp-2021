//
// Created by hanna on 11/23/2022.
//

#ifndef AOC_CPP_2021_RANGES_HPP
#define AOC_CPP_2021_RANGES_HPP

#include <cmath>
#include <ranges>

namespace rv = std::ranges::views;
namespace rg = std::ranges;

bool IsPrime(const int number) {
  if (number != 2) {
    if (number < 2 || number % 2 == 0) return false;
    auto root = std::sqrt(number);
    for (int i = 3; i <= root; i += 2)
      if (number % i == 0) return false;
  }

  return true;
}

template<rg::input_range R, typename P> requires rg::view<R>
class trim_view : public rg::view_interface<trim_view<R, P>> {
public:
    trim_view() = default;

    constexpr trim_view(R base, P pred) : mBase{std::move(base)},
                                          mPred{std::move(pred)},
                                          mBegin{std::begin(mBase)},
                                          mEnd{std::end(mBase)} {}

    constexpr R base() const &{
      return mBase;
    }

    constexpr R base() &&{
      return std::move(mBase);
    }

    constexpr P const &pred() const {
      return mPred;
    }

    constexpr auto begin() const {
      ensure_evaluated();
      return mBegin;
    }

    constexpr auto end() const {
      ensure_evaluated();
      return mEnd;
    }

    constexpr auto size() requires rg::sized_range<R> {
      return std::distance(mBegin, mEnd);
    }

    constexpr auto size() requires rg::sized_range<const R> {
      return std::distance(mBegin, mEnd);
    }

private:
    R mBase{};
    P mPred;

    mutable rg::iterator_t<R> mBegin{std::begin(mBase)};
    mutable rg::iterator_t<R> mEnd{std::end(mBase)};
    mutable bool mEvaluated = false;

    void ensure_evaluated() const;
};

template<rg::input_range R, typename P>
requires rg::view<R>
void trim_view<R, P>::ensure_evaluated() const {
  if (!mEvaluated) {
    while (mBegin != std::end(mBase) && mPred(*mBegin)) {
      mBegin = std::next(mBegin);
    }

    while (mEnd != mBegin && mPred(*std::prev(mEnd))) {
      mEnd = std::prev(mEnd);
    }

    mEvaluated = true;
  }
}

template<class R, typename P>
trim_view(R &&base, P pred) -> trim_view<rg::views::all_t<R>, P>;

namespace details {
    namespace rg = std::ranges;
    namespace rv = std::ranges::views;

    template<typename P>
    struct trim_view_range_adaptor_closure {
        P pred;

        constexpr explicit trim_view_range_adaptor_closure(P pred_) : pred{pred_} {}

        template<rg::viewable_range R>
        constexpr auto operator()(R &&r) const {
          return trim_view{std::forward<R>(r), pred};
        }
    };

    struct trim_view_range_adaptor {
        template<rg::viewable_range R, typename P>
        constexpr auto operator()(R &&r, P pred) {
          return trim_view(std::forward<R>(r), pred);
        }

        template<typename P>
        constexpr auto operator()(P pred) {
          return trim_view_range_adaptor_closure(pred);
        }
    };

    template<rg::viewable_range R, typename P>
    constexpr auto operator|(R &&r, trim_view_range_adaptor_closure<P> const &a) {
      return a(std::forward<R>(r));
    }
}

#endif //AOC_CPP_2021_RANGES_HPP

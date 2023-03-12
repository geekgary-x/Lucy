#pragma once
#include <boost/smart_ptr.hpp>
#include <type_traits>
namespace Lucy
{
	template<typename T, class... Args>
	class Singleton
	{
    public:
        friend boost::shared_ptr<T> boost::make_shared<T>();
    public:
        static boost::shared_ptr<T> getInstance(Args && ... args) noexcept
        {
            static boost::shared_ptr<T> instance = boost::make_shared<T>(boost::detail::sp_forward<Args>(args)...);
            return instance;
        }

        virtual ~Singleton() noexcept {}
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
    protected:
        Singleton() = default;
	};
}
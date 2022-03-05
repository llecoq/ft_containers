
namespace ft
{

	template<typename T>
	constexpr std::remove_reference_t<T>&& move_utils(T&& t) noexcept
	{
		return static_cast<std::remove_reference_t<T>&&>(t);
	}
}
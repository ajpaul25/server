#pragma once

#include <memory>

#include <boost/noncopyable.hpp>

#include <Glee.h>

#include <boost/tuple/tuple.hpp>
#include <boost/thread/future.hpp>

namespace caspar { namespace gl {
	
class pixel_buffer_object : boost::noncopyable
{
public:
	pixel_buffer_object();
	pixel_buffer_object(pixel_buffer_object&& other);
	pixel_buffer_object(size_t width, size_t height, GLenum format = GL_BGRA);
	pixel_buffer_object& operator=(pixel_buffer_object&& other);
	void create(size_t width, size_t height, GLenum format = GL_BGRA);
	~pixel_buffer_object(){}

	void unmap_write();
	void* map_write();

	void unmap_read();
	void* map_read();

	void is_smooth(bool smooth);

	void* data();
	const void* data() const;

	void bind_texture();

	size_t width() const;
	size_t height() const;
	size_t size() const;

	bool is_reading() const;
	bool is_writing() const;
		
private:
	struct implementation;
	std::shared_ptr<implementation> impl_;
};
typedef std::shared_ptr<pixel_buffer_object> pixel_buffer_object_ptr;

typedef pixel_buffer_object pbo;
typedef pixel_buffer_object_ptr pbo_ptr;
}}
/*
	INTERFACE GCOMPONENT
*/

#ifndef GCOMPONENT
#define GCOMPONENT

#include <vector>
#include "bdt_grectangle.hpp"
#include "../interface/bdt_renderable.hpp"

namespace bdt {
namespace graphic {

class GComponent : virtual public GRectangle, virtual public Renderable {
protected:

	Color foreground_;
	Color background_;
	
	bool visible_;

	GComponent* parent_;
	
	std::vector<GComponent*> children_;

	GComponent()
	 :	GRectangle(0,0,0,0),
	 	Renderable(),
	 	foreground_(C_BRIGHT_WHITE),
		background_(C_BLACK),
		visible_(true),
		parent_(nullptr) {}
	// default settings

	~GComponent() {
		for(auto child : children_)
			child->~GComponent();
		if(parent_!=nullptr) {
			for(auto comp=parent_->children_.begin();comp<parent_->children_.end();comp++) {
				if(*comp == this) {
					parent_->children_.erase(comp);
					break;
				}
			}
		}
	}

	inline GRectangle* get_abs_bounds() {
		if(parent_ != nullptr) {
			GRectangle* abs_bounds;
			GRectangle* tmp = new GRectangle(this->get_bounds());
			tmp->translate(parent_->get_x(),parent_->get_y());
			abs_bounds = parent_->get_intersection(*tmp);
			delete tmp;
			return abs_bounds;
		}
		else
			return new GRectangle(this->get_bounds());
	}
	
	inline void set_parent(GComponent* parent) {	this->parent_ = parent;	}

public:	
	
	inline Color get_foreground() const {	return this->foreground_;	}
	inline Color get_background() const {	return this->background_;	}
	inline bool is_visible() const {	return this->visible_;	}
	
	inline void set_foreground(Color foreground) {	this->foreground_ = foreground;	}
	inline void set_background(Color background) {	this->background_ = background;	}
	inline void set_visible(bool visible) {	this->visible_ = visible;	}

	inline void add(GComponent* child) {
		this->children_.push_back(child);
		child->set_parent(this);
	}

	// override Renderable
	virtual void render() override {
		GRectangle* abs_bounds = get_abs_bounds();
		if(abs_bounds == nullptr)	return;
		if(this->visible_ == false)	return;
		
		Renderable::_set_color(foreground_,background_);
		for(int h=0; h<abs_bounds->get_height(); h++) {
			Renderable::_set_pos(abs_bounds->get_x(),abs_bounds->get_y()+h);
			for(int w=0; w<abs_bounds->get_width(); w++)	cout << " ";			
		}

		if(!children_.empty())
			for(auto& comp : children_)
				comp->render();
	}

	// override Stringlizable
	virtual string to_string() const override {	return "";	}

};

}
}

#endif
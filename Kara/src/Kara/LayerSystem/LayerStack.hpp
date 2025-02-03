#pragma once

#include "Kara/Core/Core.hpp"

namespace Kara {
namespace LayerSystem {
class Layer;

class KARA_API LayerStack {
  using Container = std::vector<Layer *>;

public:
  ~LayerStack();

  //! @brief Used to insert a layer to the layer stack. Caller will lose
  //! ownership over the [aLayer] parameter
  void Push(Layer *aLayer);
  void Pop(Layer *aLayer);

  Container::iterator begin() noexcept { return mLayers.begin(); }
  Container::iterator end() noexcept { return mLayers.end(); }

private:
  Container mLayers;
};
} // namespace LayerSystem
} // namespace Kara
<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>multithread.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/al/</path>
    <filename>multithread_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::al</namespace>
    <member kind="typedef">
      <type>double</type>
      <name>mt_double_t</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>a120235a88ff5b87aecc2b6671e2aa34d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::size_t</type>
      <name>mt_size_t</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>adde22a9fc824f252937cfda2ceca8b18</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mt_add</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>a2b2f1a1104dd40f0ba23f12ad48ed8df</anchor>
      <arglist>(U &amp;lhs, const V &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mt_init</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>a9c316463739f65c5fc7994d9e38e96f7</anchor>
      <arglist>(LHS *lhs, RHS rhs)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>mt_load</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>aa2cfd83ab696496e080e73a168e31c21</anchor>
      <arglist>(const T &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mt_set</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>a34ba8f4c71fd6d74cc9b1a2f70a47340</anchor>
      <arglist>(U &amp;lhs, const V &amp;rhs)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>closest_pair2D.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/</path>
    <filename>closest__pair2D_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::algorithm::closest_pair2D</class>
    <class kind="struct">rcppsw::algorithm::result_type2D</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
  </compound>
  <compound kind="file">
    <name>base_clustering_impl.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/clustering/</path>
    <filename>base__clustering__impl_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="cluster_8hpp" name="cluster.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/cluster.hpp</includes>
    <includes id="membership__policy_8hpp" name="membership_policy.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/membership_policy.hpp</includes>
    <class kind="interface">rcppsw::algorithm::clustering::base_clustering_impl</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::algorithm::clustering</namespace>
  </compound>
  <compound kind="file">
    <name>cluster.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/clustering/</path>
    <filename>cluster_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="membership__policy_8hpp" name="membership_policy.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/membership_policy.hpp</includes>
    <includes id="math_8hpp" name="math.hpp" local="yes" imported="no">rcppsw/math/math.hpp</includes>
    <class kind="struct">rcppsw::algorithm::clustering::cluster::mapping</class>
    <class kind="struct">rcppsw::algorithm::clustering::cluster::mapping&lt; T, Policy, policy::is_eh&lt; Policy &gt; &gt;</class>
    <class kind="struct">rcppsw::algorithm::clustering::cluster::mapping&lt; T, Policy, policy::is_nc&lt; Policy &gt; &gt;</class>
    <class kind="class">rcppsw::algorithm::clustering::eh_cluster</class>
    <class kind="class">rcppsw::algorithm::clustering::nc_cluster</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::algorithm::clustering</namespace>
    <namespace>rcppsw::algorithm::clustering::cluster</namespace>
  </compound>
  <compound kind="file">
    <name>eh_clustering_impl.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/clustering/</path>
    <filename>eh__clustering__impl_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="base__clustering__impl_8hpp" name="base_clustering_impl.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/base_clustering_impl.hpp</includes>
    <class kind="interface">rcppsw::algorithm::clustering::eh_clustering_impl</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::algorithm::clustering</namespace>
  </compound>
  <compound kind="file">
    <name>entropy.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/clustering/</path>
    <filename>entropy_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="cluster_8hpp" name="cluster.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/cluster.hpp</includes>
    <includes id="eh__clustering__impl_8hpp" name="eh_clustering_impl.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/eh_clustering_impl.hpp</includes>
    <includes id="range_8hpp" name="range.hpp" local="yes" imported="no">rcppsw/math/range.hpp</includes>
    <includes id="ientropy_8hpp" name="ientropy.hpp" local="yes" imported="no">rcppsw/math/ientropy.hpp</includes>
    <class kind="class">rcppsw::algorithm::clustering::entropy_balch2000</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::algorithm::clustering</namespace>
  </compound>
  <compound kind="file">
    <name>entropy_eh_omp.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/clustering/</path>
    <filename>entropy__eh__omp_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="eh__clustering__impl_8hpp" name="eh_clustering_impl.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/eh_clustering_impl.hpp</includes>
    <class kind="class">rcppsw::algorithm::clustering::entropy_eh_omp</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::algorithm::clustering</namespace>
  </compound>
  <compound kind="file">
    <name>kmeans.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/clustering/</path>
    <filename>kmeans_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="cluster_8hpp" name="cluster.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/cluster.hpp</includes>
    <includes id="kmeans__omp_8hpp" name="kmeans_omp.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/kmeans_omp.hpp</includes>
    <includes id="base__clustering__impl_8hpp" name="base_clustering_impl.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/base_clustering_impl.hpp</includes>
    <class kind="class">rcppsw::algorithm::clustering::kmeans</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::algorithm::clustering</namespace>
  </compound>
  <compound kind="file">
    <name>kmeans_omp.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/clustering/</path>
    <filename>kmeans__omp_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="base__clustering__impl_8hpp" name="base_clustering_impl.hpp" local="yes" imported="no">rcppsw/algorithm/clustering/base_clustering_impl.hpp</includes>
    <class kind="class">rcppsw::algorithm::clustering::kmeans_omp</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::algorithm::clustering</namespace>
  </compound>
  <compound kind="file">
    <name>membership_policy.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/clustering/</path>
    <filename>membership__policy_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="struct">rcppsw::algorithm::clustering::membership::mapping</class>
    <class kind="struct">rcppsw::algorithm::clustering::membership::mapping&lt; Policy, policy::is_eh&lt; Policy &gt; &gt;</class>
    <class kind="struct">rcppsw::algorithm::clustering::membership::mapping&lt; Policy, policy::is_nc&lt; Policy &gt; &gt;</class>
    <class kind="class">rcppsw::algorithm::clustering::policy::EH</class>
    <class kind="class">rcppsw::algorithm::clustering::policy::NC</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::algorithm::clustering</namespace>
    <namespace>rcppsw::algorithm::clustering::membership</namespace>
    <namespace>rcppsw::algorithm::clustering::policy</namespace>
    <member kind="typedef">
      <type>typename std::enable_if_t&lt; is_eh_&lt; Policy &gt;::value &gt;</type>
      <name>is_eh</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</anchorfile>
      <anchor>a93e2541d4b7b87c962aa26a820961171</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::is_same&lt; Policy, EH &gt;</type>
      <name>is_eh_</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</anchorfile>
      <anchor>ae00d598179a3129379523bc8225148d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename std::enable_if_t&lt; is_nc_&lt; Policy &gt;::value &gt;</type>
      <name>is_nc</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</anchorfile>
      <anchor>a6ad2a498aaa8af4df9552dc8a64c81bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::is_same&lt; Policy, NC &gt;</type>
      <name>is_nc_</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</anchorfile>
      <anchor>ad73f8261d3fab385cbd1cf263d937e6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename membership::mapping&lt; Policy &gt;::type</type>
      <name>membership_type</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering.html</anchorfile>
      <anchor>ae4bdc3c1b255447703e70a19e7c90aef</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>convex_hull2D.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/</path>
    <filename>convex__hull2D_8hpp.html</filename>
    <includes id="math_8hpp" name="math.hpp" local="yes" imported="no">rcppsw/math/math.hpp</includes>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="vector2_8hpp" name="vector2.hpp" local="yes" imported="no">rcppsw/math/vector2.hpp</includes>
    <class kind="class">rcppsw::algorithm::convex_hull2D</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
  </compound>
  <compound kind="file">
    <name>max_subarray_finder.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/</path>
    <filename>max__subarray__finder_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::algorithm::max_subarray_finder</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
  </compound>
  <compound kind="file">
    <name>transform.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/algorithm/</path>
    <filename>transform_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <member kind="function">
      <type>OutputIterator</type>
      <name>transform_if</name>
      <anchorfile>namespacercppsw_1_1algorithm.html</anchorfile>
      <anchor>a708f58ee6c37c53495f944f28499ea28</anchor>
      <arglist>(InputIterator first, InputIterator last, OutputIterator result, const Predicate &amp;pred, const UnaryFunction &amp;f)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>common.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/common/</path>
    <filename>common_8hpp.html</filename>
    <includes id="common_2macros_8hpp" name="macros.hpp" local="yes" imported="no">rcppsw/common/macros.hpp</includes>
    <includes id="mpl_8hpp" name="mpl.hpp" local="yes" imported="no">rcppsw/mpl/mpl.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::detail</namespace>
    <member kind="typedef">
      <type>decltype(std::declval&lt; T &gt;().to_str())</type>
      <name>to_str_type</name>
      <anchorfile>namespacercppsw_1_1detail.html</anchorfile>
      <anchor>ab58299866908c24e5cb4283812dd0b73</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr std::underlying_type&lt; TEnum &gt;::type</type>
      <name>as_underlying</name>
      <anchorfile>namespacercppsw.html</anchorfile>
      <anchor>a8947a64dc8b866fbf1b0e47526552828</anchor>
      <arglist>(const TEnum &amp;e) noexcept</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_string</name>
      <anchorfile>namespacercppsw.html</anchorfile>
      <anchor>a067e7fdc1e45476ca82cb106d0809015</anchor>
      <arglist>(const T &amp;obj)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>macros.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/common/</path>
    <filename>common_2macros_8hpp.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>define</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a0ec3f1f76900803ac4f041eb90b84a34</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>NS_END</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>af6c55b58384045452cc8ce88f54e3265</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>NS_END_</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a9ad0eb293f54247c59c75d849c45df67</anchor>
      <arglist>(ns)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>NS_START</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a553c4f9d95d9ac867c32675925e86368</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>NS_START_</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a8a6cf97b5307c71b6cfc574f88081818</anchor>
      <arglist>(ns)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_COLD</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>aab1daefd51d059d6774569e9590d4fb8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_CONST</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>ac9a179ff9e10d391a9a794175729493f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_DEAD</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>ad10e83a2ab0471c0e95bca6e8d822557</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FPC_RET_V</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a0ea9c4e875ed1ff7ea3805fd70bedadc</anchor>
      <arglist>(cond)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_IS_BETWEEN</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>aa37b1bea2856518ad91b6407e42e88cb</anchor>
      <arglist>(n, lb, ub)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_IS_EVEN</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a252ccf92abf5da261a39dbbf3c1724e5</anchor>
      <arglist>(n)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_IS_ODD</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>af19b142b99e0e3eb22d3eec2ba54d1bd</anchor>
      <arglist>(n)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_LIKELY</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a87b5ff6118f9c04219cbc01e39c5982a</anchor>
      <arglist>(cond)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_NODISCARD</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a4160e6a58445c478750f981632097665</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_PTRREF_DECLDEF</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a5c02369dbdd1a76f31cbc10b6fe6e87a</anchor>
      <arglist>(Func, Member,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_PTRREF_DECLDEF_CONST</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a7fedd56824caca9558ffca4adf523bd3</anchor>
      <arglist>(Func, Member)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_PURE</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a080d8af20d6aa955d4db7ef068309a7c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_STRUCT_DOT_INITIALIZER</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a7923482659a79cf40aec0fd929aa8c4b</anchor>
      <arglist>(name, value)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_UNLIKELY</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a318d7a1e5f231434bb28321d941ddce3</anchor>
      <arglist>(cond)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_UNUSED</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a182007b022ff477677d33b31a89cb7fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WARNING_DISABLE</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>abd3fccfd919cadd321de43b436a7f50f</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WARNING_DISABLE_POP</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a5e18d29b5090a524f0317886f2539bc4</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WARNING_DISABLE_PUSH</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a753de85e03181f93c89a5b39285670fd</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WRAP_DECL</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a0b47b5230c652d927b3486dd6056c2de</anchor>
      <arglist>(Ret, Func,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WRAP_DECL_OVERRIDE</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>aeab6d90820e57a2708a9fb57d17362af</anchor>
      <arglist>(Ret, Func,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WRAP_DECLDEF</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>ac325bbd230ae35d40462ed95ddb468db</anchor>
      <arglist>(Func, Callable,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WRAP_DECLDEF_AS</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a308f81475fb65ca59ee3a3ae5a7581d3</anchor>
      <arglist>(Func, Callable, NewName,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WRAP_DECLDEF_OVERRIDE</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>ad6c93faf754b45bd3d4c9c5def3fcaba</anchor>
      <arglist>(Func, Callable,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WRAP_DEF</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a77cd57707ddc6b4f3dd0de2b866e5cb2</anchor>
      <arglist>(Class, Func, Handle,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WRAP_DEF_OVERRIDE</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a28f0630dfa16c654b0ec4f414335b656</anchor>
      <arglist>(Class, Func, Handle,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WRAP_DEFP</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>afb0404b009333e643b3aff1341c0cdd1</anchor>
      <arglist>(Class, Func, Handle, NullRet,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_WRAP_DEFP_OVERRIDE</name>
      <anchorfile>common_2macros_8hpp.html</anchorfile>
      <anchor>a697ec27047c2fcc8041986662581cc97</anchor>
      <arglist>(Class, Func, Handle, NullRet,...)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>macros.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/er/</path>
    <filename>er_2macros_8hpp.html</filename>
    <includes id="er_8hpp" name="er.hpp" local="yes" imported="no">rcppsw/er/er.hpp</includes>
    <includes id="stacktrace_8hpp" name="stacktrace.hpp" local="yes" imported="no">rcppsw/er/stacktrace.hpp</includes>
    <member kind="define">
      <type>#define</type>
      <name>ER_ASSERT</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>abd0e460b9aa8c2ffef233474c3486dd1</anchor>
      <arglist>(cond, msg,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_CHECK</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>a6d9b0f16d55f153c8056d89be1eb5d71</anchor>
      <arglist>(cond, msg,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_CONDD</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>a6d1bf605505a2c66679f0b6f3d7f0750</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_CONDI</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>afc18a617db752590e2f31e769c9e6b40</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_CONDW</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>a82e0fbe4789d998bd0496c692d8d1447</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_DEBUG</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>aca509f60c625066554367ccf8150e10b</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_ERR</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>af35280808d990b76b7a859d37ed12626</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_FATAL</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>a04117b448c465e24b73c68f044a9a7bb</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_FATAL_SENTINEL</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>a77ef3bf40622ab52772e57524467bbbc</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_GET_LOGGER</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>a75c746b5add05a5bd3f5d0e0b45175ac</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_INFO</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>adcf63ebd51cba1bf7ec00484800bd728</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_SENTINEL</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>ace3553fdadbaeee5c8a006b30bc43df0</anchor>
      <arglist>(msg,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_TRACE</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>a8973874d9049f2fb8e3c6b7c3d8a981e</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_WARN</name>
      <anchorfile>er_2macros_8hpp.html</anchorfile>
      <anchor>a8fd8dc21eb70bd0c45fc5f2921a33b09</anchor>
      <arglist>(...)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>base_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/config/</path>
    <filename>base__config_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="struct">rcppsw::config::base_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::config</namespace>
  </compound>
  <compound kind="file">
    <name>streamable_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/config/</path>
    <filename>streamable__parser_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::config::streamable_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::config</namespace>
  </compound>
  <compound kind="file">
    <name>xml_config_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/config/xml/</path>
    <filename>xml__config__parser_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <member kind="define">
      <type>#define</type>
      <name>XML_PARSE_ATTR</name>
      <anchorfile>xml__config__parser_8hpp.html</anchorfile>
      <anchor>a6d5050689b0bcd25748de04b7c3b2e29</anchor>
      <arglist>(node, container, name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>XML_PARSE_ATTR_DFLT</name>
      <anchorfile>xml__config__parser_8hpp.html</anchorfile>
      <anchor>a09c9111f566e624a42b834827648d589</anchor>
      <arglist>(node, container, name, dflt)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>xml_config_repository.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/config/xml/</path>
    <filename>xml__config__repository_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="xml__config__parser_8hpp" name="xml_config_parser.hpp" local="yes" imported="no">rcppsw/config/xml/xml_config_parser.hpp</includes>
    <includes id="factory_8hpp" name="factory.hpp" local="yes" imported="no">rcppsw/patterns/factory/factory.hpp</includes>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <class kind="class">rcppsw::config::xml::xml_config_repository</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::config</namespace>
    <namespace>rcppsw::config::xml</namespace>
  </compound>
  <compound kind="file">
    <name>aperiodic_waveform.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/control/</path>
    <filename>aperiodic__waveform_8hpp.html</filename>
    <includes id="base__waveform_8hpp" name="base_waveform.hpp" local="yes" imported="no">rcppsw/control/base_waveform.hpp</includes>
    <class kind="class">rcppsw::control::constant_waveform</class>
    <class kind="class">rcppsw::control::null_waveform</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::control</namespace>
  </compound>
  <compound kind="file">
    <name>base_waveform.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/control/</path>
    <filename>base__waveform_8hpp.html</filename>
    <includes id="waveform__config_8hpp" name="waveform_config.hpp" local="yes" imported="no">rcppsw/control/config/waveform_config.hpp</includes>
    <includes id="radians_8hpp" name="radians.hpp" local="yes" imported="no">rcppsw/math/radians.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::control::base_waveform</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::control</namespace>
  </compound>
  <compound kind="file">
    <name>waveform_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/control/config/</path>
    <filename>waveform__config_8hpp.html</filename>
    <includes id="base__config_8hpp" name="base_config.hpp" local="yes" imported="no">rcppsw/config/base_config.hpp</includes>
    <class kind="struct">rcppsw::control::config::waveform_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::control</namespace>
    <namespace>rcppsw::control::config</namespace>
  </compound>
  <compound kind="file">
    <name>waveform_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/control/config/xml/</path>
    <filename>waveform__parser_8hpp.html</filename>
    <includes id="waveform__config_8hpp" name="waveform_config.hpp" local="yes" imported="no">rcppsw/control/config/waveform_config.hpp</includes>
    <includes id="xml__config__parser_8hpp" name="xml_config_parser.hpp" local="yes" imported="no">rcppsw/config/xml/xml_config_parser.hpp</includes>
    <class kind="class">rcppsw::control::config::xml::waveform_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::control</namespace>
    <namespace>rcppsw::control::config</namespace>
    <namespace>rcppsw::control::config::xml</namespace>
  </compound>
  <compound kind="file">
    <name>periodic_waveform.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/control/</path>
    <filename>periodic__waveform_8hpp.html</filename>
    <includes id="base__waveform_8hpp" name="base_waveform.hpp" local="yes" imported="no">rcppsw/control/base_waveform.hpp</includes>
    <class kind="class">rcppsw::control::sawtooth_waveform</class>
    <class kind="class">rcppsw::control::sine_waveform</class>
    <class kind="class">rcppsw::control::square_waveform</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::control</namespace>
  </compound>
  <compound kind="file">
    <name>pid_loop.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/control/</path>
    <filename>pid__loop_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::control::pid_loop</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::control</namespace>
  </compound>
  <compound kind="file">
    <name>waveform_generator.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/control/</path>
    <filename>waveform__generator_8hpp.html</filename>
    <includes id="factory_8hpp" name="factory.hpp" local="yes" imported="no">rcppsw/patterns/factory/factory.hpp</includes>
    <class kind="class">rcppsw::control::waveform_generator</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::control</namespace>
    <namespace>rcppsw::control::config</namespace>
  </compound>
  <compound kind="file">
    <name>base_grid2D.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>base__grid2D_8hpp.html</filename>
    <includes id="vector2_8hpp" name="vector2.hpp" local="yes" imported="no">rcppsw/math/vector2.hpp</includes>
    <class kind="class">rcppsw::ds::base_grid2D</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>base_grid3D.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>base__grid3D_8hpp.html</filename>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <class kind="class">rcppsw::ds::base_grid3D</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>base_grid_overlay.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>base__grid__overlay_8hpp.html</filename>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="vector2_8hpp" name="vector2.hpp" local="yes" imported="no">rcppsw/math/vector2.hpp</includes>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <includes id="discretize__ratio_8hpp" name="discretize_ratio.hpp" local="yes" imported="no">rcppsw/types/discretize_ratio.hpp</includes>
    <class kind="class">rcppsw::ds::base_grid_overlay</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>base_vertex_property.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>base__vertex__property_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="struct">rcppsw::ds::graph::base_vertex_property</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
  </compound>
  <compound kind="file">
    <name>directed_graph.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>directed__graph_8hpp.html</filename>
    <includes id="graph_8hpp" name="graph.hpp" local="yes" imported="no">rcppsw/ds/graph/graph.hpp</includes>
    <includes id="directed__graph__spec_8hpp" name="directed_graph_spec.hpp" local="yes" imported="no">rcppsw/ds/graph/directed_graph_spec.hpp</includes>
    <includes id="decorator_8hpp" name="decorator.hpp" local="yes" imported="no">rcppsw/patterns/decorator/decorator.hpp</includes>
    <class kind="class">rcppsw::ds::graph::directed_graph</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
  </compound>
  <compound kind="file">
    <name>directed_graph_spec.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>directed__graph__spec_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="base__vertex__property_8hpp" name="base_vertex_property.hpp" local="yes" imported="no">rcppsw/ds/graph/base_vertex_property.hpp</includes>
    <class kind="struct">rcppsw::ds::graph::directed_graph_spec</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
  </compound>
  <compound kind="file">
    <name>graph.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>graph_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
    <namespace>rcppsw::ds::graph::detail</namespace>
    <member kind="typedef">
      <type>typename std::add_pointer&lt; decltype(std::declval&lt; TBGLGraphType &gt;().operator[](std::declval&lt; typename TBGLGraphType::vertex_descriptor &gt;())) &gt;::type</type>
      <name>find_result_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph_1_1detail.html</anchorfile>
      <anchor>a2c9bda01f8c338e7729fe49a9bedb89c</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>static auto</type>
      <name>add_edge</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>a728ba2f07edc3a2f9de61e879884274a</anchor>
      <arglist>(TBGLGraphType &amp;g, typename TBGLGraphType::vertex_descriptor u, typename TBGLGraphType::vertex_descriptor v)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static auto</type>
      <name>add_vertex</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>a6f1130cb6bca74a465baf0c8575b7250</anchor>
      <arglist>(TBGLGraphType &amp;g)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static auto</type>
      <name>adjacent_vertices</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>a2b1e5f47a4374b0b9fa3b25436eae969</anchor>
      <arglist>(const TBGLGraphType &amp;g, typename TBGLGraphType::vertex_descriptor v)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>contains</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>ab90eab37470416a242c969f02bde4a2a</anchor>
      <arglist>(const TBGLGraphType &amp;g, const rmath::vector3z &amp;c)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static boost::optional&lt; typename TBGLGraphType::vertex_descriptor &gt;</type>
      <name>find</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>a2b2d4d13c8b1fc4fb15e97c21264a80b</anchor>
      <arglist>(const TBGLGraphType &amp;g, const TCoordType &amp;c)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static size_t</type>
      <name>n_vertices</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>a2a17a8cdf486ffc7a07c462721e565f9</anchor>
      <arglist>(const TBGLGraphType &amp;g)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static auto</type>
      <name>out_degree</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>ad9231fc8acb48c67c0baaf2e1dc25938</anchor>
      <arglist>(const TBGLGraphType &amp;g, const typename TBGLGraphType::vertex_descriptor &amp;v)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static auto</type>
      <name>out_edges</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>aaa3f849f6d4a554ba04b592f4992118a</anchor>
      <arglist>(const TBGLGraphType &amp;g, const typename TBGLGraphType::vertex_descriptor &amp;v)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static auto</type>
      <name>remove_vertex</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>a5b1771af2778d689f0dc497c8911ce1d</anchor>
      <arglist>(TBGLGraphType &amp;g, typename TBGLGraphType::vertex_descriptor v)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static auto</type>
      <name>target</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>abef0e24d8523e68c5460191be4752557</anchor>
      <arglist>(const TBGLGraphType &amp;g, const typename TBGLGraphType::edge_descriptor &amp;e)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static auto</type>
      <name>vertex_properties</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>aaf6a1c472f03c01dcea6deae69f7fe69</anchor>
      <arglist>(const TBGLGraphType &amp;g)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static auto</type>
      <name>vertices</name>
      <anchorfile>graph_8hpp.html</anchorfile>
      <anchor>abc02a164df941675b9b395bfd9d54a30</anchor>
      <arglist>(const TBGLGraphType &amp;g) -&gt; decltype(boost::vertices(std::declval&lt; const TBGLGraphType &gt;()))</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>graphml.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>graphml_8hpp.html</filename>
    <includes id="graph_8hpp" name="graph.hpp" local="yes" imported="no">rcppsw/ds/graph/graph.hpp</includes>
    <includes id="decorator_8hpp" name="decorator.hpp" local="yes" imported="no">rcppsw/patterns/decorator/decorator.hpp</includes>
    <class kind="struct">rcppsw::ds::graph::detail::is_decorator</class>
    <class kind="struct">rcppsw::ds::graph::detail::is_decorator&lt; T, std::void_t&lt; decltype(std::declval&lt; T &gt;().decoratee())&gt; &gt;</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
    <namespace>rcppsw::ds::graph::detail</namespace>
    <member kind="function" static="yes">
      <type>static TMapType</type>
      <name>property_map_gen</name>
      <anchorfile>graphml_8hpp.html</anchorfile>
      <anchor>ada827a7b395b9d2985d319a5f73b68f4</anchor>
      <arglist>(TBGLGraphType &amp;g, std::function&lt; void(TMapType &amp;map, TBGLGraphType &amp;g)&gt; cb)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static TMapType</type>
      <name>property_map_gen</name>
      <anchorfile>graphml_8hpp.html</anchorfile>
      <anchor>abc0de501117e48cdaf1eb0a49de8e3e0</anchor>
      <arglist>(TGraphType &amp;g, std::function&lt; void(TMapType &amp;map, typename TGraphType::decoratee_type &amp;g)&gt; cb)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>read_graphml</name>
      <anchorfile>graphml_8hpp.html</anchorfile>
      <anchor>ae0a49e2853fa45d8b055e8543403419f</anchor>
      <arglist>(const fs::path &amp;path, TBGLGraphType &amp;g, boost::dynamic_properties &amp;dp)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>read_graphml</name>
      <anchorfile>graphml_8hpp.html</anchorfile>
      <anchor>a7a28aced8d1ccda9abf36349d4acc7cf</anchor>
      <arglist>(const fs::path &amp;path, TDecoratorType &amp;g, boost::dynamic_properties &amp;dp)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>grid_index_map.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>grid__index__map_8hpp.html</filename>
    <includes id="decorator_8hpp" name="decorator.hpp" local="yes" imported="no">rcppsw/patterns/decorator/decorator.hpp</includes>
    <class kind="class">rcppsw::ds::graph::grid_index_map</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
  </compound>
  <compound kind="file">
    <name>hgrid3D.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>hgrid3D_8hpp.html</filename>
    <includes id="graph_8hpp" name="graph.hpp" local="yes" imported="no">rcppsw/ds/graph/graph.hpp</includes>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <includes id="decorator_8hpp" name="decorator.hpp" local="yes" imported="no">rcppsw/patterns/decorator/decorator.hpp</includes>
    <includes id="hgrid3D__spec_8hpp" name="hgrid3D_spec.hpp" local="yes" imported="no">rcppsw/ds/graph/hgrid3D_spec.hpp</includes>
    <includes id="hgrid3D__view_8hpp" name="hgrid3D_view.hpp" local="yes" imported="no">rcppsw/ds/graph/hgrid3D_view.hpp</includes>
    <includes id="hgrid3D__view__filter_8hpp" name="hgrid3D_view_filter.hpp" local="yes" imported="no">rcppsw/ds/graph/hgrid3D_view_filter.hpp</includes>
    <class kind="class">rcppsw::ds::graph::hgrid3D</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
  </compound>
  <compound kind="file">
    <name>hgrid3D_spec.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>hgrid3D__spec_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="hgrid3D__vertex__property_8hpp" name="hgrid3D_vertex_property.hpp" local="yes" imported="no">rcppsw/ds/graph/hgrid3D_vertex_property.hpp</includes>
    <class kind="struct">rcppsw::ds::graph::hgrid3D_spec</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
  </compound>
  <compound kind="file">
    <name>hgrid3D_vertex_property.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>hgrid3D__vertex__property_8hpp.html</filename>
    <includes id="base__vertex__property_8hpp" name="base_vertex_property.hpp" local="yes" imported="no">rcppsw/ds/graph/base_vertex_property.hpp</includes>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <class kind="struct">rcppsw::ds::graph::hgrid3D_vertex_property</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
  </compound>
  <compound kind="file">
    <name>hgrid3D_view.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>hgrid3D__view_8hpp.html</filename>
    <includes id="graph_8hpp" name="graph.hpp" local="yes" imported="no">rcppsw/ds/graph/graph.hpp</includes>
    <includes id="decorator_8hpp" name="decorator.hpp" local="yes" imported="no">rcppsw/patterns/decorator/decorator.hpp</includes>
    <includes id="hgrid3D__spec_8hpp" name="hgrid3D_spec.hpp" local="yes" imported="no">rcppsw/ds/graph/hgrid3D_spec.hpp</includes>
    <includes id="hgrid3D__view__filter__data_8hpp" name="hgrid3D_view_filter_data.hpp" local="yes" imported="no">rcppsw/ds/graph/hgrid3D_view_filter_data.hpp</includes>
    <includes id="bounding__box_8hpp" name="bounding_box.hpp" local="yes" imported="no">rcppsw/math/bounding_box.hpp</includes>
    <class kind="class">rcppsw::ds::graph::hgrid3D_view</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
    <member kind="typedef">
      <type>std::function&lt; bool(typename TSpecType::bgl_impl_type::edge_descriptor)&gt;</type>
      <name>hgrid3D_view_edge_filter_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a3d1aea379fd27c507e19570793754cb1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::function&lt; bool(typename TSpecType::bgl_impl_type::vertex_descriptor)&gt;</type>
      <name>hgrid3D_view_vertex_filter_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a9ab64f12c0361cab4cae411667f942c0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>hgrid3D_view_builder.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>hgrid3D__view__builder_8hpp.html</filename>
    <includes id="graph_8hpp" name="graph.hpp" local="yes" imported="no">rcppsw/ds/graph/graph.hpp</includes>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <class kind="class">rcppsw::ds::graph::detail::hgrid3D_view_builder</class>
    <class kind="struct">rcppsw::ds::graph::detail::hgrid3D_view_builder::trace_data</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
    <namespace>rcppsw::ds::graph::detail</namespace>
  </compound>
  <compound kind="file">
    <name>hgrid3D_view_filter.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>hgrid3D__view__filter_8hpp.html</filename>
    <includes id="graph_8hpp" name="graph.hpp" local="yes" imported="no">rcppsw/ds/graph/graph.hpp</includes>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <includes id="hgrid3D__view__filter__data_8hpp" name="hgrid3D_view_filter_data.hpp" local="yes" imported="no">rcppsw/ds/graph/hgrid3D_view_filter_data.hpp</includes>
    <includes id="spatial__dist_8hpp" name="spatial_dist.hpp" local="yes" imported="no">rcppsw/types/spatial_dist.hpp</includes>
    <includes id="manhattan__dist_8hpp" name="manhattan_dist.hpp" local="yes" imported="no">rcppsw/types/manhattan_dist.hpp</includes>
    <class kind="class">rcppsw::ds::graph::detail::hgrid3D_view_filter</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
    <namespace>rcppsw::ds::graph::detail</namespace>
  </compound>
  <compound kind="file">
    <name>hgrid3D_view_filter_data.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/graph/</path>
    <filename>hgrid3D__view__filter__data_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <includes id="manhattan__dist_8hpp" name="manhattan_dist.hpp" local="yes" imported="no">rcppsw/types/manhattan_dist.hpp</includes>
    <includes id="grid__index__map_8hpp" name="grid_index_map.hpp" local="yes" imported="no">rcppsw/ds/graph/grid_index_map.hpp</includes>
    <class kind="class">rcppsw::ds::graph::hgrid3D_view_filter_data</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
  </compound>
  <compound kind="file">
    <name>grid2D.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>grid2D_8hpp.html</filename>
    <includes id="base__grid2D_8hpp" name="base_grid2D.hpp" local="yes" imported="no">rcppsw/ds/base_grid2D.hpp</includes>
    <class kind="class">rcppsw::ds::grid2D</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>grid2D_overlay.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>grid2D__overlay_8hpp.html</filename>
    <includes id="base__grid2D_8hpp" name="base_grid2D.hpp" local="yes" imported="no">rcppsw/ds/base_grid2D.hpp</includes>
    <includes id="base__grid__overlay_8hpp" name="base_grid_overlay.hpp" local="yes" imported="no">rcppsw/ds/base_grid_overlay.hpp</includes>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <class kind="class">rcppsw::ds::grid2D_overlay</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>grid3D.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>grid3D_8hpp.html</filename>
    <includes id="base__grid3D_8hpp" name="base_grid3D.hpp" local="yes" imported="no">rcppsw/ds/base_grid3D.hpp</includes>
    <class kind="class">rcppsw::ds::grid3D</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>grid3D_overlay.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>grid3D__overlay_8hpp.html</filename>
    <includes id="base__grid3D_8hpp" name="base_grid3D.hpp" local="yes" imported="no">rcppsw/ds/base_grid3D.hpp</includes>
    <includes id="base__grid__overlay_8hpp" name="base_grid_overlay.hpp" local="yes" imported="no">rcppsw/ds/base_grid_overlay.hpp</includes>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <class kind="class">rcppsw::ds::grid3D_overlay</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>cell_op.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/metrics/</path>
    <filename>cell__op_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::metrics</namespace>
    <member kind="typedef">
      <type>std::false_type</type>
      <name>cell_accum</name>
      <anchorfile>namespacercppsw_1_1ds_1_1metrics.html</anchorfile>
      <anchor>a0fd0a886443527d9cade0ae0000bcbb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::true_type</type>
      <name>cell_avg</name>
      <anchorfile>namespacercppsw_1_1ds_1_1metrics.html</anchorfile>
      <anchor>a8950dadfb171492419a562b3f4f9713c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>grid2D_metrics_collector.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/metrics/</path>
    <filename>grid2D__metrics__collector_8hpp.html</filename>
    <includes id="base__collector_8hpp" name="base_collector.hpp" local="yes" imported="no">rcppsw/metrics/base_collector.hpp</includes>
    <includes id="grid2D__metrics__data_8hpp" name="grid2D_metrics_data.hpp" local="yes" imported="no">rcppsw/ds/metrics/grid2D_metrics_data.hpp</includes>
    <class kind="class">rcppsw::ds::metrics::grid2D_metrics_collector</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>grid2D_metrics_csv_sink.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/metrics/</path>
    <filename>grid2D__metrics__csv__sink_8hpp.html</filename>
    <includes id="grid2D_8hpp" name="grid2D.hpp" local="yes" imported="no">rcppsw/ds/grid2D.hpp</includes>
    <includes id="csv__sink_8hpp" name="csv_sink.hpp" local="yes" imported="no">rcppsw/metrics/csv_sink.hpp</includes>
    <includes id="grid2D__metrics__data_8hpp" name="grid2D_metrics_data.hpp" local="yes" imported="no">rcppsw/ds/metrics/grid2D_metrics_data.hpp</includes>
    <includes id="cell__op_8hpp" name="cell_op.hpp" local="yes" imported="no">rcppsw/ds/metrics/cell_op.hpp</includes>
    <class kind="class">rcppsw::ds::metrics::grid2D_metrics_csv_sink</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>grid2D_metrics_data.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/metrics/</path>
    <filename>grid2D__metrics__data_8hpp.html</filename>
    <includes id="base__data_8hpp" name="base_data.hpp" local="yes" imported="no">rcppsw/metrics/base_data.hpp</includes>
    <includes id="grid2D_8hpp" name="grid2D.hpp" local="yes" imported="no">rcppsw/ds/grid2D.hpp</includes>
    <includes id="multithread_8hpp" name="multithread.hpp" local="yes" imported="no">rcppsw/al/multithread.hpp</includes>
    <class kind="interface">rcppsw::ds::metrics::grid2D_metrics_data</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>grid3D_metrics_collector.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/metrics/</path>
    <filename>grid3D__metrics__collector_8hpp.html</filename>
    <includes id="base__collector_8hpp" name="base_collector.hpp" local="yes" imported="no">rcppsw/metrics/base_collector.hpp</includes>
    <includes id="grid3D__metrics__data_8hpp" name="grid3D_metrics_data.hpp" local="yes" imported="no">rcppsw/ds/metrics/grid3D_metrics_data.hpp</includes>
    <class kind="class">rcppsw::ds::metrics::grid3D_metrics_collector</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>grid3D_metrics_csv_sink.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/metrics/</path>
    <filename>grid3D__metrics__csv__sink_8hpp.html</filename>
    <includes id="grid3D_8hpp" name="grid3D.hpp" local="yes" imported="no">rcppsw/ds/grid3D.hpp</includes>
    <includes id="csv__sink_8hpp" name="csv_sink.hpp" local="yes" imported="no">rcppsw/metrics/csv_sink.hpp</includes>
    <includes id="cell__op_8hpp" name="cell_op.hpp" local="yes" imported="no">rcppsw/ds/metrics/cell_op.hpp</includes>
    <includes id="grid3D__metrics__data_8hpp" name="grid3D_metrics_data.hpp" local="yes" imported="no">rcppsw/ds/metrics/grid3D_metrics_data.hpp</includes>
    <class kind="class">rcppsw::ds::metrics::grid3D_metrics_csv_sink</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>grid3D_metrics_data.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/metrics/</path>
    <filename>grid3D__metrics__data_8hpp.html</filename>
    <includes id="base__data_8hpp" name="base_data.hpp" local="yes" imported="no">rcppsw/metrics/base_data.hpp</includes>
    <includes id="grid3D_8hpp" name="grid3D.hpp" local="yes" imported="no">rcppsw/ds/grid3D.hpp</includes>
    <includes id="multithread_8hpp" name="multithread.hpp" local="yes" imported="no">rcppsw/al/multithread.hpp</includes>
    <class kind="interface">rcppsw::ds::metrics::grid3D_metrics_data</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>poisson_queue.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>poisson__queue_8hpp.html</filename>
    <includes id="rng_8hpp" name="rng.hpp" local="yes" imported="no">rcppsw/math/rng.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="timestep_8hpp" name="timestep.hpp" local="yes" imported="no">rcppsw/types/timestep.hpp</includes>
    <class kind="class">rcppsw::ds::poisson_queue</class>
    <class kind="struct">rcppsw::ds::poisson_queue::op_metadata</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>rtree.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>rtree_8hpp.html</filename>
    <includes id="vector2_8hpp" name="vector2.hpp" local="yes" imported="no">rcppsw/math/vector2.hpp</includes>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <includes id="decorator_8hpp" name="decorator.hpp" local="yes" imported="no">rcppsw/patterns/decorator/decorator.hpp</includes>
    <class kind="class">rcppsw::ds::rtree</class>
    <class kind="struct">rcppsw::ds::rtree_spec</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
    <member kind="typedef">
      <type>bg::model::box&lt; rtree_point&lt; TCoordType &gt; &gt;</type>
      <name>rtree_box</name>
      <anchorfile>namespacercppsw_1_1ds.html</anchorfile>
      <anchor>ab6204211b4072bc13dc807ed29c4119e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>bg::model::point&lt; typename TCoordType::value_type, TCoordType::kDIMENSIONALITY, bg::cs::cartesian &gt;</type>
      <name>rtree_point</name>
      <anchorfile>namespacercppsw_1_1ds.html</anchorfile>
      <anchor>a54d5b03ae8dd86c3ba54653e4713325e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>rtree_box&lt; TCoordType &gt;</type>
      <name>make_rtree_box</name>
      <anchorfile>namespacercppsw_1_1ds.html</anchorfile>
      <anchor>a7fa16818dd1112e1177d430d5c62fd4d</anchor>
      <arglist>(const TCoordType &amp;ll, const TCoordType &amp;ur)</arglist>
    </member>
    <member kind="function">
      <type>rtree_point&lt; TCoordType &gt;</type>
      <name>make_rtree_point</name>
      <anchorfile>namespacercppsw_1_1ds.html</anchorfile>
      <anchor>aff578e47a24623687163f1e8449538c7</anchor>
      <arglist>(const TCoordType &amp;c)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>stacked_grid2D.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>stacked__grid2D_8hpp.html</filename>
    <includes id="grid2D__overlay_8hpp" name="grid2D_overlay.hpp" local="yes" imported="no">rcppsw/ds/grid2D_overlay.hpp</includes>
    <includes id="vector2_8hpp" name="vector2.hpp" local="yes" imported="no">rcppsw/math/vector2.hpp</includes>
    <includes id="discretize__ratio_8hpp" name="discretize_ratio.hpp" local="yes" imported="no">rcppsw/types/discretize_ratio.hpp</includes>
    <class kind="class">rcppsw::ds::stacked_grid2D</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>type_map.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/ds/</path>
    <filename>type__map_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::ds::type_map</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::ds</namespace>
  </compound>
  <compound kind="file">
    <name>client.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/er/</path>
    <filename>client_8hpp.html</filename>
    <includes id="er_8hpp" name="er.hpp" local="yes" imported="no">rcppsw/er/er.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="er_2macros_8hpp" name="macros.hpp" local="yes" imported="no">rcppsw/er/macros.hpp</includes>
    <class kind="class">rcppsw::er::client</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::er</namespace>
    <member kind="define">
      <type>#define</type>
      <name>ER_CLIENT_INIT</name>
      <anchorfile>client_8hpp.html</anchorfile>
      <anchor>a2e46a4046efab8f06e9e8316c5760a4d</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_ENV_VERIFY</name>
      <anchorfile>client_8hpp.html</anchorfile>
      <anchor>a346305444975cf1d3e5a4b7561ed3529</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_LOGFILE_SET</name>
      <anchorfile>client_8hpp.html</anchorfile>
      <anchor>a7c176ffff4a1b58e73f8efc8e5574c09</anchor>
      <arglist>(logger, fname)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_LOGGING_INIT</name>
      <anchorfile>client_8hpp.html</anchorfile>
      <anchor>abe4fa277755a728eb269076f1829ec26</anchor>
      <arglist>(fname)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_MDC_ADD</name>
      <anchorfile>client_8hpp.html</anchorfile>
      <anchor>ab010a5a440319ce922fee3132f3a7e80</anchor>
      <arglist>(key, value)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_MDC_RM</name>
      <anchorfile>client_8hpp.html</anchorfile>
      <anchor>a444de96b013a54268310717baa33e6c2</anchor>
      <arglist>(key)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_NDC_POP</name>
      <anchorfile>client_8hpp.html</anchorfile>
      <anchor>af6e97e640ae883b78961de065a96627e</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ER_NDC_PUSH</name>
      <anchorfile>client_8hpp.html</anchorfile>
      <anchor>ab7dcc4359c785b1adb41b3aaddf3a810</anchor>
      <arglist>(s)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>er.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/er/</path>
    <filename>er_8hpp.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>LIBRA_ER_ALL</name>
      <anchorfile>er_8hpp.html</anchorfile>
      <anchor>a0513de2aff32d8d79e1c91e13c092a4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>LIBRA_ER_FATAL</name>
      <anchorfile>er_8hpp.html</anchorfile>
      <anchor>a20527fd868e8326d6f5688f6b018170d</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>LIBRA_ER_NONE</name>
      <anchorfile>er_8hpp.html</anchorfile>
      <anchor>a6551d5f2cd31da2caa3860f4d84b5830</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_ER</name>
      <anchorfile>er_8hpp.html</anchorfile>
      <anchor>ae44e3cdede3b012954e89258c0570aeb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_ER_ALL</name>
      <anchorfile>er_8hpp.html</anchorfile>
      <anchor>a7e0d90c199a86067828ae55672e88295</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_ER_FATAL</name>
      <anchorfile>er_8hpp.html</anchorfile>
      <anchor>a6e23d03e90003e24aef9e873ccc8e315</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_ER_FATAL_MSG_LEN_MAX</name>
      <anchorfile>er_8hpp.html</anchorfile>
      <anchor>a54d737c499a19e8ef76de54051db89cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_ER_MSG_LEN_MAX</name>
      <anchorfile>er_8hpp.html</anchorfile>
      <anchor>a0697b9f40c686bdda11e0cd0837e02f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_ER_NONE</name>
      <anchorfile>er_8hpp.html</anchorfile>
      <anchor>a6887501415f5f401a84f4d8e958f3082</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>stacktrace.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/er/</path>
    <filename>stacktrace_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::er</namespace>
    <member kind="define">
      <type>#define</type>
      <name>BOOST_STACKTRACE_USE_ADDR2LINE</name>
      <anchorfile>stacktrace_8hpp.html</anchorfile>
      <anchor>a61e98b5b2367ea3a7a46304630abfadb</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>sigsegv_sighandler</name>
      <anchorfile>namespacercppsw_1_1er.html</anchorfile>
      <anchor>af85843c56e74e1e6ce8822a09d4615ad</anchor>
      <arglist>(int signum)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>terminate_handler</name>
      <anchorfile>namespacercppsw_1_1er.html</anchorfile>
      <anchor>a50ccdc4c3117669b5d38dd117cae9391</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>stringizable.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/er/</path>
    <filename>stringizable_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::er::stringizable</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::er</namespace>
  </compound>
  <compound kind="file">
    <name>angles.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>angles_8hpp.html</filename>
    <includes id="degrees_8hpp" name="degrees.hpp" local="yes" imported="no">rcppsw/math/degrees.hpp</includes>
    <includes id="radians_8hpp" name="radians.hpp" local="yes" imported="no">rcppsw/math/radians.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <member kind="function">
      <type>TAngleType</type>
      <name>abs</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a08642e8d3e916a6836bd252d108b4d30</anchor>
      <arglist>(const TAngleType &amp;angle)</arglist>
    </member>
    <member kind="function">
      <type>degrees</type>
      <name>normalized_diff</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ad9e36b73d4cf7997dd91497a11002a31</anchor>
      <arglist>(const degrees &amp;angle1, const degrees &amp;angle2)</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>normalized_diff</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>acbaaea8cea9c437013e1d809eda674d9</anchor>
      <arglist>(const radians &amp;angle1, const radians &amp;angle2)</arglist>
    </member>
    <member kind="function">
      <type>degrees</type>
      <name>to_degrees</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af5131d3da982b91cdb4ec521ddac59b8</anchor>
      <arglist>(const radians &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>to_radians</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a84f217d997fcca5cc7480e6973607a13</anchor>
      <arglist>(const degrees &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>binned_powerlaw_distribution.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>binned__powerlaw__distribution_8hpp.html</filename>
    <includes id="powerlaw__distribution_8hpp" name="powerlaw_distribution.hpp" local="yes" imported="no">rcppsw/math/powerlaw_distribution.hpp</includes>
    <includes id="rng_8hpp" name="rng.hpp" local="yes" imported="no">rcppsw/math/rng.hpp</includes>
    <class kind="class">rcppsw::math::binned_powerlaw_distribution</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
  </compound>
  <compound kind="file">
    <name>bounding_box.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>bounding__box_8hpp.html</filename>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <includes id="spatial_8hpp" name="spatial.hpp" local="yes" imported="no">rcppsw/math/spatial.hpp</includes>
    <class kind="class">rcppsw::math::bounding_box</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
  </compound>
  <compound kind="file">
    <name>ema_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/config/</path>
    <filename>ema__config_8hpp.html</filename>
    <includes id="base__config_8hpp" name="base_config.hpp" local="yes" imported="no">rcppsw/config/base_config.hpp</includes>
    <class kind="struct">rcppsw::math::config::ema_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::math::config</namespace>
  </compound>
  <compound kind="file">
    <name>rng_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/config/</path>
    <filename>rng__config_8hpp.html</filename>
    <includes id="base__config_8hpp" name="base_config.hpp" local="yes" imported="no">rcppsw/config/base_config.hpp</includes>
    <class kind="struct">rcppsw::math::config::rng_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::math::config</namespace>
  </compound>
  <compound kind="file">
    <name>sigmoid_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/config/</path>
    <filename>sigmoid__config_8hpp.html</filename>
    <includes id="base__config_8hpp" name="base_config.hpp" local="yes" imported="no">rcppsw/config/base_config.hpp</includes>
    <class kind="struct">rcppsw::math::config::sigmoid_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::math::config</namespace>
  </compound>
  <compound kind="file">
    <name>ema_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/config/xml/</path>
    <filename>ema__parser_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="ema__config_8hpp" name="ema_config.hpp" local="yes" imported="no">rcppsw/math/config/ema_config.hpp</includes>
    <includes id="xml__config__parser_8hpp" name="xml_config_parser.hpp" local="yes" imported="no">rcppsw/config/xml/xml_config_parser.hpp</includes>
    <class kind="class">rcppsw::math::config::xml::ema_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::math::config</namespace>
    <namespace>rcppsw::math::config::xml</namespace>
  </compound>
  <compound kind="file">
    <name>rng_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/config/xml/</path>
    <filename>rng__parser_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="rng__config_8hpp" name="rng_config.hpp" local="yes" imported="no">rcppsw/math/config/rng_config.hpp</includes>
    <includes id="xml__config__parser_8hpp" name="xml_config_parser.hpp" local="yes" imported="no">rcppsw/config/xml/xml_config_parser.hpp</includes>
    <class kind="class">rcppsw::math::config::xml::rng_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::math::config</namespace>
    <namespace>rcppsw::math::config::xml</namespace>
  </compound>
  <compound kind="file">
    <name>sigmoid_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/config/xml/</path>
    <filename>sigmoid__parser_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="sigmoid__config_8hpp" name="sigmoid_config.hpp" local="yes" imported="no">rcppsw/math/config/sigmoid_config.hpp</includes>
    <includes id="xml__config__parser_8hpp" name="xml_config_parser.hpp" local="yes" imported="no">rcppsw/config/xml/xml_config_parser.hpp</includes>
    <class kind="class">rcppsw::math::config::xml::sigmoid_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::math::config</namespace>
    <namespace>rcppsw::math::config::xml</namespace>
  </compound>
  <compound kind="file">
    <name>degrees.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>degrees_8hpp.html</filename>
    <includes id="range_8hpp" name="range.hpp" local="yes" imported="no">rcppsw/math/range.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="math_8hpp" name="math.hpp" local="yes" imported="no">rcppsw/math/math.hpp</includes>
    <class kind="class">rcppsw::math::degrees</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ab9a74f174a2ea8affb6bff17a1179394</anchor>
      <arglist>(std::ostream &amp;stream, const degrees &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ema.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>ema_8hpp.html</filename>
    <includes id="expression_8hpp" name="expression.hpp" local="yes" imported="no">rcppsw/math/expression.hpp</includes>
    <class kind="class">rcppsw::math::ema</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator*</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af676ea466603dec88e6310deccc2d150</anchor>
      <arglist>(const ema&lt; T &gt; &amp;lhs, const U &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator*</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a6be779cbac1a588dea6bb6ecfcde24cb</anchor>
      <arglist>(const U &amp;lhs, const ema&lt; T &gt; &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator-</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ac21a96f6ef02624e0dc8742625e7ccce</anchor>
      <arglist>(const ema&lt; T &gt; &amp;lhs, const U &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator-</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af60bd71ea4af6a585f8c02220b5defe5</anchor>
      <arglist>(const U &amp;lhs, const ema&lt; T &gt; &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator/</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ac0b88164561f83eef7ab6c43cd126b6e</anchor>
      <arglist>(const ema&lt; T &gt; &amp;lhs, const double &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator/</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>afd8c377515b4ac3383951e754edc9d20</anchor>
      <arglist>(const U &amp;lhs, const ema&lt; T &gt; &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a53c97519cd1429ba1ea1ace8ba1e0a4c</anchor>
      <arglist>(const T &amp;v, const ema&lt; T &gt; &amp;rhs)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>expression.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>expression_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::math::expression</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
  </compound>
  <compound kind="file">
    <name>ientropy.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>ientropy_8hpp.html</filename>
    <includes id="expression_8hpp" name="expression.hpp" local="yes" imported="no">rcppsw/math/expression.hpp</includes>
    <includes id="radians_8hpp" name="radians.hpp" local="yes" imported="no">rcppsw/math/radians.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::math::ientropy</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
  </compound>
  <compound kind="file">
    <name>math.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>math_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::math::detail</namespace>
    <member kind="typedef">
      <type>decltype(std::declval&lt; T &gt;().length())</type>
      <name>length_func_decltype</name>
      <anchorfile>namespacercppsw_1_1math_1_1detail.html</anchorfile>
      <anchor>a8df4a58ef0ebabc5c34175ea202ab1db</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>is_equal</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ad738db774594efe4405af0852fb67c44</anchor>
      <arglist>(double lhs, double rhs, double tol=kDOUBLE_EPSILON)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>is_multiple_of</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a1a70d2e6d2170629c906200b59da2ade</anchor>
      <arglist>(double x, double y, double tol=kDOUBLE_EPSILON)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static double</type>
      <name>l2norm</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a8b3457a654bdbbf2923603c43b00bab0</anchor>
      <arglist>(const T &amp;lhs, const T &amp;rhs)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static double</type>
      <name>l2norm_squared</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a2666dc7f637c4452c0d51cff46ae07a4</anchor>
      <arglist>(const T &amp;lhs, const T &amp;rhs)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr double</type>
      <name>kDOUBLE_EPSILON</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a3de3b99c93e96d09928476864d7ecf59</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>normalize.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>normalize_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="math_8hpp" name="math.hpp" local="yes" imported="no">rcppsw/math/math.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <member kind="function" static="yes">
      <type>static double</type>
      <name>normalize</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a394f87378955773f4b26f4ee11f8e3c9</anchor>
      <arglist>(double min, double max, double val)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>orientation.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>orientation_8hpp.html</filename>
    <includes id="radians_8hpp" name="radians.hpp" local="yes" imported="no">rcppsw/math/radians.hpp</includes>
    <class kind="class">rcppsw::math::euler_angles</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
  </compound>
  <compound kind="file">
    <name>powerlaw_distribution.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>powerlaw__distribution_8hpp.html</filename>
    <includes id="rng_8hpp" name="rng.hpp" local="yes" imported="no">rcppsw/math/rng.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::math::powerlaw_distribution</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
  </compound>
  <compound kind="file">
    <name>radians.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>radians_8hpp.html</filename>
    <includes id="range_8hpp" name="range.hpp" local="yes" imported="no">rcppsw/math/range.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="math_8hpp" name="math.hpp" local="yes" imported="no">rcppsw/math/math.hpp</includes>
    <includes id="stringizable_8hpp" name="stringizable.hpp" local="yes" imported="no">rcppsw/er/stringizable.hpp</includes>
    <class kind="class">rcppsw::math::radians</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <member kind="function">
      <type>rmath::radians</type>
      <name>operator*</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a502c47e9a9ff5cc05f0424ed28ec799b</anchor>
      <arglist>(double lhs, const rmath::radians &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aca8039f34097e0ab3dbdfe4a05a09cc4</anchor>
      <arglist>(std::ostream &amp;stream, const radians &amp;r)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>range.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>range_8hpp.html</filename>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="string__utils_8hpp" name="string_utils.hpp" local="yes" imported="no">rcppsw/utils/string_utils.hpp</includes>
    <includes id="stringizable_8hpp" name="stringizable.hpp" local="yes" imported="no">rcppsw/er/stringizable.hpp</includes>
    <class kind="class">rcppsw::math::range</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_RANGE_CONV2DISC</name>
      <anchorfile>range_8hpp.html</anchorfile>
      <anchor>a2707a7872c6554ef36da5c1cfaa47a4c</anchor>
      <arglist>(dest_prefix, dest_type)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_RANGE_DIRECT_CONV2FLT</name>
      <anchorfile>range_8hpp.html</anchorfile>
      <anchor>a3e73b5567b118e3df763fcd00cc5fd94</anchor>
      <arglist>(prefix)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_RANGE_SCALED_CONV2FLT</name>
      <anchorfile>range_8hpp.html</anchorfile>
      <anchor>af29ff3af9c0a1925611a9b3219b9b699</anchor>
      <arglist>(prefix)</arglist>
    </member>
    <member kind="typedef">
      <type>range&lt; double &gt;</type>
      <name>ranged</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a5ff0a4d528d5429045da4f1d3fd382f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>range&lt; int &gt;</type>
      <name>rangei</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a94eace0e741aaeada9e9e08d8de34e47</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>range&lt; size_t &gt;</type>
      <name>rangez</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>afc75f115f30ec3888181ea1bdd921e17</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rangez</type>
      <name>drange2zrange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a9c696ef894fd3e9030aacf3b89dec0ba</anchor>
      <arglist>(const rangez &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ranged</type>
      <name>irange2drange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a8d8df93fe4ad4d82761ea7b56bfaee81</anchor>
      <arglist>(const rangei &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ranged</type>
      <name>irange2drange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a9947aa65ad754480dfb5d59827424523</anchor>
      <arglist>(const rangei &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ranged</type>
      <name>zrange2drange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a28a134c46abc211cb7a95e997c856663</anchor>
      <arglist>(const rangez &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ranged</type>
      <name>zrange2drange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ac5b7f20bdffaad00d3c41740b7a59024</anchor>
      <arglist>(const rangez &amp;other, double scale)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>rng.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>rng_8hpp.html</filename>
    <includes id="range_8hpp" name="range.hpp" local="yes" imported="no">rcppsw/math/range.hpp</includes>
    <includes id="pimpl_8hpp" name="pimpl.hpp" local="yes" imported="no">rcppsw/patterns/pimpl/pimpl.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rng</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::math::detail</namespace>
  </compound>
  <compound kind="file">
    <name>rngm.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>rngm_8hpp.html</filename>
    <includes id="caching__factory_8hpp" name="caching_factory.hpp" local="yes" imported="no">rcppsw/patterns/prototype/caching_factory.hpp</includes>
    <includes id="singleton_8hpp" name="singleton.hpp" local="yes" imported="no">rcppsw/patterns/singleton/singleton.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::math::rngm</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
  </compound>
  <compound kind="file">
    <name>sigmoid.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>sigmoid_8hpp.html</filename>
    <includes id="sigmoid__config_8hpp" name="sigmoid_config.hpp" local="yes" imported="no">rcppsw/math/config/sigmoid_config.hpp</includes>
    <includes id="expression_8hpp" name="expression.hpp" local="yes" imported="no">rcppsw/math/expression.hpp</includes>
    <class kind="class">rcppsw::math::sigmoid</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
  </compound>
  <compound kind="file">
    <name>spatial.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>spatial_8hpp.html</filename>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <includes id="vector2_8hpp" name="vector2.hpp" local="yes" imported="no">rcppsw/math/vector2.hpp</includes>
    <includes id="spatial__dist_8hpp" name="spatial_dist.hpp" local="yes" imported="no">rcppsw/types/spatial_dist.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_SPAN_FUNC_DISC</name>
      <anchorfile>spatial_8hpp.html</anchorfile>
      <anchor>ab1761c4cb5784c46eaaad94c96ed2603</anchor>
      <arglist>(component)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_SPAN_FUNC_FLT</name>
      <anchorfile>spatial_8hpp.html</anchorfile>
      <anchor>ab842213e5cb530401fe07d0ef2354d97</anchor>
      <arglist>(component)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::ranged</type>
      <name>xspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a06017d6613cca2a80d4313e9c85abfe8</anchor>
      <arglist>(const TCoord &amp;anchor, const double &amp;dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::rangez</type>
      <name>xspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a5fb321b2ade79ebbfd0ef1f3d41559b8</anchor>
      <arglist>(const TCoord &amp;anchor, size_t dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::ranged</type>
      <name>yspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a11db4f529af511f79b50e6750c81e603</anchor>
      <arglist>(const TCoord &amp;anchor, const double &amp;dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::rangez</type>
      <name>yspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a85847e546ad69933d10d3cfc5f909f10</anchor>
      <arglist>(const TCoord &amp;anchor, size_t dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::ranged</type>
      <name>zspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a706469c24348832bda949a85709dd1d8</anchor>
      <arglist>(const TCoord &amp;anchor, const double &amp;dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::rangez</type>
      <name>zspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a33983279d2ba7a443a8a653056a123b7</anchor>
      <arglist>(const TCoord &amp;anchor, size_t dim)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sphere_vector.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>sphere__vector_8hpp.html</filename>
    <includes id="radians_8hpp" name="radians.hpp" local="yes" imported="no">rcppsw/math/radians.hpp</includes>
    <class kind="class">rcppsw::math::sphere_vector</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
  </compound>
  <compound kind="file">
    <name>vector2.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>vector2_8hpp.html</filename>
    <includes id="radians_8hpp" name="radians.hpp" local="yes" imported="no">rcppsw/math/radians.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="discretize__ratio_8hpp" name="discretize_ratio.hpp" local="yes" imported="no">rcppsw/types/discretize_ratio.hpp</includes>
    <includes id="stringizable_8hpp" name="stringizable.hpp" local="yes" imported="no">rcppsw/er/stringizable.hpp</includes>
    <class kind="class">rcppsw::math::vector2</class>
    <class kind="struct">rcppsw::math::vector2::componentwise_compare</class>
    <class kind="struct">rcppsw::math::vector2::key_compare</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_VEC2_CONV2DISC</name>
      <anchorfile>vector2_8hpp.html</anchorfile>
      <anchor>a867d642347f002235bbcade5a7231665</anchor>
      <arglist>(dest_prefix, dest_type)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_VEC2_DIRECT_CONVF</name>
      <anchorfile>vector2_8hpp.html</anchorfile>
      <anchor>a146127190fb994d3714b251195de4b22</anchor>
      <arglist>(prefix)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_VEC2_SCALED_CONVF</name>
      <anchorfile>vector2_8hpp.html</anchorfile>
      <anchor>a89ca2cc16241d7a099c317cb94416f04</anchor>
      <arglist>(prefix)</arglist>
    </member>
    <member kind="typedef">
      <type>vector2&lt; double &gt;</type>
      <name>vector2d</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aeee4cbfec7ec35d102de51e287b8edeb</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector2&lt; int &gt;</type>
      <name>vector2i</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a5b451219559579141b097391f9fc0e80</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector2&lt; size_t &gt;</type>
      <name>vector2z</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aa61ac5b9e211ad9913993fe03c12af7c</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2i</type>
      <name>dvec2ivec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a14ee837e88234393c8920fb33a0824b3</anchor>
      <arglist>(const vector2d &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2z</type>
      <name>dvec2zvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a4a74ff2c01803969fd82df02945e7953</anchor>
      <arglist>(const vector2d &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2d</type>
      <name>ivec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aa961b26521f8d4bca4d3421461cee713</anchor>
      <arglist>(const vector2i &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2d</type>
      <name>ivec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a670395d2d582fe4ca41d6bb7d44bd940</anchor>
      <arglist>(const vector2i &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static size_t</type>
      <name>l1norm</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a97ff44efd91cc0c6f7bde760e9d62ae1</anchor>
      <arglist>(const vector2&lt; U &gt; &amp;v1, const vector2&lt; V &gt; &amp;v2)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2d</type>
      <name>zvec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a7899ac1ece0936beb822977a9accdfec</anchor>
      <arglist>(const vector2z &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2d</type>
      <name>zvec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ae0228cb269b52f2e835336b600b533aa</anchor>
      <arglist>(const vector2z &amp;other, double scale)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>vector3.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/math/</path>
    <filename>vector3_8hpp.html</filename>
    <includes id="radians_8hpp" name="radians.hpp" local="yes" imported="no">rcppsw/math/radians.hpp</includes>
    <includes id="sphere__vector_8hpp" name="sphere_vector.hpp" local="yes" imported="no">rcppsw/math/sphere_vector.hpp</includes>
    <includes id="vector2_8hpp" name="vector2.hpp" local="yes" imported="no">rcppsw/math/vector2.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="discretize__ratio_8hpp" name="discretize_ratio.hpp" local="yes" imported="no">rcppsw/types/discretize_ratio.hpp</includes>
    <includes id="stringizable_8hpp" name="stringizable.hpp" local="yes" imported="no">rcppsw/er/stringizable.hpp</includes>
    <class kind="class">rcppsw::math::vector3</class>
    <class kind="struct">rcppsw::math::vector3::componentwise_compare</class>
    <class kind="struct">rcppsw::math::vector3::key_compare</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::math</namespace>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_VEC3_CONV2DISC</name>
      <anchorfile>vector3_8hpp.html</anchorfile>
      <anchor>ab614500b7244cb771163840bf272433a</anchor>
      <arglist>(dest_prefix, dest_type)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_VEC3_DIRECT_CONV2FLT</name>
      <anchorfile>vector3_8hpp.html</anchorfile>
      <anchor>a63b83599fd7a2a3ceb1d533de12e08bc</anchor>
      <arglist>(prefix)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_MATH_VEC3_SCALED_CONV2FLT</name>
      <anchorfile>vector3_8hpp.html</anchorfile>
      <anchor>a86aae9da4652f9e2ccc53cca4254e6c2</anchor>
      <arglist>(prefix)</arglist>
    </member>
    <member kind="typedef">
      <type>vector3&lt; double &gt;</type>
      <name>vector3d</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af66a56a5aa1b099f8fa9da9a346847f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector3&lt; int &gt;</type>
      <name>vector3i</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a013f4548331430677be3d5c65796845a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector3&lt; size_t &gt;</type>
      <name>vector3z</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a72e9a2c7f7fb0b33f22a664371912a36</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3i</type>
      <name>dvec2ivec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af7679ef40e012ce00d194ceaf7c536b8</anchor>
      <arglist>(const vector3d &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3z</type>
      <name>dvec2zvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a08e7a8d5d252fa7672c53e387bd6b807</anchor>
      <arglist>(const vector3d &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3d</type>
      <name>ivec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a0a921ed8e23896267d945d86340ffd1d</anchor>
      <arglist>(const vector3i &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3d</type>
      <name>ivec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aff1888ba00c80210c00d8c55ee0dba2d</anchor>
      <arglist>(const vector3i &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static size_t</type>
      <name>l1norm</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a3da7d798817b70e4de41527fabdbfc2f</anchor>
      <arglist>(const vector3&lt; U &gt; &amp;v1, const vector3&lt; V &gt; &amp;v2)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3d</type>
      <name>zvec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a6590e524799ca25849ac5a49f93e07ee</anchor>
      <arglist>(const vector3z &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3d</type>
      <name>zvec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a454f55be44625cec03576bd2641e4a96</anchor>
      <arglist>(const vector3z &amp;other, double scale)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>base_collector.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>base__collector_8hpp.html</filename>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="timestep_8hpp" name="timestep.hpp" local="yes" imported="no">rcppsw/types/timestep.hpp</includes>
    <includes id="write__status_8hpp" name="write_status.hpp" local="yes" imported="no">rcppsw/metrics/write_status.hpp</includes>
    <includes id="base__data_8hpp" name="base_data.hpp" local="yes" imported="no">rcppsw/metrics/base_data.hpp</includes>
    <includes id="base__sink_8hpp" name="base_sink.hpp" local="yes" imported="no">rcppsw/metrics/base_sink.hpp</includes>
    <class kind="class">rcppsw::metrics::base_collector</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>base_data.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>base__data_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="interface">rcppsw::metrics::base_data</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>base_manager.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>base__manager_8hpp.html</filename>
    <includes id="vector2_8hpp" name="vector2.hpp" local="yes" imported="no">rcppsw/math/vector2.hpp</includes>
    <includes id="vector3_8hpp" name="vector3.hpp" local="yes" imported="no">rcppsw/math/vector3.hpp</includes>
    <includes id="collector__group_8hpp" name="collector_group.hpp" local="yes" imported="no">rcppsw/metrics/collector_group.hpp</includes>
    <includes id="output__mode_8hpp" name="output_mode.hpp" local="yes" imported="no">rcppsw/metrics/output_mode.hpp</includes>
    <class kind="class">rcppsw::metrics::base_manager</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>base_metrics.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>base__metrics_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="interface">rcppsw::metrics::base_metrics</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>base_sink.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>base__sink_8hpp.html</filename>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="write__status_8hpp" name="write_status.hpp" local="yes" imported="no">rcppsw/metrics/write_status.hpp</includes>
    <includes id="timestep_8hpp" name="timestep.hpp" local="yes" imported="no">rcppsw/types/timestep.hpp</includes>
    <includes id="base__data_8hpp" name="base_data.hpp" local="yes" imported="no">rcppsw/metrics/base_data.hpp</includes>
    <includes id="output__mode_8hpp" name="output_mode.hpp" local="yes" imported="no">rcppsw/metrics/output_mode.hpp</includes>
    <class kind="class">rcppsw::metrics::base_sink</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>collector_group.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>collector__group_8hpp.html</filename>
    <includes id="base__collector_8hpp" name="base_collector.hpp" local="yes" imported="no">rcppsw/metrics/base_collector.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="write__status_8hpp" name="write_status.hpp" local="yes" imported="no">rcppsw/metrics/write_status.hpp</includes>
    <class kind="class">rcppsw::metrics::collector_group</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>file_sink_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/config/</path>
    <filename>file__sink__config_8hpp.html</filename>
    <includes id="base__config_8hpp" name="base_config.hpp" local="yes" imported="no">rcppsw/config/base_config.hpp</includes>
    <includes id="output__mode__config_8hpp" name="output_mode_config.hpp" local="yes" imported="no">rcppsw/metrics/config/output_mode_config.hpp</includes>
    <class kind="struct">rcppsw::metrics::config::file_sink_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::config</namespace>
  </compound>
  <compound kind="file">
    <name>metrics_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/config/</path>
    <filename>metrics__config_8hpp.html</filename>
    <includes id="base__config_8hpp" name="base_config.hpp" local="yes" imported="no">rcppsw/config/base_config.hpp</includes>
    <includes id="file__sink__config_8hpp" name="file_sink_config.hpp" local="yes" imported="no">rcppsw/metrics/config/file_sink_config.hpp</includes>
    <includes id="network__sink__config_8hpp" name="network_sink_config.hpp" local="yes" imported="no">rcppsw/metrics/config/network_sink_config.hpp</includes>
    <class kind="struct">rcppsw::metrics::config::metrics_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::config</namespace>
  </compound>
  <compound kind="file">
    <name>network_sink_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/config/</path>
    <filename>network__sink__config_8hpp.html</filename>
    <includes id="base__config_8hpp" name="base_config.hpp" local="yes" imported="no">rcppsw/config/base_config.hpp</includes>
    <includes id="output__mode__config_8hpp" name="output_mode_config.hpp" local="yes" imported="no">rcppsw/metrics/config/output_mode_config.hpp</includes>
    <class kind="struct">rcppsw::metrics::config::network_sink_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::config</namespace>
  </compound>
  <compound kind="file">
    <name>output_mode_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/config/</path>
    <filename>output__mode__config_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="timestep_8hpp" name="timestep.hpp" local="yes" imported="no">rcppsw/types/timestep.hpp</includes>
    <class kind="struct">rcppsw::metrics::config::output_mode_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::config</namespace>
  </compound>
  <compound kind="file">
    <name>base_sink_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/config/xml/</path>
    <filename>base__sink__parser_8hpp.html</filename>
    <includes id="xml__config__parser_8hpp" name="xml_config_parser.hpp" local="yes" imported="no">rcppsw/config/xml/xml_config_parser.hpp</includes>
    <includes id="output__mode__config_8hpp" name="output_mode_config.hpp" local="yes" imported="no">rcppsw/metrics/config/output_mode_config.hpp</includes>
    <class kind="class">rcppsw::metrics::config::xml::base_sink_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::config</namespace>
    <namespace>rcppsw::metrics::config::xml</namespace>
  </compound>
  <compound kind="file">
    <name>file_sink_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/config/xml/</path>
    <filename>file__sink__parser_8hpp.html</filename>
    <includes id="base__sink__parser_8hpp" name="base_sink_parser.hpp" local="yes" imported="no">rcppsw/metrics/config/xml/base_sink_parser.hpp</includes>
    <includes id="file__sink__config_8hpp" name="file_sink_config.hpp" local="yes" imported="no">rcppsw/metrics/config/file_sink_config.hpp</includes>
    <class kind="class">rcppsw::metrics::config::xml::file_sink_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::config</namespace>
    <namespace>rcppsw::metrics::config::xml</namespace>
  </compound>
  <compound kind="file">
    <name>metrics_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/config/xml/</path>
    <filename>metrics__parser_8hpp.html</filename>
    <includes id="xml__config__parser_8hpp" name="xml_config_parser.hpp" local="yes" imported="no">rcppsw/config/xml/xml_config_parser.hpp</includes>
    <includes id="file__sink__parser_8hpp" name="file_sink_parser.hpp" local="yes" imported="no">rcppsw/metrics/config/xml/file_sink_parser.hpp</includes>
    <includes id="network__sink__parser_8hpp" name="network_sink_parser.hpp" local="yes" imported="no">rcppsw/metrics/config/xml/network_sink_parser.hpp</includes>
    <includes id="metrics__config_8hpp" name="metrics_config.hpp" local="yes" imported="no">rcppsw/metrics/config/metrics_config.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::metrics::config::xml::metrics_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::config</namespace>
    <namespace>rcppsw::metrics::config::xml</namespace>
  </compound>
  <compound kind="file">
    <name>network_sink_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/config/xml/</path>
    <filename>network__sink__parser_8hpp.html</filename>
    <includes id="base__sink__parser_8hpp" name="base_sink_parser.hpp" local="yes" imported="no">rcppsw/metrics/config/xml/base_sink_parser.hpp</includes>
    <includes id="network__sink__config_8hpp" name="network_sink_config.hpp" local="yes" imported="no">rcppsw/metrics/config/network_sink_config.hpp</includes>
    <class kind="class">rcppsw::metrics::config::xml::network_sink_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::config</namespace>
    <namespace>rcppsw::metrics::config::xml</namespace>
  </compound>
  <compound kind="file">
    <name>creatable_collector_set.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>creatable__collector__set_8hpp.html</filename>
    <includes id="output__mode_8hpp" name="output_mode.hpp" local="yes" imported="no">rcppsw/metrics/output_mode.hpp</includes>
    <includes id="base__sink_8hpp" name="base_sink.hpp" local="yes" imported="no">rcppsw/metrics/base_sink.hpp</includes>
    <class kind="struct">rcppsw::metrics::collector_registration_spec</class>
    <class kind="struct">rcppsw::metrics::creatable_collector_spec</class>
    <class kind="struct">rcppsw::metrics::detail::creatable_collector_set_comparator</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::detail</namespace>
    <member kind="typedef">
      <type>std::multiset&lt; creatable_collector_spec, detail::creatable_collector_set_comparator &gt;</type>
      <name>creatable_collector_set</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>adc89b6e34f69346cce13197bc5c01330</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>csv_sink.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>csv__sink_8hpp.html</filename>
    <includes id="file__sink_8hpp" name="file_sink.hpp" local="yes" imported="no">rcppsw/metrics/file_sink.hpp</includes>
    <includes id="output__mode_8hpp" name="output_mode.hpp" local="yes" imported="no">rcppsw/metrics/output_mode.hpp</includes>
    <class kind="class">rcppsw::metrics::csv_sink</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>file_sink.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>file__sink_8hpp.html</filename>
    <includes id="base__sink_8hpp" name="base_sink.hpp" local="yes" imported="no">rcppsw/metrics/base_sink.hpp</includes>
    <class kind="class">rcppsw::metrics::file_sink</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>file_sink_registerer.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>file__sink__registerer_8hpp.html</filename>
    <includes id="file__sink__config_8hpp" name="file_sink_config.hpp" local="yes" imported="no">rcppsw/metrics/config/file_sink_config.hpp</includes>
    <includes id="fs__output__manager_8hpp" name="fs_output_manager.hpp" local="yes" imported="no">rcppsw/metrics/fs_output_manager.hpp</includes>
    <includes id="maskable__enum_8hpp" name="maskable_enum.hpp" local="yes" imported="no">rcppsw/utils/maskable_enum.hpp</includes>
    <includes id="creatable__collector__set_8hpp" name="creatable_collector_set.hpp" local="yes" imported="no">rcppsw/metrics/creatable_collector_set.hpp</includes>
    <includes id="file__sink_8hpp" name="file_sink.hpp" local="yes" imported="no">rcppsw/metrics/file_sink.hpp</includes>
    <class kind="class">rcppsw::metrics::file_sink_registerer</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>fs_output_manager.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>fs__output__manager_8hpp.html</filename>
    <includes id="base__manager_8hpp" name="base_manager.hpp" local="yes" imported="no">rcppsw/metrics/base_manager.hpp</includes>
    <includes id="metrics__config_8hpp" name="metrics_config.hpp" local="yes" imported="no">rcppsw/metrics/config/metrics_config.hpp</includes>
    <class kind="class">rcppsw::metrics::fs_output_manager</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>network_output_manager.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>network__output__manager_8hpp.html</filename>
    <includes id="base__manager_8hpp" name="base_manager.hpp" local="yes" imported="no">rcppsw/metrics/base_manager.hpp</includes>
    <includes id="metrics__config_8hpp" name="metrics_config.hpp" local="yes" imported="no">rcppsw/metrics/config/metrics_config.hpp</includes>
    <class kind="class">rcppsw::metrics::network_output_manager</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>network_sink.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>network__sink_8hpp.html</filename>
    <includes id="base__sink_8hpp" name="base_sink.hpp" local="yes" imported="no">rcppsw/metrics/base_sink.hpp</includes>
    <class kind="class">rcppsw::metrics::network_sink</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>network_sink_registerer.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>network__sink__registerer_8hpp.html</filename>
    <includes id="network__sink__config_8hpp" name="network_sink_config.hpp" local="yes" imported="no">rcppsw/metrics/config/network_sink_config.hpp</includes>
    <includes id="network__output__manager_8hpp" name="network_output_manager.hpp" local="yes" imported="no">rcppsw/metrics/network_output_manager.hpp</includes>
    <includes id="maskable__enum_8hpp" name="maskable_enum.hpp" local="yes" imported="no">rcppsw/utils/maskable_enum.hpp</includes>
    <includes id="creatable__collector__set_8hpp" name="creatable_collector_set.hpp" local="yes" imported="no">rcppsw/metrics/creatable_collector_set.hpp</includes>
    <includes id="network__sink_8hpp" name="network_sink.hpp" local="yes" imported="no">rcppsw/metrics/network_sink.hpp</includes>
    <class kind="class">rcppsw::metrics::network_sink_registerer</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>output_mode.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>output__mode_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <member kind="enumeration">
      <type></type>
      <name>output_mode</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>ac42f08cd0253142d3dacdf5339f3587f</anchor>
      <arglist></arglist>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587fa46ea291249caff31653a439e2a7fed9c">ekNONE</enumvalue>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587faeb6d39ff8f11b0c4148abaf0b9da90c5">ekAPPEND</enumvalue>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587fa36e7d4cce81688522a04e5435c1512d9">ekTRUNCATE</enumvalue>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587fa46f4cb8693fdba815a1187d688f3580e">ekCREATE</enumvalue>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587fafcb9fec17836aea1b6069f9d19f72f50">ekSTREAM</enumvalue>
    </member>
  </compound>
  <compound kind="file">
    <name>register_using_config.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>register__using__config_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::metrics::register_using_config</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>register_with_sink.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>register__with__sink_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="base__manager_8hpp" name="base_manager.hpp" local="yes" imported="no">rcppsw/metrics/base_manager.hpp</includes>
    <includes id="creatable__collector__set_8hpp" name="creatable_collector_set.hpp" local="yes" imported="no">rcppsw/metrics/creatable_collector_set.hpp</includes>
    <class kind="class">rcppsw::metrics::register_with_sink</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
  </compound>
  <compound kind="file">
    <name>write_status.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/metrics/</path>
    <filename>write__status_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::metrics</namespace>
    <member kind="enumeration">
      <type></type>
      <name>write_status</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a9deb89f55ed769b27bdaf97be97c3d5b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekNO_ATTEMPT</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a9deb89f55ed769b27bdaf97be97c3d5baa58c01134d64c97192932b3f98d2647d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekFAILED</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a9deb89f55ed769b27bdaf97be97c3d5bab30168a8c0e4f097972513b87708bdc6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekSUCCESS</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a9deb89f55ed769b27bdaf97be97c3d5ba2dbb241488e975a9a3ff19065d293570</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>identity.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/mpl/</path>
    <filename>identity_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::mpl::identity</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::mpl</namespace>
  </compound>
  <compound kind="file">
    <name>mpl.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/mpl/</path>
    <filename>mpl_8hpp.html</filename>
    <includes id="common_2macros_8hpp" name="macros.hpp" local="yes" imported="no">rcppsw/common/macros.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="struct">rcppsw::mpl::can_static_cast</class>
    <class kind="struct">rcppsw::mpl::can_static_cast&lt; T, U, std::void_t&lt; decltype(static_cast&lt; U &gt;(std::declval&lt; T &gt;()))&gt; &gt;</class>
    <class kind="struct">rcppsw::mpl::detail::detector</class>
    <class kind="struct">rcppsw::mpl::detail::detector&lt; TFailType, std::void_t&lt; TFuncDecltype&lt; Args... &gt; &gt;, TFuncDecltype, Args... &gt;</class>
    <class kind="struct">rcppsw::mpl::is_specialization</class>
    <class kind="struct">rcppsw::mpl::is_specialization&lt; Template&lt; Args... &gt;, Template &gt;</class>
    <class kind="struct">rcppsw::mpl::no_such_trait</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::mpl</namespace>
    <namespace>rcppsw::mpl::detail</namespace>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_SFINAE_TYPE</name>
      <anchorfile>mpl_8hpp.html</anchorfile>
      <anchor>a4928a444989162770db738ddf8c3e0a1</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="typedef">
      <type>detail::detector&lt; TFailType, void, TFuncDecltype, Args... &gt;</type>
      <name>detected_or</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a06f783c764e189077611aff2eb5b3677</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename detail::detector&lt; no_such_trait, void, TFuncDecltype, Args... &gt;::type</type>
      <name>detected_t</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a03714aecbca890aef4edc33a86e331c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename detail::detector&lt; no_such_trait, void, TFuncDecltype, Args... &gt;::value</type>
      <name>is_detected</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>aa2874711ad74f595a443da11e77fdbf2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>reflectable.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/mpl/</path>
    <filename>reflectable_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::mpl::reflectable</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::mpl</namespace>
  </compound>
  <compound kind="file">
    <name>typelist.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/mpl/</path>
    <filename>typelist_8hpp.html</filename>
    <includes id="common_8hpp" name="common.hpp" local="yes" imported="no">rcppsw/common/common.hpp</includes>
    <includes id="mpl_8hpp" name="mpl.hpp" local="yes" imported="no">rcppsw/mpl/mpl.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="struct">rcppsw::mpl::detail::ExtendTList</class>
    <class kind="struct">rcppsw::mpl::detail::ExtendTList&lt; std::tuple&lt; Ts... &gt;, T &gt;</class>
    <class kind="struct">rcppsw::mpl::detail::ExtendTList&lt; std::tuple&lt; void &gt;, T &gt;</class>
    <class kind="struct">rcppsw::mpl::detail::rename_impl</class>
    <class kind="struct">rcppsw::mpl::detail::rename_impl&lt; A&lt; T... &gt;, B &gt;</class>
    <class kind="struct">rcppsw::mpl::typelist_wrap_into</class>
    <class kind="struct">rcppsw::mpl::typelist_wrap_into::apply</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::mpl</namespace>
    <namespace>rcppsw::mpl::detail</namespace>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_SFINAE_TYPELIST_REJECT</name>
      <anchorfile>typelist_8hpp.html</anchorfile>
      <anchor>af00a3972c57e6bbb43d017e6cca6f543</anchor>
      <arglist>(Typelist, T)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_SFINAE_TYPELIST_REQUIRE</name>
      <anchorfile>typelist_8hpp.html</anchorfile>
      <anchor>a30edd63818e9cff35a4db192dc8af59f</anchor>
      <arglist>(Typelist, T)</arglist>
    </member>
    <member kind="typedef">
      <type>boost::mpl::empty&lt; Ts... &gt;</type>
      <name>empty</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a95f260d74410ea011c23268337bd9d02</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename boost::mpl::fold&lt; typename boost::mpl::fold&lt; Seq, boost::mpl::set&lt;&gt;, boost::mpl::insert&lt; boost::mpl::_1, boost::mpl::_2 &gt; &gt;::type, boost::tuple&lt; void &gt;, detail::ExtendTList&lt; boost::mpl::_1, boost::mpl::_2 &gt; &gt;</type>
      <name>make_tuple_type</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a7253bb9de384d7440b6631c56dd4fea3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename detail::rename_impl&lt; A, B &gt;</type>
      <name>rename</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a8f16170d63177182637c57126fa14c70</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::mpl::vector&lt; Ts... &gt;</type>
      <name>typelist</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a087641491e12b257b1c6ecf5414aa192</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename boost::mpl::transform&lt; Typelist, typelist_wrap_into&lt; WrapperType, Args... &gt; &gt;</type>
      <name>typelist_wrap_apply</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>af62bfb86a6e582b117607194c2e0ec8e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>forkable.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/multiprocess/</path>
    <filename>forkable_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::multiprocess::forkable</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::multiprocess</namespace>
  </compound>
  <compound kind="file">
    <name>ipc.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/multiprocess/</path>
    <filename>ipc_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::multiprocess</namespace>
  </compound>
  <compound kind="file">
    <name>ipc_queue.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/multiprocess/</path>
    <filename>ipc__queue_8hpp.html</filename>
    <includes id="ipc_8hpp" name="ipc.hpp" local="yes" imported="no">rcppsw/multiprocess/ipc.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::multiprocess::ipc_queue</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::multiprocess</namespace>
  </compound>
  <compound kind="file">
    <name>lockable.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/multithread/</path>
    <filename>lockable_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::multithread::lockable</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::multithread</namespace>
  </compound>
  <compound kind="file">
    <name>mt_fsm.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/multithread/</path>
    <filename>mt__fsm_8hpp.html</filename>
    <includes id="base__fsm_8hpp" name="base_fsm.hpp" local="yes" imported="no">rcppsw/patterns/fsm/base_fsm.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::multithread::mt_fsm</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::multithread</namespace>
  </compound>
  <compound kind="file">
    <name>mt_queue.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/multithread/</path>
    <filename>mt__queue_8hpp.html</filename>
    <includes id="decorator_8hpp" name="decorator.hpp" local="yes" imported="no">rcppsw/patterns/decorator/decorator.hpp</includes>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::multithread::mt_queue</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::multithread</namespace>
  </compound>
  <compound kind="file">
    <name>mt_vector.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/multithread/</path>
    <filename>mt__vector_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::multithread::mt_vector</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::multithread</namespace>
  </compound>
  <compound kind="file">
    <name>threadable.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/multithread/</path>
    <filename>threadable_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::multithread::threadable</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::multithread</namespace>
  </compound>
  <compound kind="file">
    <name>decorator.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/decorator/</path>
    <filename>decorator_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::decorator::decorator</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::decorator</namespace>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_DECORATE_CT</name>
      <anchorfile>decorator_8hpp.html</anchorfile>
      <anchor>a176a5c0ce692ad036e0ee365520f4fe8</anchor>
      <arglist>(...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>decorator_8hpp.html</anchorfile>
      <anchor>a806cbfcb6fd695462ee45a08525360e4</anchor>
      <arglist>(Name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>decorator_8hpp.html</anchorfile>
      <anchor>a95ec2800347ba0818c0cafe374c20267</anchor>
      <arglist>(Func,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>decorator_8hpp.html</anchorfile>
      <anchor>ae61d423fbb7e3fb1f7862815da772b65</anchor>
      <arglist>(Class, Func,...)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>base_factory.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/factory/</path>
    <filename>base__factory_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::factory::detail::base_factory</class>
    <class kind="struct">rcppsw::patterns::factory::detail::factory_releasing_type</class>
    <class kind="struct">rcppsw::patterns::factory::detail::factory_sharing_type</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::factory</namespace>
    <namespace>rcppsw::patterns::factory::detail</namespace>
  </compound>
  <compound kind="file">
    <name>factory.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/factory/</path>
    <filename>factory_8hpp.html</filename>
    <includes id="base__factory_8hpp" name="base_factory.hpp" local="yes" imported="no">rcppsw/patterns/factory/base_factory.hpp</includes>
    <class kind="class">rcppsw::patterns::factory::releasing_factory</class>
    <class kind="class">rcppsw::patterns::factory::sharing_factory</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::factory</namespace>
  </compound>
  <compound kind="file">
    <name>multifactory.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/factory/</path>
    <filename>multifactory_8hpp.html</filename>
    <includes id="base__factory_8hpp" name="base_factory.hpp" local="yes" imported="no">rcppsw/patterns/factory/base_factory.hpp</includes>
    <includes id="singleton_8hpp" name="singleton.hpp" local="yes" imported="no">rcppsw/patterns/singleton/singleton.hpp</includes>
    <class kind="class">rcppsw::patterns::factory::detail::factory_singleton</class>
    <class kind="class">rcppsw::patterns::factory::detail::multifactory</class>
    <class kind="class">releasing_multifactory</class>
    <class kind="class">sharing_multifactory</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::factory</namespace>
    <namespace>rcppsw::patterns::factory::detail</namespace>
  </compound>
  <compound kind="file">
    <name>base_fsm.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>base__fsm_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="event_8hpp" name="event.hpp" local="yes" imported="no">rcppsw/patterns/fsm/event.hpp</includes>
    <includes id="state__action_8hpp" name="state_action.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_action.hpp</includes>
    <includes id="state__entry__action_8hpp" name="state_entry_action.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_entry_action.hpp</includes>
    <includes id="state__exit__action_8hpp" name="state_exit_action.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_exit_action.hpp</includes>
    <includes id="state__guard__action_8hpp" name="state_guard_action.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_guard_action.hpp</includes>
    <includes id="state__map__ex__row_8hpp" name="state_map_ex_row.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_map_ex_row.hpp</includes>
    <includes id="state__map__row_8hpp" name="state_map_row.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_map_row.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::base_fsm</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_DECLARE_STATE_MAP</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>ad21add893b4681b75f3330628a9cef82</anchor>
      <arglist>(type, name, n_entries)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_DEFINE_STATE_MAP</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a106e381ed3ccaa73c3ca8df4b21dbfe4</anchor>
      <arglist>(name,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_DEFINE_STATE_MAP_ACCESSOR</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>abb60c7531dd9aaec7ed7f797ac7166ed</anchor>
      <arglist>(type, index_var)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_DEFINE_TRANSITION_MAP</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>abceeba8f37d7e7c986f645648c5f6200</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_ENTRY_DECLARE</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a899d8a585175deaa1746e08c13ff6311</anchor>
      <arglist>(FSM, entry_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_ENTRY_DECLARE_ND</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a2624e7a7327f14d75f95a16f06cb5afb</anchor>
      <arglist>(FSM, entry_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_ENTRY_DEFINE</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a26c186919a4b2b4eb6c315a0e60ea3e6</anchor>
      <arglist>(FSM, entry_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_ENTRY_DEFINE_ND</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a6fba88c00121f3415eadc41d24dd6b23</anchor>
      <arglist>(FSM, entry_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_EXIT_DECLARE</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>ace47defe883cbf0d3c52908986e1909d</anchor>
      <arglist>(FSM, exit_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_EXIT_DEFINE</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>aa0ea31c0c20490670454ed0629b15783</anchor>
      <arglist>(FSM, exit_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_GUARD_DECLARE</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a82ae35b954317bea77f350c4ed32a9bf</anchor>
      <arglist>(FSM, guard_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_GUARD_DECLARE_ND</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a7b80757aca15251a256e84f3a6c13bb4</anchor>
      <arglist>(FSM, guard_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_GUARD_DEFINE</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a93e6f3fbe0a7e14dee20dfbea8a14bf9</anchor>
      <arglist>(FSM, guard_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_GUARD_DEFINE_ND</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a57affe48a2f92f5de10b91c860eea23f</anchor>
      <arglist>(FSM, guard_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_STATE_DECLARE</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>afff2e8f7a83c8194d66d3b1bfe099070</anchor>
      <arglist>(FSM, state_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_STATE_DECLARE_ND</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a1cdd9d06658832382a2c9c063330a615</anchor>
      <arglist>(FSM, state_name,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_STATE_DEFINE</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>ae44cf11beab465c0a6008120ff3ccfe7</anchor>
      <arglist>(FSM, state_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_STATE_DEFINE_ND</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a34b5e6fa39098c75b439136d7281910e</anchor>
      <arglist>(FSM, state_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_STATE_MAP_ENTRY</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>ac7b9bc6fd0af7e1404d63fa93c025fbd</anchor>
      <arglist>(state_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_STATE_MAP_ENTRY_EX</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>af92a64de21c45a2308fd8c006acd677a</anchor>
      <arglist>(state_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_STATE_MAP_ENTRY_EX_ALL</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a9aaafb3db64e0b2d268d22d092571753</anchor>
      <arglist>( state_name, guard_name, entry_name, exit_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_FSM_VERIFY_TRANSITION_MAP</name>
      <anchorfile>base__fsm_8hpp.html</anchorfile>
      <anchor>a02dcb91b382a63d1c6cb9d4b73acf189</anchor>
      <arglist>(name, n_entries)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>event.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>event_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::event_data</class>
    <class kind="class">rcppsw::patterns::fsm::event_signal</class>
    <class kind="class">rcppsw::patterns::fsm::event_type</class>
    <class kind="class">rcppsw::patterns::fsm::no_event_data</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>hfsm.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>hfsm_8hpp.html</filename>
    <includes id="base__fsm_8hpp" name="base_fsm.hpp" local="yes" imported="no">rcppsw/patterns/fsm/base_fsm.hpp</includes>
    <includes id="hfsm__state_8hpp" name="hfsm_state.hpp" local="yes" imported="no">rcppsw/patterns/fsm/hfsm_state.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::hfsm</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_CONSTRUCT_STATE</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a569b518ce0c2a22dd23e33f247d23c8f</anchor>
      <arglist>(state_name, parent)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_DECLARE_STATE_MAP</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a7f6ff8b7c300043296606ac06ef34b77</anchor>
      <arglist>(type, name, n_entries)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_DEFINE_STATE_MAP</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a7c0378cf6ef0957182091c676ba82751</anchor>
      <arglist>(name,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_DEFINE_STATE_MAP_ACCESSOR</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>abfeb3292116c0baa3c634018527e10e8</anchor>
      <arglist>(type, index_var)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_DEFINE_TRANSITION_MAP</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a421bdfc9f5d2cb0881d70a5412006f10</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_ENTRY_DECLARE</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>ae55ddb8922ba607d9048e9a70a22c859</anchor>
      <arglist>(FSM, entry_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_ENTRY_DECLARE_ND</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>ad25721f37609784248bc1ff819eafec6</anchor>
      <arglist>(FSM, entry_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_ENTRY_DEFINE</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a4b501816fa38c10af91143cf8f05ee2f</anchor>
      <arglist>(FSM, entry_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_ENTRY_DEFINE_ND</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>ae16ba8a406aeba812960edf4854e8f0d</anchor>
      <arglist>(FSM, entry_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_ENTRY_INHERIT</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>afdd984d6d11d319f3e40ba93f69cf619</anchor>
      <arglist>(BASE_FSM, inherited_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_ENTRY_INHERIT_ND</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>afa76ce030542ff10168d5e1a602d7c15</anchor>
      <arglist>(BASE_FSM, inherited_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_EXIT_DECLARE</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a84284e1085bf1270f34eaa76080336b0</anchor>
      <arglist>(FSM, exit_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_EXIT_DEFINE</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>afbb29ae58bfc03e0cb7b279e189e13d8</anchor>
      <arglist>(FSM, exit_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_EXIT_INHERIT</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a38daed0017442d091d5af00ef7d9f122</anchor>
      <arglist>(BASE_FSM, inherited_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_GUARD_DECLARE</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a0e034c5b8f888aa43830a9f0c383864f</anchor>
      <arglist>(FSM, guard_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_GUARD_DECLARE_ND</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a218c9be47acb4e88ad3acb2f1160c6b2</anchor>
      <arglist>(FSM, guard_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_GUARD_DEFINE</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>ab17273d0044fa6410dd4e8e50a01a0d1</anchor>
      <arglist>(FSM, guard_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_GUARD_DEFINE_ND</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a4396f62ea3e6282b8cda88e0458c3e85</anchor>
      <arglist>(FSM, guard_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_STATE_DECLARE</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>aba8c7a247769dee1d78993fe82ee40c7</anchor>
      <arglist>(FSM, state_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_STATE_DECLARE_ND</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>ab82ea118a1a446e2d0a443cc92385348</anchor>
      <arglist>(FSM, state_name,...)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_STATE_DEFINE</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>ab012438d01b1a63f12fb8d10f1aca637</anchor>
      <arglist>(FSM, state_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_STATE_DEFINE_ND</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a42c377a10ebc484d2e3a52a895b98bde</anchor>
      <arglist>(FSM, state_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_STATE_INHERIT</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a8434ed2a98fe974ab7d30192b9f79528</anchor>
      <arglist>(BASE_FSM, inherited_name, event_data)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_STATE_INHERIT_ND</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a6e5e2e1d6445d61b2870e8e8ec97feba</anchor>
      <arglist>(BASE_FSM, inherited_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_STATE_MAP_ENTRY</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>abcf7d939058780b62676d74c3735c01d</anchor>
      <arglist>(state_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_STATE_MAP_ENTRY_EX</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a0e3c64f1b88dcdb873a8fe21cfe503af</anchor>
      <arglist>(state_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_STATE_MAP_ENTRY_EX_ALL</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>a9bbfbe999eb67a0d258763e84a7cf4d5</anchor>
      <arglist>( state_name, guard_name, entry_name, exit_name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RCPPSW_HFSM_VERIFY_TRANSITION_MAP</name>
      <anchorfile>hfsm_8hpp.html</anchorfile>
      <anchor>aa99f0fc82151b8165402891688f4cbb3</anchor>
      <arglist>(name, n_entries)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>hfsm_state.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>hfsm__state_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="event_8hpp" name="event.hpp" local="yes" imported="no">rcppsw/patterns/fsm/event.hpp</includes>
    <includes id="state_8hpp" name="state.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::hfsm_state</class>
    <class kind="class">rcppsw::patterns::fsm::hfsm_state_action0</class>
    <class kind="class">rcppsw::patterns::fsm::hfsm_state_action1</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>simple_fsm.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>simple__fsm_8hpp.html</filename>
    <includes id="base__fsm_8hpp" name="base_fsm.hpp" local="yes" imported="no">rcppsw/patterns/fsm/base_fsm.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
    <member kind="typedef">
      <type>base_fsm</type>
      <name>simple_fsm</name>
      <anchorfile>namespacercppsw_1_1patterns_1_1fsm.html</anchorfile>
      <anchor>af9a95d8b12a4275318c36b763fce11c9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>state.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>state_action.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state__action_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="event_8hpp" name="event.hpp" local="yes" imported="no">rcppsw/patterns/fsm/event.hpp</includes>
    <includes id="state_8hpp" name="state.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state_action0</class>
    <class kind="class">rcppsw::patterns::fsm::state_action1</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>state_entry.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state__entry_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state_entry</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>state_entry_action.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state__entry__action_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="event_8hpp" name="event.hpp" local="yes" imported="no">rcppsw/patterns/fsm/event.hpp</includes>
    <includes id="state__entry_8hpp" name="state_entry.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_entry.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state_entry_action0</class>
    <class kind="class">rcppsw::patterns::fsm::state_entry_action1</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>state_exit.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state__exit_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state_exit</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>state_exit_action.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state__exit__action_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="event_8hpp" name="event.hpp" local="yes" imported="no">rcppsw/patterns/fsm/event.hpp</includes>
    <includes id="state__exit_8hpp" name="state_exit.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_exit.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state_exit_action</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>state_guard.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state__guard_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state_guard</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>state_guard_action.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state__guard__action_8hpp.html</filename>
    <includes id="event_8hpp" name="event.hpp" local="yes" imported="no">rcppsw/patterns/fsm/event.hpp</includes>
    <includes id="state__guard_8hpp" name="state_guard.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_guard.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state_guard_condition0</class>
    <class kind="class">rcppsw::patterns::fsm::state_guard_condition1</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>state_map_ex_row.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state__map__ex__row_8hpp.html</filename>
    <includes id="state_8hpp" name="state.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state.hpp</includes>
    <includes id="state__entry_8hpp" name="state_entry.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_entry.hpp</includes>
    <includes id="state__exit_8hpp" name="state_exit.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_exit.hpp</includes>
    <includes id="state__guard_8hpp" name="state_guard.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state_guard.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state_map_ex_row</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>state_map_row.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/fsm/</path>
    <filename>state__map__row_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="state_8hpp" name="state.hpp" local="yes" imported="no">rcppsw/patterns/fsm/state.hpp</includes>
    <class kind="class">rcppsw::patterns::fsm::state_map_row</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
  </compound>
  <compound kind="file">
    <name>pimpl.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/pimpl/</path>
    <filename>pimpl_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::pimpl::pimpl</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::pimpl</namespace>
  </compound>
  <compound kind="file">
    <name>caching_factory.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/prototype/</path>
    <filename>caching__factory_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="factory_8hpp" name="factory.hpp" local="yes" imported="no">rcppsw/patterns/factory/factory.hpp</includes>
    <class kind="class">rcppsw::patterns::prototype::caching_factory</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::prototype</namespace>
  </compound>
  <compound kind="file">
    <name>clonable.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/prototype/</path>
    <filename>clonable_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::prototype::clonable</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::prototype</namespace>
  </compound>
  <compound kind="file">
    <name>singleton.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/singleton/</path>
    <filename>singleton_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::patterns::singleton::singleton</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::singleton</namespace>
  </compound>
  <compound kind="file">
    <name>polymorphic_visitable.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/visitor/</path>
    <filename>polymorphic__visitable_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">polymorphic_accept_set</class>
    <class kind="class">polymorphic_accept_set&lt; T &gt;</class>
    <class kind="class">polymorphic_accept_set&lt; T, Ts... &gt;</class>
    <class kind="class">rcppsw::patterns::visitor::detail::polymorphic_accept_set_helper</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::visitor</namespace>
    <namespace>rcppsw::patterns::visitor::detail</namespace>
  </compound>
  <compound kind="file">
    <name>visitor.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/patterns/visitor/</path>
    <filename>visitor_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="typelist_8hpp" name="typelist.hpp" local="yes" imported="no">rcppsw/mpl/typelist.hpp</includes>
    <class kind="class">filtered_visitor</class>
    <class kind="class">precise_visitor</class>
    <class kind="class">rcppsw::patterns::visitor::detail::visit_set_helper</class>
    <class kind="class">visit_set</class>
    <class kind="class">visit_set&lt; T &gt;</class>
    <class kind="class">visit_set&lt; T, Ts... &gt;</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::visitor</namespace>
    <namespace>rcppsw::patterns::visitor::detail</namespace>
    <member kind="typedef">
      <type>mpl::typelist&lt; Args... &gt;</type>
      <name>precise_visit_set</name>
      <anchorfile>visitor_8hpp.html</anchorfile>
      <anchor>aee3c2fb91be50db41b47fe05b0d51285</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>rcppsw.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/</path>
    <filename>rcppsw_8hpp.html</filename>
    <includes id="common_8hpp" name="common.hpp" local="yes" imported="no">rcppsw/common/common.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::al</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::algorithm::clustering</namespace>
    <namespace>rcppsw::config</namespace>
    <namespace>rcppsw::control</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::ds::graph</namespace>
    <namespace>rcppsw::ds::metrics</namespace>
    <namespace>rcppsw::er</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::metrics::config</namespace>
    <namespace>rcppsw::metrics::config::xml</namespace>
    <namespace>rcppsw::mpl</namespace>
    <namespace>rcppsw::multiprocess</namespace>
    <namespace>rcppsw::multithread</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::patterns::decorator</namespace>
    <namespace>rcppsw::patterns::factory</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
    <namespace>rcppsw::patterns::pimpl</namespace>
    <namespace>rcppsw::patterns::prototype</namespace>
    <namespace>rcppsw::patterns::singleton</namespace>
    <namespace>rcppsw::patterns::visitor</namespace>
    <namespace>rcppsw::types</namespace>
    <namespace>rcppsw::utils</namespace>
  </compound>
  <compound kind="file">
    <name>discretize_ratio.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/types/</path>
    <filename>discretize__ratio_8hpp.html</filename>
    <includes id="named__type_8hpp" name="named_type.hpp" local="yes" imported="no">rcppsw/types/named_type.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::types</namespace>
    <member kind="typedef">
      <type>named_type&lt; double, struct discretize_ratio_tag &gt;</type>
      <name>discretize_ratio</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ae7dfad2612de94a0c90840e1e872dfa0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>distance_measure.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/types/</path>
    <filename>distance__measure_8hpp.html</filename>
    <includes id="client_8hpp" name="client.hpp" local="yes" imported="no">rcppsw/er/client.hpp</includes>
    <includes id="named__type_8hpp" name="named_type.hpp" local="yes" imported="no">rcppsw/types/named_type.hpp</includes>
    <class kind="class">rcppsw::types::distance_measure</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::types</namespace>
  </compound>
  <compound kind="file">
    <name>manhattan_dist.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/types/</path>
    <filename>manhattan__dist_8hpp.html</filename>
    <includes id="distance__measure_8hpp" name="distance_measure.hpp" local="yes" imported="no">rcppsw/types/distance_measure.hpp</includes>
    <class kind="class">rcppsw::types::manhattan_dist</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::types</namespace>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator+</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>a27802aa16293b7b518133955db138a4b</anchor>
      <arglist>(int lhs, const manhattan_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator-</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>a3f4858fc7f1c09ed8666732797def584</anchor>
      <arglist>(int lhs, const manhattan_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ac22882e200d1ff6bc2933e156640e01d</anchor>
      <arglist>(int lhs, const manhattan_dist &amp;rhs)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>named_type.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/types/</path>
    <filename>named__type_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="stringizable_8hpp" name="stringizable.hpp" local="yes" imported="no">rcppsw/er/stringizable.hpp</includes>
    <class kind="class">rcppsw::types::named_type</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::types</namespace>
  </compound>
  <compound kind="file">
    <name>spatial_dist.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/types/</path>
    <filename>spatial__dist_8hpp.html</filename>
    <includes id="distance__measure_8hpp" name="distance_measure.hpp" local="yes" imported="no">rcppsw/types/distance_measure.hpp</includes>
    <class kind="class">rcppsw::types::spatial_dist</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::types</namespace>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator*</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>aef760b91a956f697f983d4cb76adcc90</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator+</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ae02d68adeec2cc3ab1bc30dd738f0730</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator-</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ac6dd93090803a932374969b7a697bad0</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator/</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ac584d6f672ae57b8a27cb5ddf7fbca7b</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>a606bae202ce4cf5a0697a4b72ced5b6f</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>spatial_range.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/types/</path>
    <filename>spatial__range_8hpp.html</filename>
    <includes id="range_8hpp" name="range.hpp" local="yes" imported="no">rcppsw/math/range.hpp</includes>
    <includes id="spatial__dist_8hpp" name="spatial_dist.hpp" local="yes" imported="no">rcppsw/types/spatial_dist.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::types</namespace>
    <member kind="typedef">
      <type>math::range&lt; types::spatial_dist &gt;</type>
      <name>spatial_range</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ab416cfd1a6af16a3dec61d9ae8f5ce6a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>timestep.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/types/</path>
    <filename>timestep_8hpp.html</filename>
    <includes id="named__type_8hpp" name="named_type.hpp" local="yes" imported="no">rcppsw/types/named_type.hpp</includes>
    <class kind="class">rcppsw::types::timestep</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::types</namespace>
  </compound>
  <compound kind="file">
    <name>type_uuid.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/types/</path>
    <filename>type__uuid_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="named__type_8hpp" name="named_type.hpp" local="yes" imported="no">rcppsw/types/named_type.hpp</includes>
  </compound>
  <compound kind="file">
    <name>base_cli.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/utils/</path>
    <filename>base__cli_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::utils::base_cli</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::utils</namespace>
  </compound>
  <compound kind="file">
    <name>color.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/utils/</path>
    <filename>color_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="stringizable_8hpp" name="stringizable.hpp" local="yes" imported="no">rcppsw/er/stringizable.hpp</includes>
    <class kind="class">rcppsw::utils::color</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::utils</namespace>
  </compound>
  <compound kind="file">
    <name>file_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/utils/</path>
    <filename>file__parser_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <includes id="line__parser_8hpp" name="line_parser.hpp" local="yes" imported="no">rcppsw/utils/line_parser.hpp</includes>
    <class kind="class">rcppsw::utils::file_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::utils</namespace>
  </compound>
  <compound kind="file">
    <name>line_parser.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/utils/</path>
    <filename>line__parser_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <class kind="class">rcppsw::utils::line_parser</class>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::utils</namespace>
  </compound>
  <compound kind="file">
    <name>maskable_enum.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/utils/</path>
    <filename>maskable__enum_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <member kind="function">
      <type>bool</type>
      <name>operator&amp;</name>
      <anchorfile>maskable__enum_8hpp.html</anchorfile>
      <anchor>a2ec269e3d39fc42c5a524b45faf80d31</anchor>
      <arglist>(const TEnum &amp;lhs, const TEnum &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TEnum</type>
      <name>operator|</name>
      <anchorfile>maskable__enum_8hpp.html</anchorfile>
      <anchor>a46e32f06110882befc652ba90ed4162a</anchor>
      <arglist>(const TEnum &amp;lhs, const TEnum &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>TEnum</type>
      <name>operator|=</name>
      <anchorfile>maskable__enum_8hpp.html</anchorfile>
      <anchor>ac9eaf2565d5e20933532111a4dabc756</anchor>
      <arglist>(TEnum &amp;lhs, const TEnum &amp;rhs)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>string_utils.hpp</name>
    <path>/home/jharwell/git/rcppsw/include/rcppsw/utils/</path>
    <filename>string__utils_8hpp.html</filename>
    <includes id="rcppsw_8hpp" name="rcppsw.hpp" local="yes" imported="no">rcppsw/rcppsw.hpp</includes>
    <namespace>rcppsw</namespace>
    <namespace>rcppsw::utils</namespace>
    <member kind="function">
      <type>bool</type>
      <name>parse_values</name>
      <anchorfile>namespacercppsw_1_1utils.html</anchorfile>
      <anchor>a24de48f591600b86f2163575d342cfe3</anchor>
      <arglist>(std::istream &amp;is, size_t n_fields, T *buf, char delim=&apos;\n&apos;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_clustering_impl&lt; T, policy::EH &gt;</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</filename>
    <member kind="typedef">
      <type>typename cluster::mapping&lt; T, policy::EH &gt;::type</type>
      <name>cluster_type</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>af36eb09f7dedf9887de013daa1b77c6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; cluster_type &gt;</type>
      <name>cluster_vector</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>af7c16dc09eba724dd34e5afb5070b5b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::function&lt; double(const T &amp;, const T &amp;)&gt;</type>
      <name>dist_calc_ftype</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a6d0cb28b21790eb053a2fa7a423e46da</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_clustering_impl</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a54140d4d5406e8a29ff5915561569a8a</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>converged</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a66ad621088e5c8007b62d527ed5fc001</anchor>
      <arglist>(const cluster_vector &amp;clusters) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a5931c398b226c9b0fd1719157a0f3774</anchor>
      <arglist>(std::vector&lt; T &gt; *data, membership_type&lt; policy::EH &gt; *membership)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>iterate</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a57b1d1b0a37630e02f8c0bbf49679c42</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;data, const dist_calc_ftype &amp;dist_func, cluster_vector *clusters)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>post_iter_update</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a0331abbc18e66c066f7c4bc256d95144</anchor>
      <arglist>(cluster_vector *clusters)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_clustering_impl&lt; T, policy::NC &gt;</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</filename>
    <member kind="typedef">
      <type>typename cluster::mapping&lt; T, policy::NC &gt;::type</type>
      <name>cluster_type</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>af36eb09f7dedf9887de013daa1b77c6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; cluster_type &gt;</type>
      <name>cluster_vector</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>af7c16dc09eba724dd34e5afb5070b5b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::function&lt; double(const T &amp;, const T &amp;)&gt;</type>
      <name>dist_calc_ftype</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a6d0cb28b21790eb053a2fa7a423e46da</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_clustering_impl</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a54140d4d5406e8a29ff5915561569a8a</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>converged</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a66ad621088e5c8007b62d527ed5fc001</anchor>
      <arglist>(const cluster_vector &amp;clusters) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a5931c398b226c9b0fd1719157a0f3774</anchor>
      <arglist>(std::vector&lt; T &gt; *data, membership_type&lt; policy::NC &gt; *membership)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>iterate</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a57b1d1b0a37630e02f8c0bbf49679c42</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;data, const dist_calc_ftype &amp;dist_func, cluster_vector *clusters)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>post_iter_update</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a0331abbc18e66c066f7c4bc256d95144</anchor>
      <arglist>(cluster_vector *clusters)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_clustering_impl&lt; T, rcppsw::algorithm::clustering::policy::NC &gt;</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</filename>
    <member kind="typedef">
      <type>typename cluster::mapping&lt; T, rcppsw::algorithm::clustering::policy::NC &gt;::type</type>
      <name>cluster_type</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>af36eb09f7dedf9887de013daa1b77c6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; cluster_type &gt;</type>
      <name>cluster_vector</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>af7c16dc09eba724dd34e5afb5070b5b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::function&lt; double(const T &amp;, const T &amp;)&gt;</type>
      <name>dist_calc_ftype</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a6d0cb28b21790eb053a2fa7a423e46da</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_clustering_impl</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a54140d4d5406e8a29ff5915561569a8a</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>converged</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a66ad621088e5c8007b62d527ed5fc001</anchor>
      <arglist>(const cluster_vector &amp;clusters) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a5931c398b226c9b0fd1719157a0f3774</anchor>
      <arglist>(std::vector&lt; T &gt; *data, membership_type&lt; rcppsw::algorithm::clustering::policy::NC &gt; *membership)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>iterate</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a57b1d1b0a37630e02f8c0bbf49679c42</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;data, const dist_calc_ftype &amp;dist_func, cluster_vector *clusters)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>post_iter_update</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a0331abbc18e66c066f7c4bc256d95144</anchor>
      <arglist>(cluster_vector *clusters)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_factory&lt; detail::factory_releasing_type, std::unique_ptr, base_waveform, std::string, Args... &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a000d4b0250412166a44ddef9e75ab21d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; base_waveform &gt;</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>ab4878ff7354eb99c0a3a52a2c8c6ea6d</anchor>
      <arglist>(const std::string &amp;name, Args... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a6d82ea282d6e32ce743632f249fb724a</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unregister_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>afa8c84b04fd09d44cd97b2c6505c67b4</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_factory&lt; detail::factory_releasing_type, std::unique_ptr, TBase, TKeyType, Args... &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a000d4b0250412166a44ddef9e75ab21d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; TBase &gt;</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>ab4878ff7354eb99c0a3a52a2c8c6ea6d</anchor>
      <arglist>(const TKeyType &amp;name, Args... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a6d82ea282d6e32ce743632f249fb724a</anchor>
      <arglist>(const TKeyType &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unregister_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>afa8c84b04fd09d44cd97b2c6505c67b4</anchor>
      <arglist>(const TKeyType &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_factory&lt; detail::factory_sharing_type, std::shared_ptr, rng, std::string, Args... &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a000d4b0250412166a44ddef9e75ab21d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>std::shared_ptr&lt; rng &gt;</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>ab4878ff7354eb99c0a3a52a2c8c6ea6d</anchor>
      <arglist>(const std::string &amp;name, Args... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a6d82ea282d6e32ce743632f249fb724a</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unregister_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>afa8c84b04fd09d44cd97b2c6505c67b4</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_factory&lt; detail::factory_sharing_type, std::shared_ptr, TBase, std::string, Args... &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a000d4b0250412166a44ddef9e75ab21d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>std::shared_ptr&lt; TBase &gt;</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>ab4878ff7354eb99c0a3a52a2c8c6ea6d</anchor>
      <arglist>(const std::string &amp;name, Args... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a6d82ea282d6e32ce743632f249fb724a</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unregister_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>afa8c84b04fd09d44cd97b2c6505c67b4</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_factory&lt; detail::factory_sharing_type, std::shared_ptr, TBase, TKeyType, Args... &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a000d4b0250412166a44ddef9e75ab21d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>std::shared_ptr&lt; TBase &gt;</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>ab4878ff7354eb99c0a3a52a2c8c6ea6d</anchor>
      <arglist>(const TKeyType &amp;name, Args... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a6d82ea282d6e32ce743632f249fb724a</anchor>
      <arglist>(const TKeyType &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unregister_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>afa8c84b04fd09d44cd97b2c6505c67b4</anchor>
      <arglist>(const TKeyType &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_factory&lt; detail::factory_sharing_type, std::shared_ptr, xml_config_parser, std::string, Args... &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a000d4b0250412166a44ddef9e75ab21d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>std::shared_ptr&lt; xml_config_parser &gt;</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>ab4878ff7354eb99c0a3a52a2c8c6ea6d</anchor>
      <arglist>(const std::string &amp;name, Args... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a6d82ea282d6e32ce743632f249fb724a</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unregister_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>afa8c84b04fd09d44cd97b2c6505c67b4</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_grid2D&lt; ral::mt_size_t &gt;</name>
    <filename>classrcppsw_1_1ds_1_1base__grid2D.html</filename>
    <member kind="typedef">
      <type>typename grid_type::template const_array_view&lt; 2 &gt;::type</type>
      <name>const_grid_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a433ac412b78d0e738d6047d279268320</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>math::vector2z</type>
      <name>coord_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ae339553851df15f8f7aefe6a6f57c72a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename boost::multi_array&lt; ral::mt_size_t, 2 &gt;</type>
      <name>grid_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ad19d9d6e335f964dff08c70eef52e0df</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename grid_type::template array_view&lt; 2 &gt;::type</type>
      <name>grid_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a76b5b8f35edb7150f4a4979873909b95</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename grid_type::index_range</type>
      <name>index_range</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ace9c01b56b8abc56386820ca76f09a3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ral::mt_size_t</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a318959506293c356361a85c257bf73e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a89317145ba9cffd5f4e3ffc7b05a8228</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a2b4535cf583ec4757f5a9eac139fa003</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a0ccf9f68d376e5224c5e6af9e8b284b4</anchor>
      <arglist>(const coord_type &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>const ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a2f4cc209ed97a5d839d88e8a3268bfd6</anchor>
      <arglist>(const coord_type &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>const ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a0906773f3ee17e64c0874bd01f7d86ac</anchor>
      <arglist>(size_t i, size_t j) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>af3ab1b118dee3d55ea6564f2c0fa4244</anchor>
      <arglist>(size_t i, size_t j)=0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>aec06b76a62751145dcaad60f8e001777</anchor>
      <arglist>(const coord_type &amp;pt)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a96a44cd104539a2f681558d8f20aa4c4</anchor>
      <arglist>(size_t i, size_t j)</arglist>
    </member>
    <member kind="function">
      <type>ral::mt_size_t &amp;</type>
      <name>operator[]</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a3deeb0565d9bb7e0c3313c04ceb72f0f</anchor>
      <arglist>(const coord_type &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>const ral::mt_size_t &amp;</type>
      <name>operator[]</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a13341425f16780147dbbcd9f2269dd62</anchor>
      <arglist>(const coord_type &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>subcircle</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a658148f2773c6efda3bc711b84855d0a</anchor>
      <arglist>(const coord_type &amp;c, size_t radius)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>subcircle</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a40d2a2eeed1e52ec8a59d4537251eca2</anchor>
      <arglist>(const coord_type &amp;c, size_t radius) const</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>subgrid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a0b95f4e005e63c77eec289688afddb76</anchor>
      <arglist>(const coord_type &amp;ll, const coord_type &amp;ur)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>subgrid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>af92232745f930301e5c99df9d43d4995</anchor>
      <arglist>(const coord_type &amp;ll, const coord_type &amp;ur) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a4ff0f254c0950348156ec474a8f6f9e8</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>aae9c14bf203200aaed9b2ca3e90024f7</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual const grid_type &amp;</type>
      <name>grid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ab8d872cac35bd4bb1331735e0b4dbed3</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual grid_type &amp;</type>
      <name>grid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ad5a010725166c053ac5c9e1cefd16c67</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_grid3D&lt; ral::mt_size_t &gt;</name>
    <filename>classrcppsw_1_1ds_1_1base__grid3D.html</filename>
    <member kind="typedef">
      <type>typename grid_type::template const_array_view&lt; 3 &gt;::type</type>
      <name>const_grid_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a11f0150a4712763146110d537c54a845</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>rmath::vector3z</type>
      <name>coord_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a5bbb33160f11fe1da0e514e6cae6137f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename boost::multi_array&lt; ral::mt_size_t, 3 &gt;</type>
      <name>grid_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a12c8081a19d25404fbe90644e80d52a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename grid_type::template array_view&lt; 3 &gt;::type</type>
      <name>grid_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>aaed03eaf8692fd97ec345336d7f5c02d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename grid_type::index_range</type>
      <name>index_range</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>aa2c6c466838e04dbc65c24ebb27e1baa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ral::mt_size_t</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>aee4614688e422a4ebff86371057487c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_grid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a98630a3263180ffce82dedfe146b5cb8</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_grid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a9ab7a2cdb1230dd391a9eaf1849f624a</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a78d172bf2633fc0aa93f12f13c3d6ab5</anchor>
      <arglist>(const coord_type &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>const ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a08257423dfc688b275fb26a29dd7b9f7</anchor>
      <arglist>(const coord_type &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>const ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a0c9b342c2cc3b9ec68233489eba29bb6</anchor>
      <arglist>(size_t i, size_t j, size_t k) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a05eff4a346b7a328df19257206129686</anchor>
      <arglist>(size_t i, size_t j, size_t k)=0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a422e5f43277bd0bbe48d8007a433c087</anchor>
      <arglist>(const coord_type &amp;pt)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>aab1aa33a5733948556a87562d27656e6</anchor>
      <arglist>(size_t i, size_t j, size_t k)</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>layer</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a2050360303873cf0af2c5bdc0d2c2d87</anchor>
      <arglist>(size_t z)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>layer</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a829b5ba9183465925d1f0419210178ae</anchor>
      <arglist>(size_t z) const</arglist>
    </member>
    <member kind="function">
      <type>ral::mt_size_t &amp;</type>
      <name>operator[]</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a9210a9e7e110aa4a16f5c4d89ee90748</anchor>
      <arglist>(const coord_type &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>const ral::mt_size_t &amp;</type>
      <name>operator[]</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a986b32fdf343b43ae6726a46dc23c8b0</anchor>
      <arglist>(const coord_type &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>subcircle</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a6a3ae0e9a28e50781ca9e21a04c194f5</anchor>
      <arglist>(const coord_type &amp;c, size_t radius)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>subcircle</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a00b0b17091ae0db0006aed2f4727cf87</anchor>
      <arglist>(const coord_type &amp;c, size_t radius) const</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>subgrid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a07bab3b66558618e52cb8d99364f4716</anchor>
      <arglist>(const coord_type &amp;ll, const coord_type &amp;ur)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>subgrid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>acc0579502af1077c1662faa7031c4966</anchor>
      <arglist>(const coord_type &amp;ll, const coord_type &amp;ur) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a46f68ceadbbc4797cc51e7e35a658e34</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>ade178e757b57e3b7d0d6150cce12f7bf</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>zsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a8a76901a1d4b4910a7acfadfa2fadc0a</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual const grid_type &amp;</type>
      <name>grid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>ab15b0f41b6390a5af5042941e9aa57e8</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual grid_type &amp;</type>
      <name>grid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a83721a9d073cb119200ccddf93bbf99f</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_grid_overlay&lt; math::vector2d &gt;</name>
    <filename>classrcppsw_1_1ds_1_1base__grid__overlay.html</filename>
    <base>client&lt; base_grid_overlay&lt; math::vector2d &gt; &gt;</base>
    <member kind="typedef">
      <type>typename std::conditional&lt; std::is_same&lt; math::vector2d, math::vector2z &gt;::value, math::vector2z, math::vector3z &gt;::type</type>
      <name>origin_dtype</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>a96e5b9199f0d17c8c3c33961ab2f5189</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename std::conditional&lt; std::is_same&lt; math::vector2d, math::vector2d &gt;::value, math::vector2d, math::vector3d &gt;::type</type>
      <name>origin_rtype</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>afe8b9dc76f0d8b237f8ea794479966dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_grid_overlay</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>ac2caf268914e47144c6522fe40659f2f</anchor>
      <arglist>(const origin_rtype &amp;origin, const types::discretize_ratio &amp;grid_resolution, const types::discretize_ratio &amp;field_resolution)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_grid_overlay</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>afb568100d17252a34e067bbc1dc21fbf</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>const origin_dtype &amp;</type>
      <name>origind</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>ad2539759a5ec1dc2990a2d7b003ec26b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const origin_rtype &amp;</type>
      <name>originr</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>adc80be69e0e1700c2337c0da479481a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const types::discretize_ratio &amp;</type>
      <name>resolution</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>a54243210a50361cc50a9359632d99f0c</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>base_grid_overlay&lt; math::vector3d &gt;</name>
    <filename>classrcppsw_1_1ds_1_1base__grid__overlay.html</filename>
    <base>client&lt; base_grid_overlay&lt; math::vector3d &gt; &gt;</base>
    <member kind="typedef">
      <type>typename std::conditional&lt; std::is_same&lt; math::vector3d, math::vector2z &gt;::value, math::vector2z, math::vector3z &gt;::type</type>
      <name>origin_dtype</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>a96e5b9199f0d17c8c3c33961ab2f5189</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename std::conditional&lt; std::is_same&lt; math::vector3d, math::vector2d &gt;::value, math::vector2d, math::vector3d &gt;::type</type>
      <name>origin_rtype</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>afe8b9dc76f0d8b237f8ea794479966dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_grid_overlay</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>ac2caf268914e47144c6522fe40659f2f</anchor>
      <arglist>(const origin_rtype &amp;origin, const types::discretize_ratio &amp;grid_resolution, const types::discretize_ratio &amp;field_resolution)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_grid_overlay</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>afb568100d17252a34e067bbc1dc21fbf</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>const origin_dtype &amp;</type>
      <name>origind</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>ad2539759a5ec1dc2990a2d7b003ec26b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const origin_rtype &amp;</type>
      <name>originr</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>adc80be69e0e1700c2337c0da479481a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const types::discretize_ratio &amp;</type>
      <name>resolution</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>a54243210a50361cc50a9359632d99f0c</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>bounding_box&lt; rcppsw::math::vector3 &gt;</name>
    <filename>classrcppsw_1_1math_1_1bounding__box.html</filename>
    <base>client&lt; bounding_box&lt; rcppsw::math::vector3 &gt; &gt;</base>
    <member kind="typedef">
      <type>rcppsw::math::vector3</type>
      <name>coord_type</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a6392654bdbc1e9b668e701fb8f57f4d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename coord_type::value_type</type>
      <name>coord_value_type</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>ab1841326fcc193fc2ba0478f30ea1ab4</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a1d1f5f2a56ca309f3d31be7edb199454</anchor>
      <arglist>(bounding_box &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a363fc124849735028666e64e0f869394</anchor>
      <arglist>(const bounding_box &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>aae309dd23eceab4c0928dff3b0a1da54</anchor>
      <arglist>(const coord_type &amp;dims)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>ae7bf81c3f4456af9fa9eded666c29824</anchor>
      <arglist>(const coord_type &amp;dims, const coord_type &amp;anchor)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a32dcbbd1f5737eb07bafc85ee5b54a21</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>const coord_type &amp;</type>
      <name>anchor3D</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a437355a5679db1c8da23f33e281c2200</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>coord_type</type>
      <name>center3D</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a0c8d8d5f3aed11d183b07e66c7ac9f9c</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const coord_type &amp;</type>
      <name>dims3D</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>ab033fbae20c7c9957882494694cf3f3a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bounding_box &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a8ed3bb2228d316a2cd1ac9de1b20bb5b</anchor>
      <arglist>(bounding_box &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>bounding_box &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a989c2006933a16e55b2f44d9c6c04136</anchor>
      <arglist>(const bounding_box &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a5b31f2bdcb8354a75e069a82df903c38</anchor>
      <arglist>(const coord_type &amp;anchor)</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a2aaab567d1ef21d1de924bd9599a9bb0</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>rmath::range&lt; coord_value_type &gt;</type>
      <name>xspan</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a12caea8ed95ed35c9fb288db2380ce3d</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a806b2908f2061fe3328e1f388df8e36c</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>rmath::range&lt; coord_value_type &gt;</type>
      <name>yspan</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a8653130ec36e1fe92240a8fb6c32258f</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>zsize</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>abcbd072fe3a5a3176e31514642509b8c</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>rmath::range&lt; coord_value_type &gt;</type>
      <name>zspan</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>ac0fdd4b8c67d7f8f3016832c057894c3</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>caching_factory&lt; rng, uint &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1prototype_1_1caching__factory.html</filename>
    <member kind="function">
      <type>rng *</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1prototype_1_1caching__factory.html</anchorfile>
      <anchor>a4bab8f07f5cf01ee0652c3c3c42aba52</anchor>
      <arglist>(const std::string &amp;name, Args... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1prototype_1_1caching__factory.html</anchorfile>
      <anchor>afc718b5957ca25141ce476ad792f5ce2</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; base_collector &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; base_fsm &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; base_grid_overlay&lt; math::vector2d &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; base_grid_overlay&lt; math::vector3d &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; base_grid_overlay&lt; TOriginType &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; base_sink &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; base_sink_parser &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; bounding_box&lt; rcppsw::math::vector3 &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; bounding_box&lt; TCoord &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; convex_hull2D&lt; TCoord &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; csv_sink &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; distance_measure&lt; double, struct spatial_dist_tag &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; distance_measure&lt; int, struct manhattan_dist_tag &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; distance_measure&lt; T, Tag &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; ema_parser &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; entropy_balch2000&lt; T &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; file_sink &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; file_sink_parser &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; file_sink_registerer &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; fs_output_manager &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; grid2D_overlay&lt; T &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; grid3D_overlay&lt; T &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; hfsm &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; hgrid3D_view_filter&lt; TSpecType &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; hgrid3D_view_filter_data&lt; spec_type &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; hgrid3D_view_filter_data&lt; TSpecType &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; kmeans&lt; T &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; metrics_parser &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; network_output_manager &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; network_sink &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; network_sink_parser &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; network_sink_registerer &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; range&lt; coord_value_type &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; range&lt; rcppsw::math::degrees &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; range&lt; T &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; register_with_sink&lt; TMetricsManager, TSinkMixin, void &gt; &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; rng_parser &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; sigmoid_parser &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; waveform_parser &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>client&lt; xml_config_repository &gt;</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>decorator&lt; std::deque&lt; T &gt; &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</filename>
    <member kind="typedef">
      <type>std::deque&lt; T &gt;</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a741c896a38d2c22bfcd68382fc0aee64</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decorator&lt; decoratee_type &gt;</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1b8e1bf59abf4cb7039f657c1351dbf5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0e7167ad4e2d030d6c451a867db8af5e</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a32c13ab58d3bd71c61030090590a9d62</anchor>
      <arglist>(decoratee_type &amp;&amp;arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a3856e90a033659fc506a77c613bfc89f</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a280934f4a5829a42c7916ba29560d645</anchor>
      <arglist>(std::initializer_list&lt; U &gt; args)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a64c494d06f4fcbc9e52345db78510791</anchor>
      <arglist>(TArgs... args)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1816de4c343796e84f48c3603b8041ab</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a519a95005089f4b8c476dc3b5dc0f3ab</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a34ab8f2525dae8185bf161985885e8c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0f947db92e941d973426b19c1aa1fa9c</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa7dcaa3ec447cb1af590f4a64de10b09</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa91bf92ef0eda53cc43ce584c40f5c49</anchor>
      <arglist>(TArgs &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate_with</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>af34e316851d6ccde1ab339f9dadf0c2a</anchor>
      <arglist>(const decoratee_type &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>decorator&lt; std::map&lt; rcppsw::math::vector3, const vertex_property_type *, rmath::vector3z::key_compare &gt; &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</filename>
    <member kind="typedef">
      <type>std::map&lt; rcppsw::math::vector3, const vertex_property_type *, rmath::vector3z::key_compare &gt;</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a741c896a38d2c22bfcd68382fc0aee64</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decorator&lt; decoratee_type &gt;</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1b8e1bf59abf4cb7039f657c1351dbf5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0e7167ad4e2d030d6c451a867db8af5e</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a32c13ab58d3bd71c61030090590a9d62</anchor>
      <arglist>(decoratee_type &amp;&amp;arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a3856e90a033659fc506a77c613bfc89f</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a280934f4a5829a42c7916ba29560d645</anchor>
      <arglist>(std::initializer_list&lt; U &gt; args)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a64c494d06f4fcbc9e52345db78510791</anchor>
      <arglist>(TArgs... args)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1816de4c343796e84f48c3603b8041ab</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a519a95005089f4b8c476dc3b5dc0f3ab</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a34ab8f2525dae8185bf161985885e8c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0f947db92e941d973426b19c1aa1fa9c</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa7dcaa3ec447cb1af590f4a64de10b09</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa91bf92ef0eda53cc43ce584c40f5c49</anchor>
      <arglist>(TArgs &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate_with</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>af34e316851d6ccde1ab339f9dadf0c2a</anchor>
      <arglist>(const decoratee_type &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>decorator&lt; std::map&lt; TGrid, TVertex, std::less&lt; TGrid &gt; &gt; &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</filename>
    <member kind="typedef">
      <type>std::map&lt; TGrid, TVertex, std::less&lt; TGrid &gt; &gt;</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a741c896a38d2c22bfcd68382fc0aee64</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decorator&lt; decoratee_type &gt;</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1b8e1bf59abf4cb7039f657c1351dbf5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0e7167ad4e2d030d6c451a867db8af5e</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a32c13ab58d3bd71c61030090590a9d62</anchor>
      <arglist>(decoratee_type &amp;&amp;arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a3856e90a033659fc506a77c613bfc89f</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a280934f4a5829a42c7916ba29560d645</anchor>
      <arglist>(std::initializer_list&lt; U &gt; args)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a64c494d06f4fcbc9e52345db78510791</anchor>
      <arglist>(TArgs... args)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1816de4c343796e84f48c3603b8041ab</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a519a95005089f4b8c476dc3b5dc0f3ab</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a34ab8f2525dae8185bf161985885e8c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0f947db92e941d973426b19c1aa1fa9c</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa7dcaa3ec447cb1af590f4a64de10b09</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa91bf92ef0eda53cc43ce584c40f5c49</anchor>
      <arglist>(TArgs &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate_with</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>af34e316851d6ccde1ab339f9dadf0c2a</anchor>
      <arglist>(const decoratee_type &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>decorator&lt; TSpecType::bgl_impl_type &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</filename>
    <member kind="typedef">
      <type>TSpecType::bgl_impl_type</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a741c896a38d2c22bfcd68382fc0aee64</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decorator&lt; decoratee_type &gt;</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1b8e1bf59abf4cb7039f657c1351dbf5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0e7167ad4e2d030d6c451a867db8af5e</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a32c13ab58d3bd71c61030090590a9d62</anchor>
      <arglist>(decoratee_type &amp;&amp;arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a3856e90a033659fc506a77c613bfc89f</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a280934f4a5829a42c7916ba29560d645</anchor>
      <arglist>(std::initializer_list&lt; U &gt; args)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a64c494d06f4fcbc9e52345db78510791</anchor>
      <arglist>(TArgs... args)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1816de4c343796e84f48c3603b8041ab</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a519a95005089f4b8c476dc3b5dc0f3ab</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a34ab8f2525dae8185bf161985885e8c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0f947db92e941d973426b19c1aa1fa9c</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa7dcaa3ec447cb1af590f4a64de10b09</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa91bf92ef0eda53cc43ce584c40f5c49</anchor>
      <arglist>(TArgs &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate_with</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>af34e316851d6ccde1ab339f9dadf0c2a</anchor>
      <arglist>(const decoratee_type &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>decorator&lt; TSpecType::template bgl_view_impl_type&lt; hgrid3D_view_edge_filter_type&lt; TSpecType &gt;, hgrid3D_view_vertex_filter_type&lt; TSpecType &gt; &gt; &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</filename>
    <member kind="typedef">
      <type>TSpecType::template bgl_view_impl_type&lt; hgrid3D_view_edge_filter_type&lt; TSpecType &gt;, hgrid3D_view_vertex_filter_type&lt; TSpecType &gt; &gt;</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a741c896a38d2c22bfcd68382fc0aee64</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decorator&lt; decoratee_type &gt;</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1b8e1bf59abf4cb7039f657c1351dbf5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0e7167ad4e2d030d6c451a867db8af5e</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a32c13ab58d3bd71c61030090590a9d62</anchor>
      <arglist>(decoratee_type &amp;&amp;arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a3856e90a033659fc506a77c613bfc89f</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a280934f4a5829a42c7916ba29560d645</anchor>
      <arglist>(std::initializer_list&lt; U &gt; args)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a64c494d06f4fcbc9e52345db78510791</anchor>
      <arglist>(TArgs... args)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1816de4c343796e84f48c3603b8041ab</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a519a95005089f4b8c476dc3b5dc0f3ab</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a34ab8f2525dae8185bf161985885e8c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0f947db92e941d973426b19c1aa1fa9c</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa7dcaa3ec447cb1af590f4a64de10b09</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa91bf92ef0eda53cc43ce584c40f5c49</anchor>
      <arglist>(TArgs &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate_with</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>af34e316851d6ccde1ab339f9dadf0c2a</anchor>
      <arglist>(const decoratee_type &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>decorator&lt; TSpecType::tree_type &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</filename>
    <member kind="typedef">
      <type>TSpecType::tree_type</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a741c896a38d2c22bfcd68382fc0aee64</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decorator&lt; decoratee_type &gt;</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1b8e1bf59abf4cb7039f657c1351dbf5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0e7167ad4e2d030d6c451a867db8af5e</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a32c13ab58d3bd71c61030090590a9d62</anchor>
      <arglist>(decoratee_type &amp;&amp;arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a3856e90a033659fc506a77c613bfc89f</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a280934f4a5829a42c7916ba29560d645</anchor>
      <arglist>(std::initializer_list&lt; U &gt; args)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a64c494d06f4fcbc9e52345db78510791</anchor>
      <arglist>(TArgs... args)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1816de4c343796e84f48c3603b8041ab</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a519a95005089f4b8c476dc3b5dc0f3ab</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a34ab8f2525dae8185bf161985885e8c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0f947db92e941d973426b19c1aa1fa9c</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa7dcaa3ec447cb1af590f4a64de10b09</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa91bf92ef0eda53cc43ce584c40f5c49</anchor>
      <arglist>(TArgs &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate_with</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>af34e316851d6ccde1ab339f9dadf0c2a</anchor>
      <arglist>(const decoratee_type &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>distance_measure&lt; double, struct spatial_dist_tag &gt;</name>
    <filename>classrcppsw_1_1types_1_1distance__measure.html</filename>
    <base>named_type&lt; double, struct spatial_dist_tag &gt;</base>
    <base>client&lt; distance_measure&lt; double, struct spatial_dist_tag &gt; &gt;</base>
    <member kind="typedef">
      <type>double</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>aea4a37b0610e8c0aafd27b41d60278d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>distance_measure</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a8b9eabce8e4ef1226385264a358f7467</anchor>
      <arglist>(const distance_measure &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>distance_measure</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a1a2df64630ac102d9d432373922e0900</anchor>
      <arglist>(const double &amp;value, bool check_psd=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~distance_measure</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a90138f34ada5eb86657b6fb869d07bb5</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a4c1fef0674c235cd8523abb84047654e</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a174ee7f7675692e22288c07948a4b8b6</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a119ce1e7927cd4ad28c6ed556fc6269a</anchor>
      <arglist>(double rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a313e22de24f4a672f66da8e593aa7425</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>ae5abceecbe8e7ee73a12142c080bb4c9</anchor>
      <arglist>(double rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>aa9ba96ab2957ce3cdad5857c55fc097d</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>afebaafc7a799abb0b72e086d9f06a2a6</anchor>
      <arglist>(double rhs) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>distance_measure&lt; int, struct manhattan_dist_tag &gt;</name>
    <filename>classrcppsw_1_1types_1_1distance__measure.html</filename>
    <base>named_type&lt; int, struct manhattan_dist_tag &gt;</base>
    <base>client&lt; distance_measure&lt; int, struct manhattan_dist_tag &gt; &gt;</base>
    <member kind="typedef">
      <type>int</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>aea4a37b0610e8c0aafd27b41d60278d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>distance_measure</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a8b9eabce8e4ef1226385264a358f7467</anchor>
      <arglist>(const distance_measure &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>distance_measure</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a1a2df64630ac102d9d432373922e0900</anchor>
      <arglist>(const int &amp;value, bool check_psd=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~distance_measure</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a90138f34ada5eb86657b6fb869d07bb5</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a4c1fef0674c235cd8523abb84047654e</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a174ee7f7675692e22288c07948a4b8b6</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a119ce1e7927cd4ad28c6ed556fc6269a</anchor>
      <arglist>(int rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a313e22de24f4a672f66da8e593aa7425</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>ae5abceecbe8e7ee73a12142c080bb4c9</anchor>
      <arglist>(int rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>aa9ba96ab2957ce3cdad5857c55fc097d</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>afebaafc7a799abb0b72e086d9f06a2a6</anchor>
      <arglist>(int rhs) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>expression&lt; double &gt;</name>
    <filename>classrcppsw_1_1math_1_1expression.html</filename>
    <member kind="function">
      <type></type>
      <name>expression</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>ad04caaa756da846454de4eb50a56c440</anchor>
      <arglist>(const double &amp;last)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>expression</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>aaf5f6c5239b011cc50e0660435796d42</anchor>
      <arglist>(const expression &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>expression</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a93c2ef3e3dca75b4d332b3f3dbdeabcf</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~expression</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>af75b4f349110ceaac4efbf36cd278a82</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>eval</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a2ca96a1dc826983e83f6e1e78f9f7d91</anchor>
      <arglist>(const double &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a9cb4fefa68b3548f05417e43eb5277b0</anchor>
      <arglist>(const expression &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>expression &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a485d8341d75d4b27202152a55440508c</anchor>
      <arglist>(const expression &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>afa8fda64acb803192fc82eab2e3ac2c1</anchor>
      <arglist>(const expression &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>ad8efa9b86f5cc28bd10a4b6418830667</anchor>
      <arglist>(const expression &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>aa9e95f4e981ff13149304f3ead544aaa</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>v</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a80f64efdd897e7287fef8624ef456810</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>filtered_visitor</name>
    <filename>classfiltered__visitor.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>TVisitor</type>
      <name>visitor_type</name>
      <anchorfile>classfiltered__visitor.html</anchorfile>
      <anchor>a1ca5a707ffff72c6a526a5b99d0833aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>filtered_visitor</name>
      <anchorfile>classfiltered__visitor.html</anchorfile>
      <anchor>a38febe87bb67000cba89db253018298e</anchor>
      <arglist>(Args &amp;&amp;...args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>visit</name>
      <anchorfile>classfiltered__visitor.html</anchorfile>
      <anchor>a64161f17809797db29b51c0f5a7c893d</anchor>
      <arglist>(TAny &amp;obj, Args &amp;&amp;... args)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>grid2D&lt; ral::mt_size_t &gt;</name>
    <filename>classrcppsw_1_1ds_1_1grid2D.html</filename>
    <base>base_grid2D&lt; ral::mt_size_t &gt;</base>
    <member kind="function">
      <type></type>
      <name>grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a99f63fcb43aec7c45e2e53eb77454bfe</anchor>
      <arglist>(const coord_type &amp;dims)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a1ae0eba25bec5e4765b566e51407acaa</anchor>
      <arglist>(size_t x_max, size_t y_max)</arglist>
    </member>
    <member kind="function">
      <type>ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a20714ede13a3a24b5124da2cf5d68f64</anchor>
      <arglist>(size_t i, size_t j) override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a9d7cb43e0ae820ecbd02601eb5130e45</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a79b4d97c9e50fc8f4677d3aadf4e485f</anchor>
      <arglist>(void) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>grid3D&lt; ral::mt_size_t &gt;</name>
    <filename>classrcppsw_1_1ds_1_1grid3D.html</filename>
    <base>base_grid3D&lt; ral::mt_size_t &gt;</base>
    <member kind="function">
      <type></type>
      <name>grid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a9ced942f54c5ddbd3d134933c41356d4</anchor>
      <arglist>(const coord_type &amp;dims)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>grid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a5afad89295fd0430a4a572f7c38c20ca</anchor>
      <arglist>(size_t x_max, size_t y_max, size_t z_max)</arglist>
    </member>
    <member kind="function">
      <type>ral::mt_size_t &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a0d73673d2360919a8be92eb0ccbd501f</anchor>
      <arglist>(size_t i, size_t j, size_t k) override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a32398b282a42be7e82df930b5902bfd4</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>aa868060e23e0ada5282f472d2957f472</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>zsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a25bf450199dfe72bd1f82d1d3cea7a88</anchor>
      <arglist>(void) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>grid_index_map&lt; rcppsw::math::vector3, const vertex_property_type *, rmath::vector3z::key_compare &gt;</name>
    <filename>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</filename>
    <base>decorator&lt; std::map&lt; rcppsw::math::vector3, const vertex_property_type *, rmath::vector3z::key_compare &gt; &gt;</base>
    <member kind="typedef">
      <type>typename decorator_type::decoratee_type</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>ac1db8ba22924c7051310d3de81f1011c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename rpdecorator::decorator&lt; std::map&lt; rcppsw::math::vector3, const vertex_property_type *, rmath::vector3z::key_compare &gt; &gt;::decorator_type</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a08df0561cc4f5e0209a6c35ef1f25b24</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_CT</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a0c7ab5af1e1b9e49b63e6923ce09a441</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a0c7bb472a2025dc4de107d3bfd8c19ab</anchor>
      <arglist>(begin)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a1d47d204060ade02fd51594bd79d9739</anchor>
      <arglist>(begin, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>ae38d6920eae699f15c54c50cc3dbc564</anchor>
      <arglist>(end)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a69f949c94d70d3c8659dc47877df9095</anchor>
      <arglist>(end, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a4bc87e2e932dc049883a869938d71615</anchor>
      <arglist>(find)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a22327314e471598a3fa589b7485068e8</anchor>
      <arglist>(find, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>acbdbed72d27d06f53a426db1d231f40e</anchor>
      <arglist>(insert)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a451f49a3b2d28e15f4d83ecb083043d7</anchor>
      <arglist>(operator[])</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>af5286ed9fd911fadd44e4c055cf0447b</anchor>
      <arglist>(size, const)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>hfsm_state_action0&lt; rcppsw::patterns::fsm::hfsm, &amp;hfsm::ST_top_state &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action0.html</filename>
    <base>rcppsw::patterns::fsm::hfsm_state</base>
    <member kind="function">
      <type></type>
      <name>hfsm_state_action0</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action0.html</anchorfile>
      <anchor>a61a2c21e3fb0b51480377d105d0e883e</anchor>
      <arglist>(hfsm_state *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~hfsm_state_action0</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action0.html</anchorfile>
      <anchor>abcd21a5d6fb5e80c503ac2d71525a667</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>invoke_state_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action0.html</anchorfile>
      <anchor>a25b82048ef7cfba76a34c2cd07ed17d9</anchor>
      <arglist>(base_fsm *fsm, event_data *) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>hgrid3D_view_filter_data&lt; spec_type &gt;</name>
    <filename>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</filename>
    <base>client&lt; hgrid3D_view_filter_data&lt; spec_type &gt; &gt;</base>
    <member kind="typedef">
      <type>typename spec_type ::bgl_impl_type</type>
      <name>bgl_impl_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a2ebaaed36501134082a410b4e7fe85cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::edge_descriptor</type>
      <name>edge_descriptor</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a2662c3a13d690a684854515912feb2c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::vertex_descriptor</type>
      <name>vertex_descriptor</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>aebb8d386448d350651e6e8b0c6e65b4f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::vertex_property_type</type>
      <name>vertex_property_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>aab0a17b7becbfc073b5a2c39e1a97cc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hgrid3D_view_filter_data</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>abf8a36be7b7ac7ecf0ae38a400ef29d4</anchor>
      <arglist>(const rmath::vector3z &amp;center, const rtypes::manhattan_dist &amp;max_dist, size_t max_vertices)</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>center</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a5b185a20aa44b4fb661f07b5faf73d76</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; rtypes::manhattan_dist &gt; *</type>
      <name>distances</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>aedd3701c7a211bef0eade7acda9e3da4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>edge_filter</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>ade32d4bfd92d5a050516447c8d9397d8</anchor>
      <arglist>(edge_descriptor) const</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>ll</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>aa7aaf32c859f4eb3903c6047e90d59ca</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>auto *</type>
      <name>lookup</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a13f08d0e4db02cdec7be4e1ac617c6fa</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const auto *</type>
      <name>lookup</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a434438e9955422e4f7b122e790066bee</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>lr</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>af55217e6bfe226ebde6594f63a0d0a10</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>n_vertices</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a328a88b82fc23fd8fbbaa595ed03f0c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>ul</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>ad48e2d44597778c508786764eef64111</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a06850ef6c4430c4b5b2f7c71339b887f</anchor>
      <arglist>(const bgl_impl_type &amp;g, vertex_descriptor vd, const rtypes::manhattan_dist &amp;dist)</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>ur</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a17f32b998d62d05fb255cd7e04fed26a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>vertex_filter</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a1cfdb0835bafa067d2081ad6029c2fe0</anchor>
      <arglist>(vertex_descriptor vd) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>named_type&lt; double, struct spatial_dist_tag &gt;</name>
    <filename>classrcppsw_1_1types_1_1named__type.html</filename>
    <base>rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a45531d5cc915d48d5132f711dfb5541b</anchor>
      <arglist>(double const &amp;value) noexcept</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ad2fd23fa3879f2cfd77c5ad9c65b9a57</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>double &amp;</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ae3adaef7b9d236a163a83fdfc2e8a5c8</anchor>
      <arglist>(const double &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a5be785b00b2a79f27ede7953446c9bad</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>const double &amp;</type>
      <name>v</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ab5e5d9c79710dbd92eea31dbe0357de5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a61be9ff951c2a54898fc3e0d6037adcc</anchor>
      <arglist>(std::ostream &amp;stream, const named_type &amp;c_type)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>afea5f975654f3c41ef3eb12cec92914d</anchor>
      <arglist>(std::istream &amp;stream, named_type &amp;n)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>named_type&lt; int, struct manhattan_dist_tag &gt;</name>
    <filename>classrcppsw_1_1types_1_1named__type.html</filename>
    <base>rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a45531d5cc915d48d5132f711dfb5541b</anchor>
      <arglist>(int const &amp;value) noexcept</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ad2fd23fa3879f2cfd77c5ad9c65b9a57</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>int &amp;</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ae3adaef7b9d236a163a83fdfc2e8a5c8</anchor>
      <arglist>(const int &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a5be785b00b2a79f27ede7953446c9bad</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>const int &amp;</type>
      <name>v</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ab5e5d9c79710dbd92eea31dbe0357de5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a61be9ff951c2a54898fc3e0d6037adcc</anchor>
      <arglist>(std::ostream &amp;stream, const named_type &amp;c_type)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>afea5f975654f3c41ef3eb12cec92914d</anchor>
      <arglist>(std::istream &amp;stream, named_type &amp;n)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>named_type&lt; size_t, struct timestep_tag &gt;</name>
    <filename>classrcppsw_1_1types_1_1named__type.html</filename>
    <base>rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a45531d5cc915d48d5132f711dfb5541b</anchor>
      <arglist>(size_t const &amp;value) noexcept</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ad2fd23fa3879f2cfd77c5ad9c65b9a57</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>size_t &amp;</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ae3adaef7b9d236a163a83fdfc2e8a5c8</anchor>
      <arglist>(const size_t &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a5be785b00b2a79f27ede7953446c9bad</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>const size_t &amp;</type>
      <name>v</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ab5e5d9c79710dbd92eea31dbe0357de5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a61be9ff951c2a54898fc3e0d6037adcc</anchor>
      <arglist>(std::ostream &amp;stream, const named_type &amp;c_type)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>afea5f975654f3c41ef3eb12cec92914d</anchor>
      <arglist>(std::istream &amp;stream, named_type &amp;n)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>named_type&lt; T, Tag &gt;</name>
    <filename>classrcppsw_1_1types_1_1named__type.html</filename>
    <base>rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a45531d5cc915d48d5132f711dfb5541b</anchor>
      <arglist>(T const &amp;value) noexcept</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ad2fd23fa3879f2cfd77c5ad9c65b9a57</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ae3adaef7b9d236a163a83fdfc2e8a5c8</anchor>
      <arglist>(const T &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a5be785b00b2a79f27ede7953446c9bad</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>v</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ab5e5d9c79710dbd92eea31dbe0357de5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a61be9ff951c2a54898fc3e0d6037adcc</anchor>
      <arglist>(std::ostream &amp;stream, const named_type &amp;c_type)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>afea5f975654f3c41ef3eb12cec92914d</anchor>
      <arglist>(std::istream &amp;stream, named_type &amp;n)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>polymorphic_accept_set</name>
    <filename>polymorphic__visitable_8hpp.html</filename>
    <anchor>classpolymorphic__accept__set</anchor>
    <templarg>Ts</templarg>
  </compound>
  <compound kind="class">
    <name>polymorphic_accept_set&lt; T &gt;</name>
    <filename>classpolymorphic__accept__set_3_01T_01_4.html</filename>
    <templarg></templarg>
  </compound>
  <compound kind="class">
    <name>polymorphic_accept_set&lt; T, Ts... &gt;</name>
    <filename>classpolymorphic__accept__set_3_01T_00_01Ts_8_8_8_01_4.html</filename>
    <templarg></templarg>
    <templarg>Ts</templarg>
    <base>polymorphic_accept_set&lt; Ts... &gt;</base>
  </compound>
  <compound kind="class">
    <name>polymorphic_accept_set&lt; Ts... &gt;</name>
    <filename>polymorphic__visitable_8hpp.html</filename>
  </compound>
  <compound kind="class">
    <name>precise_visitor</name>
    <filename>classprecise__visitor.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>precise_visitor</name>
      <anchorfile>classprecise__visitor.html</anchorfile>
      <anchor>abbbbd393bff9e9c8ceea813b45b90b55</anchor>
      <arglist>(Args &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>visit</name>
      <anchorfile>classprecise__visitor.html</anchorfile>
      <anchor>a480f3254456f2f9b806bf09d37629aab</anchor>
      <arglist>(T &amp;visitee, Args &amp;&amp;... args)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>precise_visitor&lt; TVisitor, typename TVisitor::visit_typelist &gt;</name>
    <filename>classprecise__visitor.html</filename>
    <member kind="function">
      <type></type>
      <name>precise_visitor</name>
      <anchorfile>classprecise__visitor.html</anchorfile>
      <anchor>abbbbd393bff9e9c8ceea813b45b90b55</anchor>
      <arglist>(Args &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>visit</name>
      <anchorfile>classprecise__visitor.html</anchorfile>
      <anchor>a480f3254456f2f9b806bf09d37629aab</anchor>
      <arglist>(T &amp;visitee, Args &amp;&amp;... args)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>range&lt; coord_value_type &gt;</name>
    <filename>classrcppsw_1_1math_1_1range.html</filename>
    <base>client&lt; range&lt; coord_value_type &gt; &gt;</base>
    <base protection="private">rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>range</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a3ab0c3bc0145a373b8402326e48832f4</anchor>
      <arglist>(const coord_value_type &amp;lb, const coord_value_type &amp;ub) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>range</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a51646a21baf91b11727e42bae296f1f3</anchor>
      <arglist>(void) noexcept</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>center</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a7fd959194720f7109c79bbe9a3899e18</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a935c2fb3c1f164d146619bfc573d5e6c</anchor>
      <arglist>(const coord_value_type &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a935c2fb3c1f164d146619bfc573d5e6c</anchor>
      <arglist>(const coord_value_type &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a236cd91f4d84f3bf342adc67c50a2879</anchor>
      <arglist>(const range&lt; coord_value_type &gt; &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lb</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>ad7874a03108e2d36070b758e26eed0e3</anchor>
      <arglist>(const coord_value_type &amp;lb)</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>lb</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a98216301a5274242d0807fdb6ef0a9e5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>overlaps_with</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a37e7e41044185c0a22991162843b1797</anchor>
      <arglist>(const range&lt; coord_value_type &gt; &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>range</type>
      <name>recenter</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a3b2461aa1d5ea6949e1c3f1369f71617</anchor>
      <arglist>(const coord_value_type &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>af0a4297b73f93d2ec286cf308976a73c</anchor>
      <arglist>(const coord_value_type &amp;lb, const coord_value_type &amp;ub)</arglist>
    </member>
    <member kind="function">
      <type>range</type>
      <name>shrink</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a98d5d14dd91aa4e10d26ec82ea1113df</anchor>
      <arglist>(const coord_value_type &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>span</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a4b26e811d65942ad13b8df83c17a16db</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a0ade48e4a0e80910b805169e2c186bd4</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>range</type>
      <name>translate</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a0d9bc5b47f120de08c42a5a00a4b0563</anchor>
      <arglist>(const coord_value_type &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ub</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a0213db565ba4678555abe0f8ef66bc85</anchor>
      <arglist>(const coord_value_type &amp;ub)</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>ub</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>af8213dcf44eddc9ebec8803d87db67fa</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>wrap_value</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a564e5d1adac98d5e1ff4e6d0542b3ae7</anchor>
      <arglist>(coord_value_type value) const</arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a4659bf314aa29a0ca9b3847e68e819bd</anchor>
      <arglist>(std::ostream &amp;stream, const range &amp;c_range)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a5d38c5c46b1f429c37395c60ba4474ad</anchor>
      <arglist>(std::istream &amp;is, range &amp;r)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>range&lt; rcppsw::math::degrees &gt;</name>
    <filename>classrcppsw_1_1math_1_1range.html</filename>
    <base>client&lt; range&lt; rcppsw::math::degrees &gt; &gt;</base>
    <base protection="private">rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>range</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a3ab0c3bc0145a373b8402326e48832f4</anchor>
      <arglist>(const rcppsw::math::degrees &amp;lb, const rcppsw::math::degrees &amp;ub) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>range</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a51646a21baf91b11727e42bae296f1f3</anchor>
      <arglist>(void) noexcept</arglist>
    </member>
    <member kind="function">
      <type>rcppsw::math::degrees</type>
      <name>center</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a7fd959194720f7109c79bbe9a3899e18</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a236cd91f4d84f3bf342adc67c50a2879</anchor>
      <arglist>(const range&lt; rcppsw::math::degrees &gt; &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a935c2fb3c1f164d146619bfc573d5e6c</anchor>
      <arglist>(const rcppsw::math::degrees &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a935c2fb3c1f164d146619bfc573d5e6c</anchor>
      <arglist>(const rcppsw::math::degrees &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lb</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>ad7874a03108e2d36070b758e26eed0e3</anchor>
      <arglist>(const rcppsw::math::degrees &amp;lb)</arglist>
    </member>
    <member kind="function">
      <type>rcppsw::math::degrees</type>
      <name>lb</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a98216301a5274242d0807fdb6ef0a9e5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>overlaps_with</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a37e7e41044185c0a22991162843b1797</anchor>
      <arglist>(const range&lt; rcppsw::math::degrees &gt; &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>range</type>
      <name>recenter</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a3b2461aa1d5ea6949e1c3f1369f71617</anchor>
      <arglist>(const rcppsw::math::degrees &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>af0a4297b73f93d2ec286cf308976a73c</anchor>
      <arglist>(const rcppsw::math::degrees &amp;lb, const rcppsw::math::degrees &amp;ub)</arglist>
    </member>
    <member kind="function">
      <type>range</type>
      <name>shrink</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a98d5d14dd91aa4e10d26ec82ea1113df</anchor>
      <arglist>(const rcppsw::math::degrees &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>rcppsw::math::degrees</type>
      <name>span</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a4b26e811d65942ad13b8df83c17a16db</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a0ade48e4a0e80910b805169e2c186bd4</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>range</type>
      <name>translate</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a0d9bc5b47f120de08c42a5a00a4b0563</anchor>
      <arglist>(const rcppsw::math::degrees &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ub</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a0213db565ba4678555abe0f8ef66bc85</anchor>
      <arglist>(const rcppsw::math::degrees &amp;ub)</arglist>
    </member>
    <member kind="function">
      <type>rcppsw::math::degrees</type>
      <name>ub</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>af8213dcf44eddc9ebec8803d87db67fa</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>rcppsw::math::degrees</type>
      <name>wrap_value</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a564e5d1adac98d5e1ff4e6d0542b3ae7</anchor>
      <arglist>(rcppsw::math::degrees value) const</arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a4659bf314aa29a0ca9b3847e68e819bd</anchor>
      <arglist>(std::ostream &amp;stream, const range &amp;c_range)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a5d38c5c46b1f429c37395c60ba4474ad</anchor>
      <arglist>(std::istream &amp;is, range &amp;r)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::closest_pair2D</name>
    <filename>classrcppsw_1_1algorithm_1_1closest__pair2D.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type>result_type2D&lt; T &gt;</type>
      <name>brute_force</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1closest__pair2D.html</anchorfile>
      <anchor>a784956b3a297251c4a89b2dca5506e33</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;points, const TDistFunc &amp;dist_func)</arglist>
    </member>
    <member kind="function">
      <type>result_type2D&lt; T &gt;</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1closest__pair2D.html</anchorfile>
      <anchor>abf56b93bdb6e9af1d984f0e841225793</anchor>
      <arglist>(const std::string &amp;method, std::vector&lt; T &gt; points, const TDistFunc &amp;dist_func)</arglist>
    </member>
    <member kind="function">
      <type>result_type2D&lt; T &gt;</type>
      <name>recursive</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1closest__pair2D.html</anchorfile>
      <anchor>ad09120cb78788305b4c0ec3e096b14b7</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;points, std::vector&lt; T &gt; &amp;strip, const TDistFunc &amp;dist_func)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kBruteForce</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1closest__pair2D.html</anchorfile>
      <anchor>a8b7d99a065768ce9e44781ece607891b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kRecursive</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1closest__pair2D.html</anchorfile>
      <anchor>aa5afedbbe06ffa00f60ead29d167fca2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>rcppsw::algorithm::clustering::base_clustering_impl</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="typedef">
      <type>typename cluster::mapping&lt; T, Policy &gt;::type</type>
      <name>cluster_type</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>af36eb09f7dedf9887de013daa1b77c6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; cluster_type &gt;</type>
      <name>cluster_vector</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>af7c16dc09eba724dd34e5afb5070b5b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::function&lt; double(const T &amp;, const T &amp;)&gt;</type>
      <name>dist_calc_ftype</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a6d0cb28b21790eb053a2fa7a423e46da</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_clustering_impl</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a54140d4d5406e8a29ff5915561569a8a</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>converged</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a66ad621088e5c8007b62d527ed5fc001</anchor>
      <arglist>(const cluster_vector &amp;clusters) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a5931c398b226c9b0fd1719157a0f3774</anchor>
      <arglist>(std::vector&lt; T &gt; *data, membership_type&lt; Policy &gt; *membership)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>iterate</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a57b1d1b0a37630e02f8c0bbf49679c42</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;data, const dist_calc_ftype &amp;dist_func, cluster_vector *clusters)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>post_iter_update</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1base__clustering__impl.html</anchorfile>
      <anchor>a0331abbc18e66c066f7c4bc256d95144</anchor>
      <arglist>(cluster_vector *clusters)=0</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::algorithm::clustering::cluster::mapping</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1cluster.html</filename>
    <anchor>structrcppsw_1_1algorithm_1_1clustering_1_1cluster_1_1mapping</anchor>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::algorithm::clustering::cluster::mapping&lt; T, Policy, policy::is_eh&lt; Policy &gt; &gt;</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1cluster.html</filename>
    <anchor>structrcppsw_1_1algorithm_1_1clustering_1_1cluster_1_1mapping_3_01T_00_01Policy_00_01policy_1_1is__eh_3_01Policy_01_4_01_4</anchor>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="typedef">
      <type>eh_cluster&lt; T, Policy &gt;</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1cluster.html</anchorfile>
      <anchor>aa17b300399336fdf67d319d0f56db408</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::algorithm::clustering::cluster::mapping&lt; T, Policy, policy::is_nc&lt; Policy &gt; &gt;</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1cluster.html</filename>
    <anchor>structrcppsw_1_1algorithm_1_1clustering_1_1cluster_1_1mapping_3_01T_00_01Policy_00_01policy_1_1is__nc_3_01Policy_01_4_01_4</anchor>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="typedef">
      <type>nc_cluster&lt; T, Policy &gt;</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1cluster.html</anchorfile>
      <anchor>abaa825a44d52cfcacfe897a482deee05</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::clustering::eh_cluster</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1eh__cluster.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>eh_cluster</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__cluster.html</anchorfile>
      <anchor>a6804b161d25cd0c6a457a460f074acec</anchor>
      <arglist>(uint id, const std::vector&lt; T &gt; &amp;data, membership_type&lt; Policy &gt; &amp;membership)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>add_point</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__cluster.html</anchorfile>
      <anchor>a8e57eff1a1302ed077640d46e7b403d3</anchor>
      <arglist>(size_t point_idx)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>center</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__cluster.html</anchorfile>
      <anchor>ae9d57603578a57a4230c0982c0370f3a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>converged</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__cluster.html</anchorfile>
      <anchor>abcd60878bcd4bd2bd3d8c985de8ce6c8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>eh_cluster &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__cluster.html</anchorfile>
      <anchor>a1256e527ed76d0472c0fc61d789cf906</anchor>
      <arglist>(const eh_cluster &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>size</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__cluster.html</anchorfile>
      <anchor>ad29c8973c4d3110c629e632ff8efef2d</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update_size</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__cluster.html</anchorfile>
      <anchor>a83752c88a807693fc8d7886d32a3263d</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>rcppsw::algorithm::clustering::eh_clustering_impl</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1eh__clustering__impl.html</filename>
    <templarg></templarg>
    <base>base_clustering_impl&lt; T, policy::EH &gt;</base>
    <member kind="function">
      <type></type>
      <name>~eh_clustering_impl</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__clustering__impl.html</anchorfile>
      <anchor>a3c179e0984d0a66bb81150cdb8d35ad6</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>horizon</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__clustering__impl.html</anchorfile>
      <anchor>aa7062eb40a44b1d7bd2000fb4c229c3d</anchor>
      <arglist>(double horizon)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>horizon</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1eh__clustering__impl.html</anchorfile>
      <anchor>a6575ba584276f776a67640e03f8b0627</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::clustering::entropy_balch2000</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__balch2000.html</filename>
    <templarg></templarg>
    <base>client&lt; entropy_balch2000&lt; T &gt; &gt;</base>
    <member kind="typedef">
      <type>typename base_clustering_impl&lt; T, policy::EH &gt;::cluster_vector</type>
      <name>cluster_vector</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__balch2000.html</anchorfile>
      <anchor>a85372f4788bada11f448caa66f2889a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename base_clustering_impl&lt; T, policy::EH &gt;::dist_calc_ftype</type>
      <name>dist_calc_ftype</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__balch2000.html</anchorfile>
      <anchor>a1cb2d57a57d667a57df66a4b3ec4b46d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::map&lt; double, membership_type&lt; policy::EH &gt; &gt;</type>
      <name>membership_map</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__balch2000.html</anchorfile>
      <anchor>a2d6474261036ecab5026eb5830f5e4d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::vector&lt; membership_type&lt; policy::EH &gt; &gt;</type>
      <name>membership_vector</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__balch2000.html</anchorfile>
      <anchor>a72bbfc8437ba58a167118b6032850395</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>entropy_balch2000</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__balch2000.html</anchorfile>
      <anchor>a972632362bb6007697e2b69f248c2337</anchor>
      <arglist>(std::unique_ptr&lt; eh_clustering_impl&lt; T &gt;&gt; impl, const math::ranged &amp;horizon, double horizon_delta)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>run</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__balch2000.html</anchorfile>
      <anchor>aa90a6d33e455efe1839e2040d17c92c0</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;data, const dist_calc_ftype &amp;dist_func)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::clustering::entropy_eh_omp</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__eh__omp.html</filename>
    <templarg></templarg>
    <base>rcppsw::algorithm::clustering::eh_clustering_impl</base>
    <member kind="function">
      <type></type>
      <name>entropy_eh_omp</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__eh__omp.html</anchorfile>
      <anchor>a7eae5d283ae906cd34415b42331268c5</anchor>
      <arglist>(size_t n_threads)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>converged</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__eh__omp.html</anchorfile>
      <anchor>afa9fb2d46570aa111912df364d147a62</anchor>
      <arglist>(const cluster_vector &amp;) const override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__eh__omp.html</anchorfile>
      <anchor>a47835ebda95854ccf5e9b845da6bb596</anchor>
      <arglist>(std::vector&lt; T &gt; *const data, membership_type&lt; policy::EH &gt; *const membership) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>iterate</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__eh__omp.html</anchorfile>
      <anchor>aeda3a6c79bcd67a20aad31d93c6558c8</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;data, const dist_calc_ftype &amp;dist_func, cluster_vector *const clusters) override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>n_threads</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__eh__omp.html</anchorfile>
      <anchor>a96ec570d8a3d3cfccc9d542324e4f2d2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>post_iter_update</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1entropy__eh__omp.html</anchorfile>
      <anchor>ab39a1575c1005a9fd44dd97c14aed9d6</anchor>
      <arglist>(cluster_vector *const) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::clustering::kmeans</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans.html</filename>
    <templarg></templarg>
    <base>client&lt; kmeans&lt; T &gt; &gt;</base>
    <member kind="typedef">
      <type>typename base_clustering_impl&lt; T, policy::NC &gt;::cluster_vector</type>
      <name>cluster_vector</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans.html</anchorfile>
      <anchor>ab60d2b177e97789ce7f6eee447f5cf2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename base_clustering_impl&lt; T, policy::NC &gt;::dist_calc_ftype</type>
      <name>dist_calc_ftype</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans.html</anchorfile>
      <anchor>ad3b17da5d28333b05bdc287af92202b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>kmeans</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans.html</anchorfile>
      <anchor>a7b193045912d2f3593b8b4648ff2c7c9</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;data_in, std::unique_ptr&lt; base_clustering_impl&lt; T, policy::NC &gt; &gt; impl, size_t k, size_t max_iter)</arglist>
    </member>
    <member kind="function">
      <type>membership_type&lt; policy::NC &gt;</type>
      <name>run</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans.html</anchorfile>
      <anchor>a0592585fbe15c78016f5a0348d4bb405</anchor>
      <arglist>(const dist_calc_ftype &amp;dist_func)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::clustering::kmeans_omp</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans__omp.html</filename>
    <templarg></templarg>
    <base>base_clustering_impl&lt; T, policy::NC &gt;</base>
    <member kind="function">
      <type></type>
      <name>kmeans_omp</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans__omp.html</anchorfile>
      <anchor>a9417dd5a2433834f7c76506e1662990b</anchor>
      <arglist>(size_t n_threads)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>converged</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans__omp.html</anchorfile>
      <anchor>afd335812f1785c0d89a39643cbe0a4b7</anchor>
      <arglist>(const cluster_vector &amp;clusters) const override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans__omp.html</anchorfile>
      <anchor>ad75d0c14be090ed69b8a5e5e7b4b3c4a</anchor>
      <arglist>(std::vector&lt; T &gt; *const data, membership_type&lt; policy::NC &gt; *const membership) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>iterate</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans__omp.html</anchorfile>
      <anchor>aef49a2ecbb8133b2e92dfd55a2d1a622</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;data, const dist_calc_ftype &amp;dist_func, cluster_vector *const clusters) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>post_iter_update</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1kmeans__omp.html</anchorfile>
      <anchor>a88460fcb2a69cec9a17d315d4f877ed2</anchor>
      <arglist>(cluster_vector *const clusters) override</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::algorithm::clustering::membership::mapping</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1membership.html</filename>
    <anchor>structrcppsw_1_1algorithm_1_1clustering_1_1membership_1_1mapping</anchor>
    <templarg></templarg>
    <templarg></templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::algorithm::clustering::membership::mapping&lt; Policy, policy::is_eh&lt; Policy &gt; &gt;</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1membership.html</filename>
    <anchor>structrcppsw_1_1algorithm_1_1clustering_1_1membership_1_1mapping_3_01Policy_00_01policy_1_1is__eh_3_01Policy_01_4_01_4</anchor>
    <templarg></templarg>
    <member kind="typedef">
      <type>std::vector&lt; std::unordered_set&lt; size_t &gt; &gt;</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1membership.html</anchorfile>
      <anchor>aada4c2de69a2c46c352bb5314464009f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::algorithm::clustering::membership::mapping&lt; Policy, policy::is_nc&lt; Policy &gt; &gt;</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1membership.html</filename>
    <anchor>structrcppsw_1_1algorithm_1_1clustering_1_1membership_1_1mapping_3_01Policy_00_01policy_1_1is__nc_3_01Policy_01_4_01_4</anchor>
    <templarg></templarg>
    <member kind="typedef">
      <type>std::vector&lt; size_t &gt;</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1membership.html</anchorfile>
      <anchor>a391967bcafc8d59955dd127ce35053ae</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::clustering::nc_cluster</name>
    <filename>classrcppsw_1_1algorithm_1_1clustering_1_1nc__cluster.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>nc_cluster</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1nc__cluster.html</anchorfile>
      <anchor>af0eab49772dce07be4e7c5a7c6af8900</anchor>
      <arglist>(uint id, const std::vector&lt; T &gt; &amp;data, membership_type&lt; Policy &gt; &amp;membership)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>add_point</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1nc__cluster.html</anchorfile>
      <anchor>acfba75742a31fdecde23ecafec7c3d9e</anchor>
      <arglist>(size_t idx)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>center</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1nc__cluster.html</anchorfile>
      <anchor>a2c3a3b5c2f113d46f7a5c44ee550027d</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>converged</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1nc__cluster.html</anchorfile>
      <anchor>a6885ce2753c2aaf3b59e592a3c9e7983</anchor>
      <arglist>(int=0) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>converged</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1nc__cluster.html</anchorfile>
      <anchor>a023eaa03c3bd2bca1ea31d01bab6ac6b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>nc_cluster &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1nc__cluster.html</anchorfile>
      <anchor>a217f0af257ea6dcd3785e851d9e77705</anchor>
      <arglist>(const nc_cluster &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update_center</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1clustering_1_1nc__cluster.html</anchorfile>
      <anchor>ae784ba448b8cc04c54b94a5911e062d4</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::clustering::policy::EH</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</filename>
    <anchor>classrcppsw_1_1algorithm_1_1clustering_1_1policy_1_1EH</anchor>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::clustering::policy::NC</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</filename>
    <anchor>classrcppsw_1_1algorithm_1_1clustering_1_1policy_1_1NC</anchor>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::convex_hull2D</name>
    <filename>classrcppsw_1_1algorithm_1_1convex__hull2D.html</filename>
    <templarg></templarg>
    <base>client&lt; convex_hull2D&lt; TCoord &gt; &gt;</base>
    <member kind="typedef">
      <type>TCoord</type>
      <name>coord_type</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1convex__hull2D.html</anchorfile>
      <anchor>a54236e1855bde2eb056d512a3f858cec</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename coord_type::value_type</type>
      <name>coord_value_type</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1convex__hull2D.html</anchorfile>
      <anchor>a3539b5f27b173c81e38979945038e53a</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>convex_hull2D</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1convex__hull2D.html</anchorfile>
      <anchor>a0f06de95c3d77d94e36b0c2b627e3980</anchor>
      <arglist>(const convex_hull2D &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>convex_hull2D</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1convex__hull2D.html</anchorfile>
      <anchor>a876809d9776d8376e87b6a01e02c4c08</anchor>
      <arglist>(convex_hull2D &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>convex_hull2D</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1convex__hull2D.html</anchorfile>
      <anchor>a96b58e1e903d89d9166336210f176250</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>boost::optional&lt; std::list&lt; coord_type &gt; &gt;</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1convex__hull2D.html</anchorfile>
      <anchor>a8f8bba32412bc4ac04205aac8fa88267</anchor>
      <arglist>(std::vector&lt; coord_type &gt; &amp;&amp;points)</arglist>
    </member>
    <member kind="function">
      <type>convex_hull2D &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1convex__hull2D.html</anchorfile>
      <anchor>a94aea68f0ab856a19a126a5493f3a3de</anchor>
      <arglist>(const convex_hull2D &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>convex_hull2D &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1convex__hull2D.html</anchorfile>
      <anchor>a577a8301aca380ef741a82f0c846ff31</anchor>
      <arglist>(convex_hull2D &amp;&amp;)=delete</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::algorithm::max_subarray_finder</name>
    <filename>classrcppsw_1_1algorithm_1_1max__subarray__finder.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type>boost::optional&lt; std::tuple&lt; T, int, int &gt; &gt;</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1algorithm_1_1max__subarray__finder.html</anchorfile>
      <anchor>afe9431a293493420ffec107190fea371</anchor>
      <arglist>(const std::vector&lt; T &gt; &amp;arr) const</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::algorithm::result_type2D</name>
    <filename>structrcppsw_1_1algorithm_1_1result__type2D.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>structrcppsw_1_1algorithm_1_1result__type2D.html</anchorfile>
      <anchor>aab8ee9744e099b0a3d04ca28aac4c024</anchor>
      <arglist>(const result_type2D&lt; T &gt; &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>structrcppsw_1_1algorithm_1_1result__type2D.html</anchorfile>
      <anchor>a3e08d3a8e444c88e72f127007143283f</anchor>
      <arglist>(double d) const</arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>dist</name>
      <anchorfile>structrcppsw_1_1algorithm_1_1result__type2D.html</anchorfile>
      <anchor>a9757a4d6d9262dcf8e946202ef4a6889</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>T</type>
      <name>p1</name>
      <anchorfile>structrcppsw_1_1algorithm_1_1result__type2D.html</anchorfile>
      <anchor>acd18e361e6ab058dd2c6b5f4e7206eff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>T</type>
      <name>p2</name>
      <anchorfile>structrcppsw_1_1algorithm_1_1result__type2D.html</anchorfile>
      <anchor>a35eea635ee45a6151de871a8a57c1182</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::config::base_config</name>
    <filename>structrcppsw_1_1config_1_1base__config.html</filename>
    <member kind="function">
      <type></type>
      <name>base_config</name>
      <anchorfile>structrcppsw_1_1config_1_1base__config.html</anchorfile>
      <anchor>a9a86158e067c0ed5b8b3c16760878473</anchor>
      <arglist>(const base_config &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_config</name>
      <anchorfile>structrcppsw_1_1config_1_1base__config.html</anchorfile>
      <anchor>a1cfd52de449665fdfe4b2a42c2248f96</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_config</name>
      <anchorfile>structrcppsw_1_1config_1_1base__config.html</anchorfile>
      <anchor>a4ddde3073572a1095a9aeeb7591cb226</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>base_config &amp;</type>
      <name>operator=</name>
      <anchorfile>structrcppsw_1_1config_1_1base__config.html</anchorfile>
      <anchor>a32d1e916aa385603fec11cefc9fa30be</anchor>
      <arglist>(const base_config &amp;)=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::config::streamable_parser</name>
    <filename>classrcppsw_1_1config_1_1streamable__parser.html</filename>
    <member kind="friend" protection="private">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1config_1_1streamable__parser.html</anchorfile>
      <anchor>a5f352c40b91b7a00bdf38cc0e919fbda</anchor>
      <arglist>(std::ostream &amp;stream, const streamable_parser &amp;parser)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::config::xml::xml_config_repository</name>
    <filename>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</filename>
    <base>client&lt; xml_config_repository &gt;</base>
    <member kind="function">
      <type></type>
      <name>xml_config_repository</name>
      <anchorfile>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</anchorfile>
      <anchor>ae496332aa6f1272d60a6880a6d1d8fe2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const T *</type>
      <name>config_get</name>
      <anchorfile>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</anchorfile>
      <anchor>ae46a367387f8846cfd6f6082b154231d</anchor>
      <arglist>(const std::string &amp;name) const</arglist>
    </member>
    <member kind="function">
      <type>const T *</type>
      <name>config_get</name>
      <anchorfile>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</anchorfile>
      <anchor>a8b00aea6b72c6b9b45e796dd5d437d11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse_all</name>
      <anchorfile>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</anchorfile>
      <anchor>a80ccd873caec50798822f1079e31b0ef</anchor>
      <arglist>(const ticpp::Element &amp;node)</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>parser_find</name>
      <anchorfile>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</anchorfile>
      <anchor>aec41270515c507e31abf20630bcb38c2</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parser_register</name>
      <anchorfile>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</anchorfile>
      <anchor>aadd7bdaf955aa78c5188debd3219be5e</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parser_register</name>
      <anchorfile>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</anchorfile>
      <anchor>ad2594410c45de0b34d51bdb8e2ee2f23</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parser_unregister</name>
      <anchorfile>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</anchorfile>
      <anchor>aced58f078ef8c835d9eb9f90454be700</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>validate_all</name>
      <anchorfile>classrcppsw_1_1config_1_1xml_1_1xml__config__repository.html</anchorfile>
      <anchor>a51a4b5bfd9106841588eb252f749f4be</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::control::base_waveform</name>
    <filename>classrcppsw_1_1control_1_1base__waveform.html</filename>
    <member kind="function">
      <type></type>
      <name>base_waveform</name>
      <anchorfile>classrcppsw_1_1control_1_1base__waveform.html</anchorfile>
      <anchor>aa1d503bc6d4e2ed057fd13935ca83031</anchor>
      <arglist>(const struct config::waveform_config *const config)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_waveform</name>
      <anchorfile>classrcppsw_1_1control_1_1base__waveform.html</anchorfile>
      <anchor>a88fac93072f67aaaa424b2985cfed241</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>amplitude</name>
      <anchorfile>classrcppsw_1_1control_1_1base__waveform.html</anchorfile>
      <anchor>ae1bb9d59522638807f5f8f6c80fe33b7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>frequency</name>
      <anchorfile>classrcppsw_1_1control_1_1base__waveform.html</anchorfile>
      <anchor>a3852a7b39f17eb8a2537979b209f7423</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>offset</name>
      <anchorfile>classrcppsw_1_1control_1_1base__waveform.html</anchorfile>
      <anchor>ac57ebf7711aaeee4b0a4c9d70d24183d</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const math::radians &amp;</type>
      <name>phase</name>
      <anchorfile>classrcppsw_1_1control_1_1base__waveform.html</anchorfile>
      <anchor>aa6242201d9d1560e6eab025c9658a073</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual double</type>
      <name>value</name>
      <anchorfile>classrcppsw_1_1control_1_1base__waveform.html</anchorfile>
      <anchor>a68747b81e14cdafce887753a477bb7b7</anchor>
      <arglist>(double time)=0</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::control::config::waveform_config</name>
    <filename>structrcppsw_1_1control_1_1config_1_1waveform__config.html</filename>
    <base>rcppsw::config::base_config</base>
    <member kind="function">
      <type></type>
      <name>waveform_config</name>
      <anchorfile>structrcppsw_1_1control_1_1config_1_1waveform__config.html</anchorfile>
      <anchor>aa24b0d9b6e84b1a8c0cdb548ed33a407</anchor>
      <arglist>(const std::string &amp;type_in, double freq_in, double phase_in, double amp_in, double offset_in)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>waveform_config</name>
      <anchorfile>structrcppsw_1_1control_1_1config_1_1waveform__config.html</anchorfile>
      <anchor>ab49e4e0164295d3d56d89a9b856457d2</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>amplitude</name>
      <anchorfile>structrcppsw_1_1control_1_1config_1_1waveform__config.html</anchorfile>
      <anchor>aac371bcc54cd45e5e8d275adea39e260</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>frequency</name>
      <anchorfile>structrcppsw_1_1control_1_1config_1_1waveform__config.html</anchorfile>
      <anchor>a4e33919e6f28fd202688549c3573755e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>offset</name>
      <anchorfile>structrcppsw_1_1control_1_1config_1_1waveform__config.html</anchorfile>
      <anchor>aad60e3fa8a9434995a201366304c6fa5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>phase</name>
      <anchorfile>structrcppsw_1_1control_1_1config_1_1waveform__config.html</anchorfile>
      <anchor>ae53ca171a9183b11a85a676a11761bc9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>type</name>
      <anchorfile>structrcppsw_1_1control_1_1config_1_1waveform__config.html</anchorfile>
      <anchor>abad1a2dcf994247cb2d5feb6980eea3f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::control::config::xml::waveform_parser</name>
    <filename>classrcppsw_1_1control_1_1config_1_1xml_1_1waveform__parser.html</filename>
    <base>client&lt; waveform_parser &gt;</base>
    <member kind="typedef">
      <type>waveform_config</type>
      <name>config_type</name>
      <anchorfile>classrcppsw_1_1control_1_1config_1_1xml_1_1waveform__parser.html</anchorfile>
      <anchor>aaf660d26937cc3068c8eb3b1cb7d7c4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>waveform_parser</name>
      <anchorfile>classrcppsw_1_1control_1_1config_1_1xml_1_1waveform__parser.html</anchorfile>
      <anchor>adfe5973444786cd3af46336a0c435160</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse</name>
      <anchorfile>classrcppsw_1_1control_1_1config_1_1xml_1_1waveform__parser.html</anchorfile>
      <anchor>a3b81a21f94861590d81c352c1b4f8036</anchor>
      <arglist>(const ticpp::Element &amp;node) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>xml_root</name>
      <anchorfile>classrcppsw_1_1control_1_1config_1_1xml_1_1waveform__parser.html</anchorfile>
      <anchor>aee115b97caedabc440348889276fd516</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kXMLRoot</name>
      <anchorfile>classrcppsw_1_1control_1_1config_1_1xml_1_1waveform__parser.html</anchorfile>
      <anchor>aa140495c4d664e820769fcfdf06a5e31</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::control::constant_waveform</name>
    <filename>classrcppsw_1_1control_1_1constant__waveform.html</filename>
    <base>rcppsw::control::base_waveform</base>
    <member kind="function">
      <type></type>
      <name>constant_waveform</name>
      <anchorfile>classrcppsw_1_1control_1_1constant__waveform.html</anchorfile>
      <anchor>ac8dc39a42c1dd23f109d6e108534aae1</anchor>
      <arglist>(const struct config::waveform_config *const config)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>value</name>
      <anchorfile>classrcppsw_1_1control_1_1constant__waveform.html</anchorfile>
      <anchor>a0318dc4d98621b55508eac1728ac5ff7</anchor>
      <arglist>(double) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::control::null_waveform</name>
    <filename>classrcppsw_1_1control_1_1null__waveform.html</filename>
    <base>rcppsw::control::base_waveform</base>
    <member kind="function">
      <type></type>
      <name>null_waveform</name>
      <anchorfile>classrcppsw_1_1control_1_1null__waveform.html</anchorfile>
      <anchor>a04c6e5e08dd48e853d664f92bcb2956d</anchor>
      <arglist>(const struct config::waveform_config *const config)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>value</name>
      <anchorfile>classrcppsw_1_1control_1_1null__waveform.html</anchorfile>
      <anchor>a13eac61ea5e4751c936ab4fa02b0f7a9</anchor>
      <arglist>(double) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::control::pid_loop</name>
    <filename>classrcppsw_1_1control_1_1pid__loop.html</filename>
    <member kind="function">
      <type></type>
      <name>pid_loop</name>
      <anchorfile>classrcppsw_1_1control_1_1pid__loop.html</anchorfile>
      <anchor>af6acfefc1d14641616bc5f78e3c0fa32</anchor>
      <arglist>(double kp, double kd, double ki, double dt, double min, double max)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>calculate</name>
      <anchorfile>classrcppsw_1_1control_1_1pid__loop.html</anchorfile>
      <anchor>a7095cbd5539987300a4b85ff36eb56a3</anchor>
      <arglist>(double setpoint, double pv)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>max</name>
      <anchorfile>classrcppsw_1_1control_1_1pid__loop.html</anchorfile>
      <anchor>a817a1d834b7c2166856ca127b30364e8</anchor>
      <arglist>(double max)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>min</name>
      <anchorfile>classrcppsw_1_1control_1_1pid__loop.html</anchorfile>
      <anchor>a398c622e8ca7b872d774eec1c7dc2211</anchor>
      <arglist>(double min)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>classrcppsw_1_1control_1_1pid__loop.html</anchorfile>
      <anchor>a6692e8798ce9d318cb0be21f050b3ed9</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::control::sawtooth_waveform</name>
    <filename>classrcppsw_1_1control_1_1sawtooth__waveform.html</filename>
    <base>rcppsw::control::base_waveform</base>
    <member kind="function">
      <type></type>
      <name>sawtooth_waveform</name>
      <anchorfile>classrcppsw_1_1control_1_1sawtooth__waveform.html</anchorfile>
      <anchor>a08d627e135690da05079260001dcac51</anchor>
      <arglist>(const struct config::waveform_config *const config)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>value</name>
      <anchorfile>classrcppsw_1_1control_1_1sawtooth__waveform.html</anchorfile>
      <anchor>a9b5018dfdf6d0a880f56113a15f5b896</anchor>
      <arglist>(double time) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::control::sine_waveform</name>
    <filename>classrcppsw_1_1control_1_1sine__waveform.html</filename>
    <base>rcppsw::control::base_waveform</base>
    <member kind="function">
      <type></type>
      <name>sine_waveform</name>
      <anchorfile>classrcppsw_1_1control_1_1sine__waveform.html</anchorfile>
      <anchor>aec5fe745655e26671ebaada1330af36d</anchor>
      <arglist>(const struct config::waveform_config *const config)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>value</name>
      <anchorfile>classrcppsw_1_1control_1_1sine__waveform.html</anchorfile>
      <anchor>ae685a834fe473c1b0a838a28fe7af637</anchor>
      <arglist>(double time) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::control::square_waveform</name>
    <filename>classrcppsw_1_1control_1_1square__waveform.html</filename>
    <base>rcppsw::control::base_waveform</base>
    <member kind="function">
      <type></type>
      <name>square_waveform</name>
      <anchorfile>classrcppsw_1_1control_1_1square__waveform.html</anchorfile>
      <anchor>ac7b7f84907d640e166fc944746d10ba2</anchor>
      <arglist>(const struct config::waveform_config *const config)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>value</name>
      <anchorfile>classrcppsw_1_1control_1_1square__waveform.html</anchorfile>
      <anchor>a709f48b6f560d807d93b55c0e3e30ce6</anchor>
      <arglist>(double time) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::control::waveform_generator</name>
    <filename>classrcppsw_1_1control_1_1waveform__generator.html</filename>
    <base>releasing_factory&lt; base_waveform, std::string, const config::waveform_config * &gt;</base>
    <member kind="function">
      <type></type>
      <name>waveform_generator</name>
      <anchorfile>classrcppsw_1_1control_1_1waveform__generator.html</anchorfile>
      <anchor>a7bedb9295a9f441546c40728ae3e33b3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; base_waveform &gt;</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1control_1_1waveform__generator.html</anchorfile>
      <anchor>a9dfdc263f32ede6751b855000726c498</anchor>
      <arglist>(const std::string &amp;name, const config::waveform_config *config)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kConstant</name>
      <anchorfile>classrcppsw_1_1control_1_1waveform__generator.html</anchorfile>
      <anchor>a98ea4eba631e0be5f794006890233fbe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kNull</name>
      <anchorfile>classrcppsw_1_1control_1_1waveform__generator.html</anchorfile>
      <anchor>a9db80ced1b1036d7727ab63058b2e10d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kSawtooth</name>
      <anchorfile>classrcppsw_1_1control_1_1waveform__generator.html</anchorfile>
      <anchor>a869766a5352ad4a9ec3bd2af58ef56ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kSine</name>
      <anchorfile>classrcppsw_1_1control_1_1waveform__generator.html</anchorfile>
      <anchor>a6be555947c2eb4be1ee6db636300e18a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kSquare</name>
      <anchorfile>classrcppsw_1_1control_1_1waveform__generator.html</anchorfile>
      <anchor>a44af0522714edee1f87667ff01f83ad1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::base_grid2D</name>
    <filename>classrcppsw_1_1ds_1_1base__grid2D.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>typename grid_type::template const_array_view&lt; 2 &gt;::type</type>
      <name>const_grid_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a433ac412b78d0e738d6047d279268320</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>math::vector2z</type>
      <name>coord_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ae339553851df15f8f7aefe6a6f57c72a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename boost::multi_array&lt; T, 2 &gt;</type>
      <name>grid_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ad19d9d6e335f964dff08c70eef52e0df</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename grid_type::template array_view&lt; 2 &gt;::type</type>
      <name>grid_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a76b5b8f35edb7150f4a4979873909b95</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename grid_type::index_range</type>
      <name>index_range</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ace9c01b56b8abc56386820ca76f09a3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>T</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a318959506293c356361a85c257bf73e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a89317145ba9cffd5f4e3ffc7b05a8228</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a2b4535cf583ec4757f5a9eac139fa003</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a0ccf9f68d376e5224c5e6af9e8b284b4</anchor>
      <arglist>(const coord_type &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a2f4cc209ed97a5d839d88e8a3268bfd6</anchor>
      <arglist>(const coord_type &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a0906773f3ee17e64c0874bd01f7d86ac</anchor>
      <arglist>(size_t i, size_t j) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>af3ab1b118dee3d55ea6564f2c0fa4244</anchor>
      <arglist>(size_t i, size_t j)=0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>aec06b76a62751145dcaad60f8e001777</anchor>
      <arglist>(const coord_type &amp;pt)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a96a44cd104539a2f681558d8f20aa4c4</anchor>
      <arglist>(size_t i, size_t j)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator[]</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a3deeb0565d9bb7e0c3313c04ceb72f0f</anchor>
      <arglist>(const coord_type &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>operator[]</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a13341425f16780147dbbcd9f2269dd62</anchor>
      <arglist>(const coord_type &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>subcircle</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a658148f2773c6efda3bc711b84855d0a</anchor>
      <arglist>(const coord_type &amp;c, size_t radius)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>subcircle</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a40d2a2eeed1e52ec8a59d4537251eca2</anchor>
      <arglist>(const coord_type &amp;c, size_t radius) const</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>subgrid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a0b95f4e005e63c77eec289688afddb76</anchor>
      <arglist>(const coord_type &amp;ll, const coord_type &amp;ur)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>subgrid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>af92232745f930301e5c99df9d43d4995</anchor>
      <arglist>(const coord_type &amp;ll, const coord_type &amp;ur) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>a4ff0f254c0950348156ec474a8f6f9e8</anchor>
      <arglist>(void) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>aae9c14bf203200aaed9b2ca3e90024f7</anchor>
      <arglist>(void) const =0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual const grid_type &amp;</type>
      <name>grid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ab8d872cac35bd4bb1331735e0b4dbed3</anchor>
      <arglist>(void) const =0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual grid_type &amp;</type>
      <name>grid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid2D.html</anchorfile>
      <anchor>ad5a010725166c053ac5c9e1cefd16c67</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::base_grid3D</name>
    <filename>classrcppsw_1_1ds_1_1base__grid3D.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>typename grid_type::template const_array_view&lt; 3 &gt;::type</type>
      <name>const_grid_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a11f0150a4712763146110d537c54a845</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>rmath::vector3z</type>
      <name>coord_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a5bbb33160f11fe1da0e514e6cae6137f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename boost::multi_array&lt; T, 3 &gt;</type>
      <name>grid_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a12c8081a19d25404fbe90644e80d52a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename grid_type::template array_view&lt; 3 &gt;::type</type>
      <name>grid_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>aaed03eaf8692fd97ec345336d7f5c02d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename grid_type::index_range</type>
      <name>index_range</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>aa2c6c466838e04dbc65c24ebb27e1baa</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>T</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>aee4614688e422a4ebff86371057487c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_grid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a98630a3263180ffce82dedfe146b5cb8</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_grid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a9ab7a2cdb1230dd391a9eaf1849f624a</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a78d172bf2633fc0aa93f12f13c3d6ab5</anchor>
      <arglist>(const coord_type &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a08257423dfc688b275fb26a29dd7b9f7</anchor>
      <arglist>(const coord_type &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a0c9b342c2cc3b9ec68233489eba29bb6</anchor>
      <arglist>(size_t i, size_t j, size_t k) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a05eff4a346b7a328df19257206129686</anchor>
      <arglist>(size_t i, size_t j, size_t k)=0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a422e5f43277bd0bbe48d8007a433c087</anchor>
      <arglist>(const coord_type &amp;pt)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>aab1aa33a5733948556a87562d27656e6</anchor>
      <arglist>(size_t i, size_t j, size_t k)</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>layer</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a2050360303873cf0af2c5bdc0d2c2d87</anchor>
      <arglist>(size_t z)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>layer</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a829b5ba9183465925d1f0419210178ae</anchor>
      <arglist>(size_t z) const</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator[]</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a9210a9e7e110aa4a16f5c4d89ee90748</anchor>
      <arglist>(const coord_type &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>operator[]</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a986b32fdf343b43ae6726a46dc23c8b0</anchor>
      <arglist>(const coord_type &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>subcircle</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a6a3ae0e9a28e50781ca9e21a04c194f5</anchor>
      <arglist>(const coord_type &amp;c, size_t radius)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>subcircle</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a00b0b17091ae0db0006aed2f4727cf87</anchor>
      <arglist>(const coord_type &amp;c, size_t radius) const</arglist>
    </member>
    <member kind="function">
      <type>grid_view</type>
      <name>subgrid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a07bab3b66558618e52cb8d99364f4716</anchor>
      <arglist>(const coord_type &amp;ll, const coord_type &amp;ur)</arglist>
    </member>
    <member kind="function">
      <type>const_grid_view</type>
      <name>subgrid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>acc0579502af1077c1662faa7031c4966</anchor>
      <arglist>(const coord_type &amp;ll, const coord_type &amp;ur) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a46f68ceadbbc4797cc51e7e35a658e34</anchor>
      <arglist>(void) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>ade178e757b57e3b7d0d6150cce12f7bf</anchor>
      <arglist>(void) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>zsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a8a76901a1d4b4910a7acfadfa2fadc0a</anchor>
      <arglist>(void) const =0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual const grid_type &amp;</type>
      <name>grid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>ab15b0f41b6390a5af5042941e9aa57e8</anchor>
      <arglist>(void) const =0</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual grid_type &amp;</type>
      <name>grid</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid3D.html</anchorfile>
      <anchor>a83721a9d073cb119200ccddf93bbf99f</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::base_grid_overlay</name>
    <filename>classrcppsw_1_1ds_1_1base__grid__overlay.html</filename>
    <templarg></templarg>
    <base>client&lt; base_grid_overlay&lt; TOriginType &gt; &gt;</base>
    <member kind="typedef">
      <type>typename std::conditional&lt; std::is_same&lt; TOriginType, math::vector2z &gt;::value, math::vector2z, math::vector3z &gt;::type</type>
      <name>origin_dtype</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>a96e5b9199f0d17c8c3c33961ab2f5189</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename std::conditional&lt; std::is_same&lt; TOriginType, math::vector2d &gt;::value, math::vector2d, math::vector3d &gt;::type</type>
      <name>origin_rtype</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>afe8b9dc76f0d8b237f8ea794479966dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_grid_overlay</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>ac2caf268914e47144c6522fe40659f2f</anchor>
      <arglist>(const origin_rtype &amp;origin, const types::discretize_ratio &amp;grid_resolution, const types::discretize_ratio &amp;field_resolution)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_grid_overlay</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>afb568100d17252a34e067bbc1dc21fbf</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>const origin_dtype &amp;</type>
      <name>origind</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>ad2539759a5ec1dc2990a2d7b003ec26b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const origin_rtype &amp;</type>
      <name>originr</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>adc80be69e0e1700c2337c0da479481a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const types::discretize_ratio &amp;</type>
      <name>resolution</name>
      <anchorfile>classrcppsw_1_1ds_1_1base__grid__overlay.html</anchorfile>
      <anchor>a54243210a50361cc50a9359632d99f0c</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::ds::graph::base_vertex_property</name>
    <filename>structrcppsw_1_1ds_1_1graph_1_1base__vertex__property.html</filename>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::graph::detail::hgrid3D_view_builder</name>
    <filename>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>typename TSpecType::bgl_impl_type</type>
      <name>bgl_impl_type</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</anchorfile>
      <anchor>a1d54985ebe17ba22cf41f83f54c8acae</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::edge_descriptor</type>
      <name>edge_descriptor</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</anchorfile>
      <anchor>a6cdf76c6cd49341fd9cb99a19c2a4d2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::vertex_descriptor</type>
      <name>vertex_descriptor</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</anchorfile>
      <anchor>a78c98a3c55e61c751b0a2c0aa5bc9657</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hgrid3D_view_builder</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</anchorfile>
      <anchor>a684694ebd3924b8513bb5683fca20366</anchor>
      <arglist>(const bgl_impl_type &amp;graph, const vertex_descriptor &amp;start, size_t max_dist, boost::optional&lt; rmath::vector3z &gt; axis)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</anchorfile>
      <anchor>a4a359569b7f1837c28b0f221fc0a2933</anchor>
      <arglist>(edge_descriptor) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</anchorfile>
      <anchor>a4ccfc089a3e4ca82c7f8eab8c80dc44d</anchor>
      <arglist>(vertex_descriptor vd) const</arglist>
    </member>
    <member kind="function">
      <type>const trace_data &amp;</type>
      <name>trace</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</anchorfile>
      <anchor>a45fb5184e8ff3dc6c122756293e112d3</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::ds::graph::detail::hgrid3D_view_builder::trace_data</name>
    <filename>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</filename>
    <anchor>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder_1_1trace__data</anchor>
    <member kind="variable">
      <type>rmath::vector3z</type>
      <name>ll</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</anchorfile>
      <anchor>acab4be570b19deb95f7fcfcfcaa9beac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>rmath::vector3z</type>
      <name>ur</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__builder.html</anchorfile>
      <anchor>ad87a08d1d08d955c5d19f94ca2d0544d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::graph::detail::hgrid3D_view_filter</name>
    <filename>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__filter.html</filename>
    <templarg></templarg>
    <base>client&lt; hgrid3D_view_filter&lt; TSpecType &gt; &gt;</base>
    <member kind="typedef">
      <type>typename TSpecType::bgl_impl_type</type>
      <name>bgl_impl_type</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__filter.html</anchorfile>
      <anchor>a9f9471f437bdc24ce632b254d5a49218</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::edge_descriptor</type>
      <name>edge_descriptor</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__filter.html</anchorfile>
      <anchor>a9825c1eaceebf56dc5250ca57f29c84e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename TSpecType::vertex_coord_type</type>
      <name>vertex_coord_type</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__filter.html</anchorfile>
      <anchor>ab0f3ff6f574104c9b11cbeb59eaeb45b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::vertex_descriptor</type>
      <name>vertex_descriptor</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__filter.html</anchorfile>
      <anchor>a5977462823c9d68619eb7cc720208639</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::vertex_property_type</type>
      <name>vertex_property_type</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__filter.html</anchorfile>
      <anchor>a96eb53a078c8d36e5fbd57290d220684</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hgrid3D_view_filter</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__filter.html</anchorfile>
      <anchor>aebabb078f06f885bc2185e731d86ccca</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; hgrid3D_view_filter_data&lt; TSpecType &gt; &gt;</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1detail_1_1hgrid3D__view__filter.html</anchorfile>
      <anchor>a82980c92d7450ac12e1f491fa1303bda</anchor>
      <arglist>(const bgl_impl_type &amp;graph, const vertex_descriptor &amp;start, const rtypes::manhattan_dist &amp;max_dist, boost::optional&lt; vertex_coord_type &gt; axis) const</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::ds::graph::detail::is_decorator</name>
    <filename>structrcppsw_1_1ds_1_1graph_1_1detail_1_1is__decorator.html</filename>
    <templarg></templarg>
    <templarg></templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::ds::graph::detail::is_decorator&lt; T, std::void_t&lt; decltype(std::declval&lt; T &gt;().decoratee())&gt; &gt;</name>
    <filename>structrcppsw_1_1ds_1_1graph_1_1detail_1_1is__decorator_3_01T_00_01std_1_1void__t_3_01decltype_0797869b44197aeec6ced20fc5796ab80b.html</filename>
    <templarg></templarg>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::graph::directed_graph</name>
    <filename>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</filename>
    <templarg></templarg>
    <base>decorator&lt; TSpecType::bgl_impl_type &gt;</base>
    <member kind="typedef">
      <type>typename spec_type::bgl_impl_type</type>
      <name>bgl_impl_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a01e01cd2bd17a25438435ade77a04457</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename rpdecorator::decorator&lt; bgl_impl_type &gt;::decoratee_type</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a4cd52f8618684dc661ae5556e78460ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename rpdecorator::decorator&lt; bgl_impl_type &gt;::decorator_type</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a739da315cb21d57623d908559540d932</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::edge_property_type</type>
      <name>edge_property_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>aa10bafa99047e003d7768b2d6bd8f4e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TSpecType</type>
      <name>spec_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a7e7a147797c9f3251a2a47b6921d4ee7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::vertex_property_type</type>
      <name>vertex_property_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a3124d99872c2ba074fe74c46f430e64b</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>directed_graph</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a7dcea262b3ff7690f7059b85025cb2a9</anchor>
      <arglist>(const directed_graph &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>directed_graph</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a0284109da9a872723749266db2f47d6c</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>aaf374260625dd132037b47fa01c59015</anchor>
      <arglist>(directed_category)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a73599224aaf39b88c84fb73951b10188</anchor>
      <arglist>(edge_descriptor)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a4b89fbe3d0a1dd9176080628c8fc069a</anchor>
      <arglist>(edge_parallel_category)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>ac76725d7b04c7e9e614e7c8768d70a20</anchor>
      <arglist>(traversal_category)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a3518df8d9e707ef4a666d00e17fbe156</anchor>
      <arglist>(vertex_descriptor)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a2d4f57d8a464008a3585c988bbfa5c61</anchor>
      <arglist>(vertex_iterator)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a771e55e7ba7c53667f2bad052b4e2960</anchor>
      <arglist>(operator[])</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a09672e4e01638728933d5e0b32ecd5de</anchor>
      <arglist>(operator[], const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>af081fcbf62ca8025ae273f4be1c9f471</anchor>
      <arglist>(rdgraph, add_edge)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>ab9985f704a58ed1885504226f29b3c7c</anchor>
      <arglist>(rdgraph, add_vertex)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a3b9fd22f6a5faf05ad6f3d6bcd13a74c</anchor>
      <arglist>(rdgraph, adjacent_vertices)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>aa835d453ec37ce93f1da9ef41f8d8de1</anchor>
      <arglist>(rdgraph, adjacent_vertices, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a817e267250b6a4762512148149f3a349</anchor>
      <arglist>(rdgraph, find)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>ad7f91e580c422d24301a79b0f5558c63</anchor>
      <arglist>(rdgraph, find, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>aa0e5aacc5e4ae27aef7723a56d3a2914</anchor>
      <arglist>(rdgraph, n_vertices, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a42571fe9c35732398b345190d22e5c98</anchor>
      <arglist>(rdgraph, out_edges, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a1e86dc18f5fccfefb5157f51b729c198</anchor>
      <arglist>(rdgraph, remove_vertex)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>addb6bb2e272cb2283a42b6a6973b15ef</anchor>
      <arglist>(rdgraph, target)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>aeac4d00f3c93ee911de69b6bc53be248</anchor>
      <arglist>(rdgraph, target, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a803b4b2e7d200dd70315a8e08cfc409b</anchor>
      <arglist>(rdgraph, vertices)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1directed__graph.html</anchorfile>
      <anchor>a11fc018e8a01af84aefb4d086619decc</anchor>
      <arglist>(rdgraph, vertices, const)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::ds::graph::directed_graph_spec</name>
    <filename>namespacercppsw_1_1ds_1_1graph.html</filename>
    <anchor>structrcppsw_1_1ds_1_1graph_1_1directed__graph__spec</anchor>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="typedef">
      <type>boost::adjacency_list&lt; vertex_edge_list_type, vertex_list_type, directedness_type, vertex_property_type, edge_property_type, graph_property_type, graph_edge_list_type &gt;</type>
      <name>bgl_impl_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a258ba71680b6ddac71ec566017e971a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::directedS</type>
      <name>directedness_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a5bc6f44f63c765e4911945966ddb95f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TEdgePropertyType</type>
      <name>edge_property_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a6680b8234fa5f6027f980a6223898545</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::listS</type>
      <name>graph_edge_list_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a89baad1c0025aca9fdf7ae13bb42aa13</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::no_property</type>
      <name>graph_property_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a3cc17ac4bc098b49ae32b491c1b1bba5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::vecS</type>
      <name>vertex_edge_list_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a280599728b4d0b75f40c6af6c52a660f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::listS</type>
      <name>vertex_list_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a3280d187adf08e7003ae46a8299d9b30</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TVertexPropertyType</type>
      <name>vertex_property_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a32bcd29175fa1444dfa3d659357f79dd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::graph::grid_index_map</name>
    <filename>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>decorator&lt; std::map&lt; TGrid, TVertex, std::less&lt; TGrid &gt; &gt; &gt;</base>
    <member kind="typedef">
      <type>typename decorator_type::decoratee_type</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>ac1db8ba22924c7051310d3de81f1011c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename rpdecorator::decorator&lt; std::map&lt; TGrid, TVertex, TCompare &gt; &gt;::decorator_type</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a08df0561cc4f5e0209a6c35ef1f25b24</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_CT</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a0c7ab5af1e1b9e49b63e6923ce09a441</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a0c7bb472a2025dc4de107d3bfd8c19ab</anchor>
      <arglist>(begin)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a1d47d204060ade02fd51594bd79d9739</anchor>
      <arglist>(begin, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>ae38d6920eae699f15c54c50cc3dbc564</anchor>
      <arglist>(end)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a69f949c94d70d3c8659dc47877df9095</anchor>
      <arglist>(end, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a4bc87e2e932dc049883a869938d71615</anchor>
      <arglist>(find)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a22327314e471598a3fa589b7485068e8</anchor>
      <arglist>(find, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>acbdbed72d27d06f53a426db1d231f40e</anchor>
      <arglist>(insert)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>a451f49a3b2d28e15f4d83ecb083043d7</anchor>
      <arglist>(operator[])</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1grid__index__map.html</anchorfile>
      <anchor>af5286ed9fd911fadd44e4c055cf0447b</anchor>
      <arglist>(size, const)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::graph::hgrid3D</name>
    <filename>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</filename>
    <templarg></templarg>
    <base>decorator&lt; TSpecType::bgl_impl_type &gt;</base>
    <member kind="typedef">
      <type>typename spec_type::bgl_impl_type</type>
      <name>bgl_impl_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a51c197d66ad2f434c49f6f9dcb17af32</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename rpdecorator::decorator&lt; bgl_impl_type &gt;::decoratee_type</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a2a6168bf04f2bacb2bedcc0215654145</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename rpdecorator::decorator&lt; bgl_impl_type &gt;::decorator_type</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a50022e02ebfe70df93897c2b47660018</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::edge_property_type</type>
      <name>edge_property_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a45e6c896afcef5b11e8719a01307d119</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TSpecType</type>
      <name>spec_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a2fd176072afca3fe75451ab3ae13f03b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::vertex_coord_type</type>
      <name>vertex_coord_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a9fe87ac9d955d330e251ae1fcb48e8bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::vertex_property_type</type>
      <name>vertex_property_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>ae1fccaf93546f4d175af0e27c9bce5be</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>hgrid3D_view&lt; spec_type &gt;</type>
      <name>view_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a49827af5ba861547259caa874066af55</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hgrid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>adee911cd7208757ff433943c9073c9ee</anchor>
      <arglist>(const hgrid3D &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hgrid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>ab1000163dae3a67d669f29bd2e369405</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a00ce8151a0e9eca66d620b876f04386e</anchor>
      <arglist>(directed_category)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a115c3f3fdf98b4464d8f6876cd2967b9</anchor>
      <arglist>(edge_descriptor)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>ab8b782565d73049aedb5c8bdaa12333b</anchor>
      <arglist>(edge_parallel_category)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>afdbf2a8b78c406c6cb87f8a964108217</anchor>
      <arglist>(traversal_category)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>abc01ef9edc6c07083f7f7c88bca50281</anchor>
      <arglist>(vertex_descriptor)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>aa5cff906de8e3fe5c768d797dff39726</anchor>
      <arglist>(vertex_iterator)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>acda5b0b5d554dfcaab8a28637e1fbdd9</anchor>
      <arglist>(operator[])</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>abeb08d6a712480808104544eb8378853</anchor>
      <arglist>(operator[], const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a11f86d0cac90a04457c5c666cc13cda8</anchor>
      <arglist>(rdgraph, adjacent_vertices)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a93c5f6d644f3292f6111dc3d25f5f2c1</anchor>
      <arglist>(rdgraph, adjacent_vertices, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a526a7f9f0ce207f2a18e767a6eb986c9</anchor>
      <arglist>(rdgraph, contains, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>ab609406fe9a8625e0a6a6ecf0cbc5c36</anchor>
      <arglist>(rdgraph, find)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a2f781a94b13a6d67e4cb052d4ede5ffc</anchor>
      <arglist>(rdgraph, find, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a21b8e37787d4ccd91ee30f5286d90ab8</anchor>
      <arglist>(rdgraph, n_vertices, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a09a6423b6e721d7f8b89e7144bc46499</anchor>
      <arglist>(rdgraph, out_degree, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>ac735906955acf35ff40cf97c2f688f73</anchor>
      <arglist>(rdgraph, out_edges, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a7de5216e5af5778e449fc429b8e4f2f0</anchor>
      <arglist>(rdgraph, target)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>aa411149ea99eedc9a5789c9fe0188c97</anchor>
      <arglist>(rdgraph, target, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a3cde5e60180d2c9beac738a5cded8d65</anchor>
      <arglist>(rdgraph, vertices)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>a4b06b308ae2d59ae3e8c0f3b1e80c685</anchor>
      <arglist>(rdgraph, vertices, const)</arglist>
    </member>
    <member kind="function">
      <type>view_type</type>
      <name>subgraph</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D.html</anchorfile>
      <anchor>accbb2f2be14c8accdd00f69c01fc6815</anchor>
      <arglist>(const vertex_descriptor &amp;start, const rtypes::manhattan_dist &amp;max_dist, boost::optional&lt; rmath::vector3z &gt; axis=boost::none) const</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::ds::graph::hgrid3D_spec</name>
    <filename>namespacercppsw_1_1ds_1_1graph.html</filename>
    <anchor>structrcppsw_1_1ds_1_1graph_1_1hgrid3D__spec</anchor>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="typedef">
      <type>boost::adjacency_list&lt; vertex_edge_list_type, vertex_list_type, directedness_type, vertex_property_type, edge_property_type, graph_property_type, graph_edge_list_type &gt;</type>
      <name>bgl_impl_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a52f95b17ad9f838ed1086f7312570820</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::filtered_graph&lt; bgl_impl_type, TEdgePredicateType, TVertexPredicateType &gt;</type>
      <name>bgl_view_impl_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a01426167adfa08759378447439377ff9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::undirectedS</type>
      <name>directedness_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>af59c3abf213cf12d3243bcedec9bc6f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TEdgePropertyType</type>
      <name>edge_property_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>acc1d5b2bf863474979d5d43e13ff6ac1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::listS</type>
      <name>graph_edge_list_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>aac8a46bac1128cc9e79dd06e17fc572a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::no_property</type>
      <name>graph_property_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a03b6afc04e9dcce4d5013d068e6fd4a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decltype(hgrid3D_vertex_property::coord)</type>
      <name>vertex_coord_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>af1edfa4c355fc0eae78e9fe5c034edfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::vecS</type>
      <name>vertex_edge_list_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a635ac8767da3b37f260bced27740fdcc</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::vecS</type>
      <name>vertex_list_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a3560b2bb85d1726058e5de986567bf79</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TVertexPropertyType</type>
      <name>vertex_property_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a69eeafec0d125957364ac02c9afd48a2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::ds::graph::hgrid3D_vertex_property</name>
    <filename>structrcppsw_1_1ds_1_1graph_1_1hgrid3D__vertex__property.html</filename>
    <base>rcppsw::ds::graph::base_vertex_property</base>
    <member kind="variable">
      <type>rmath::vector3z</type>
      <name>coord</name>
      <anchorfile>structrcppsw_1_1ds_1_1graph_1_1hgrid3D__vertex__property.html</anchorfile>
      <anchor>a972b7ffdf2cc75642f761a878c7e3857</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::graph::hgrid3D_view</name>
    <filename>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</filename>
    <templarg></templarg>
    <base>decorator&lt; TSpecType::template bgl_view_impl_type&lt; hgrid3D_view_edge_filter_type&lt; TSpecType &gt;, hgrid3D_view_vertex_filter_type&lt; TSpecType &gt; &gt; &gt;</base>
    <member kind="typedef">
      <type>typename spec_type::template bgl_view_impl_type&lt; hgrid3D_view_edge_filter_type&lt; spec_type &gt;, hgrid3D_view_vertex_filter_type&lt; spec_type &gt; &gt;</type>
      <name>bgl_view_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>ade4a15eb2b34c5fe38d24f341dd8898c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename decorator_type::decoratee_type</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a9817a873e873829bcedb75ee061e84c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename rpdecorator::decorator&lt; bgl_view_type &gt;::decorator_type</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a1ed4f192292a852f5a21afed57b0a928</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::edge_property_type</type>
      <name>edge_property_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>ad57c3ada0695a2f09e5a38e49cbeade5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TSpecType</type>
      <name>spec_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a32d86b08fa6c5d991552b05e4eb77aad</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::vertex_coord_type</type>
      <name>vertex_coord_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>aa79a019bfe39322e4e656d8d6210ec8b</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::vertex_property_type</type>
      <name>vertex_property_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>aaf20c7a6835550b9daa15077e40e1fc4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>bgl_view_type</type>
      <name>view_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>ab1b7a086f5fc910c1014d080e58a311b</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hgrid3D_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a7a4ef91288b901a41e3d548a1bc0da96</anchor>
      <arglist>(bgl_view_type &amp;view, std::unique_ptr&lt; hgrid3D_view_filter_data&lt; spec_type &gt;&gt; data)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hgrid3D_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a3793dca761f64be4397fad6efd5f0194</anchor>
      <arglist>(const hgrid3D_view &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hgrid3D_view</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a63fe4be64b739a581ff63e769592c8c1</anchor>
      <arglist>(hgrid3D_view &amp;&amp;other)=default</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>bb</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a09f3f3b5dcdf590dc5a0e2d7cb9418b9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>central_vertex</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a01a73ed3102911f4e2f7292fac7d7d2e</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>aeedb1a6f292a809772830205e99ff92a</anchor>
      <arglist>(const rmath::vector3z &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>af11fc62d0355f1442eba40cc3668dc87</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>af11fc62d0355f1442eba40cc3668dc87</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>af11fc62d0355f1442eba40cc3668dc87</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>af11fc62d0355f1442eba40cc3668dc87</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>af11fc62d0355f1442eba40cc3668dc87</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>af11fc62d0355f1442eba40cc3668dc87</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>af11fc62d0355f1442eba40cc3668dc87</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>af11fc62d0355f1442eba40cc3668dc87</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>const vertex_property_type *</type>
      <name>lookup</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a734d5938bb52b46318fd6817e012a2d9</anchor>
      <arglist>(const rmath::vector3z &amp;c) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>n_vertices</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>afdcdfa278a8ee63c5ccde2d6da261697</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>hgrid3D_view &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a443c1cd89dabd360e0fbf37a6f8faa20</anchor>
      <arglist>(const hgrid3D_view &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>hgrid3D_view &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>aa3048e8276d4f95b86f307919e7d1e5b</anchor>
      <arglist>(hgrid3D_view &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>aadda73178d3e0a036b7f6c37e2bfc29e</anchor>
      <arglist>(edge_descriptor)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a420efaa93021f836e30bc084f35ec80a</anchor>
      <arglist>(vertex_descriptor)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECL</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>addf935a228b99a521490f51d60009622</anchor>
      <arglist>(vertex_iterator)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>aeab9c49402e0c3dedc3c6eccae6207ff</anchor>
      <arglist>(operator[])</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>ab6a25503f2b6424a828a69896a4a9efd</anchor>
      <arglist>(operator[], const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>ae53cffa810ce79c80c382266299ede1c</anchor>
      <arglist>(rdgraph, adjacent_vertices)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a501435133c74ee3f9735de851e6af54b</anchor>
      <arglist>(rdgraph, adjacent_vertices, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a2c069505e2211405e1df3f3f0cefd472</anchor>
      <arglist>(rdgraph, contains)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a0f8534c793b29f1ca22d007a1518ece2</anchor>
      <arglist>(rdgraph, find)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a6c56ea849bde8ac3294f36a08e080bf8</anchor>
      <arglist>(rdgraph, find, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>ab1c8c6e8c66d4df1ea02834e54188174</anchor>
      <arglist>(rdgraph, out_edges)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>abe40bd1e3796695c85fd880cc4ffe3c0</anchor>
      <arglist>(rdgraph, out_edges, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a3ba12a81c15f7ef4a2bdb9264c9b5222</anchor>
      <arglist>(rdgraph, target)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a5d684211a22b9601e51872e3a1073104</anchor>
      <arglist>(rdgraph, target, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>afb0c217743832b1a09111a5e6d9c5203</anchor>
      <arglist>(rdgraph, vertices)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF_STATIC</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view.html</anchorfile>
      <anchor>a3e9116bd3a896c5a211c8358c78885a4</anchor>
      <arglist>(rdgraph, vertices, const)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::graph::hgrid3D_view_filter_data</name>
    <filename>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</filename>
    <templarg></templarg>
    <base>client&lt; hgrid3D_view_filter_data&lt; TSpecType &gt; &gt;</base>
    <member kind="typedef">
      <type>typename TSpecType::bgl_impl_type</type>
      <name>bgl_impl_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a2ebaaed36501134082a410b4e7fe85cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::edge_descriptor</type>
      <name>edge_descriptor</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a2662c3a13d690a684854515912feb2c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::vertex_descriptor</type>
      <name>vertex_descriptor</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>aebb8d386448d350651e6e8b0c6e65b4f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename bgl_impl_type::vertex_property_type</type>
      <name>vertex_property_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>aab0a17b7becbfc073b5a2c39e1a97cc2</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hgrid3D_view_filter_data</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>abf8a36be7b7ac7ecf0ae38a400ef29d4</anchor>
      <arglist>(const rmath::vector3z &amp;center, const rtypes::manhattan_dist &amp;max_dist, size_t max_vertices)</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>center</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a5b185a20aa44b4fb661f07b5faf73d76</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; rtypes::manhattan_dist &gt; *</type>
      <name>distances</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>aedd3701c7a211bef0eade7acda9e3da4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>edge_filter</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>ade32d4bfd92d5a050516447c8d9397d8</anchor>
      <arglist>(edge_descriptor) const</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>ll</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>aa7aaf32c859f4eb3903c6047e90d59ca</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>auto *</type>
      <name>lookup</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a13f08d0e4db02cdec7be4e1ac617c6fa</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const auto *</type>
      <name>lookup</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a434438e9955422e4f7b122e790066bee</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>lr</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>af55217e6bfe226ebde6594f63a0d0a10</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>n_vertices</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a328a88b82fc23fd8fbbaa595ed03f0c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>ul</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>ad48e2d44597778c508786764eef64111</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a06850ef6c4430c4b5b2f7c71339b887f</anchor>
      <arglist>(const bgl_impl_type &amp;g, vertex_descriptor vd, const rtypes::manhattan_dist &amp;dist)</arglist>
    </member>
    <member kind="function">
      <type>const auto &amp;</type>
      <name>ur</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a17f32b998d62d05fb255cd7e04fed26a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>vertex_filter</name>
      <anchorfile>classrcppsw_1_1ds_1_1graph_1_1hgrid3D__view__filter__data.html</anchorfile>
      <anchor>a1cfdb0835bafa067d2081ad6029c2fe0</anchor>
      <arglist>(vertex_descriptor vd) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::grid2D</name>
    <filename>classrcppsw_1_1ds_1_1grid2D.html</filename>
    <templarg></templarg>
    <base>rcppsw::ds::base_grid2D</base>
    <member kind="function">
      <type></type>
      <name>grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a99f63fcb43aec7c45e2e53eb77454bfe</anchor>
      <arglist>(const coord_type &amp;dims)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a1ae0eba25bec5e4765b566e51407acaa</anchor>
      <arglist>(size_t x_max, size_t y_max)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a20714ede13a3a24b5124da2cf5d68f64</anchor>
      <arglist>(size_t i, size_t j) override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a9d7cb43e0ae820ecbd02601eb5130e45</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D.html</anchorfile>
      <anchor>a79b4d97c9e50fc8f4677d3aadf4e485f</anchor>
      <arglist>(void) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::grid2D_overlay</name>
    <filename>classrcppsw_1_1ds_1_1grid2D__overlay.html</filename>
    <templarg></templarg>
    <base>rcppsw::ds::base_grid2D</base>
    <base>base_grid_overlay&lt; math::vector2d &gt;</base>
    <base>client&lt; grid2D_overlay&lt; T &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>grid2D_overlay</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D__overlay.html</anchorfile>
      <anchor>a8ff704bb3864089febb5e566ea8a6605</anchor>
      <arglist>(const math::vector2d &amp;origin, const math::vector2d &amp;dims, const types::discretize_ratio &amp;grid_res, const types::discretize_ratio &amp;field_res)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D__overlay.html</anchorfile>
      <anchor>a35d821709e46997b393965dea26d579c</anchor>
      <arglist>(size_t i, size_t j) override</arglist>
    </member>
    <member kind="function">
      <type>coord_type</type>
      <name>ddims2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D__overlay.html</anchorfile>
      <anchor>a8a785a7fa403df17bfa11c9a5746185a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const math::vector2d &amp;</type>
      <name>rdims2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D__overlay.html</anchorfile>
      <anchor>ac8fd2c8a445603ac6fb2defc0e89964c</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>xdsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D__overlay.html</anchorfile>
      <anchor>a312fceb52e79f9c9d5381fe97c6d26c3</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>xrsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D__overlay.html</anchorfile>
      <anchor>a127b5b97fb0b1ca888fb2bb838665965</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>ydsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D__overlay.html</anchorfile>
      <anchor>ac49cd6926dc2fe3ebf36296c47c7fbf2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>yrsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid2D__overlay.html</anchorfile>
      <anchor>a162e17d6011cad9ab10ba82ab9c78a6d</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::grid3D</name>
    <filename>classrcppsw_1_1ds_1_1grid3D.html</filename>
    <templarg></templarg>
    <base>rcppsw::ds::base_grid3D</base>
    <member kind="function">
      <type></type>
      <name>grid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a9ced942f54c5ddbd3d134933c41356d4</anchor>
      <arglist>(const coord_type &amp;dims)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>grid3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a5afad89295fd0430a4a572f7c38c20ca</anchor>
      <arglist>(size_t x_max, size_t y_max, size_t z_max)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a0d73673d2360919a8be92eb0ccbd501f</anchor>
      <arglist>(size_t i, size_t j, size_t k) override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a32398b282a42be7e82df930b5902bfd4</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>aa868060e23e0ada5282f472d2957f472</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>zsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D.html</anchorfile>
      <anchor>a25bf450199dfe72bd1f82d1d3cea7a88</anchor>
      <arglist>(void) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::grid3D_overlay</name>
    <filename>classrcppsw_1_1ds_1_1grid3D__overlay.html</filename>
    <templarg></templarg>
    <base>rcppsw::ds::base_grid3D</base>
    <base>base_grid_overlay&lt; math::vector3d &gt;</base>
    <base>client&lt; grid3D_overlay&lt; T &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>grid3D_overlay</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>a73148c5eb0b0e24b0cd4b931b37d4c69</anchor>
      <arglist>(const math::vector3d &amp;origin, const math::vector3d &amp;dim, const types::discretize_ratio &amp;grid_res, const types::discretize_ratio &amp;field_res)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~grid3D_overlay</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>ab4a619af34c49aa6ad3a9b6729cc7069</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>a0fa4f281d3006096d8f2b30ca7584790</anchor>
      <arglist>(size_t i, size_t j, size_t k) override</arglist>
    </member>
    <member kind="function">
      <type>coord_type</type>
      <name>ddims3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>ac7dcd5fed98029af9630f4cb8388b99a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const math::vector3d &amp;</type>
      <name>rdims3D</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>a8dc04d7e52ae53a44dcdf48b47f9c336</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>xdsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>a40b506f9bef93959c6a78cf50cf528ff</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>xrsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>ad82bb5a3d6c6de2a736d809f7a132b79</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>ydsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>a7e83f946ea61a38592c6420d0257a044</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>yrsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>add39dc4e75be6f2ca271cb3aec41fd9a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>zdsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>ae9638e03951dc754bd026d03685b6a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>zrsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1grid3D__overlay.html</anchorfile>
      <anchor>a03bfc8b04a08e70102738abe972c97c0</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::metrics::grid2D_metrics_collector</name>
    <filename>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__collector.html</filename>
    <base>rcppsw::metrics::base_collector</base>
    <member kind="function">
      <type></type>
      <name>grid2D_metrics_collector</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__collector.html</anchorfile>
      <anchor>a17dfb84ad085ce6628caed6df72dbc01</anchor>
      <arglist>(std::unique_ptr&lt; rmetrics::base_sink &gt; sink, const math::vector2z &amp;dims)</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__collector.html</anchorfile>
      <anchor>ac8d33303e8a9bd90f7ecb1be2de3f473</anchor>
      <arglist>(Args &amp;&amp;... args) -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__collector.html</anchorfile>
      <anchor>ac8d33303e8a9bd90f7ecb1be2de3f473</anchor>
      <arglist>(Args &amp;&amp;... args) -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const rmetrics::base_data *</type>
      <name>data</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__collector.html</anchorfile>
      <anchor>a1939e3abed4e63e3e056732ef323427e</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>inc_cell_count</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__collector.html</anchorfile>
      <anchor>a2cde6fa21cee2949c572dbbdc996c5d8</anchor>
      <arglist>(const math::vector2z &amp;c, size_t count=1)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>inc_total_count</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__collector.html</anchorfile>
      <anchor>a0b393d365341e9544051fdf87da93c6f</anchor>
      <arglist>(size_t count=1)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::metrics::grid2D_metrics_csv_sink</name>
    <filename>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__csv__sink.html</filename>
    <templarg></templarg>
    <base>rcppsw::metrics::csv_sink</base>
    <member kind="function">
      <type></type>
      <name>grid2D_metrics_csv_sink</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__csv__sink.html</anchorfile>
      <anchor>ac868ccb43150922e003753690e4a5027</anchor>
      <arglist>(const std::string &amp;fpath_stem, const rmetrics::output_mode &amp;mode, const types::timestep &amp;interval)</arglist>
    </member>
    <member kind="function">
      <type>std::list&lt; std::string &gt;</type>
      <name>csv_header_cols</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__csv__sink.html</anchorfile>
      <anchor>afe2ee5935c9266a75a1fb8e9575f799c</anchor>
      <arglist>(const rmetrics::base_data *data) const override</arglist>
    </member>
    <member kind="function">
      <type>boost::optional&lt; std::string &gt;</type>
      <name>csv_line_build</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__csv__sink.html</anchorfile>
      <anchor>a6cce01da4d33cec5a7943ce7c054774f</anchor>
      <arglist>(const rmetrics::base_data *data, const rtypes::timestep &amp;t) override</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>rcppsw::ds::metrics::grid2D_metrics_data</name>
    <filename>structrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__data.html</filename>
    <base>rcppsw::metrics::base_data</base>
    <member kind="function">
      <type></type>
      <name>grid2D_metrics_data</name>
      <anchorfile>structrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__data.html</anchorfile>
      <anchor>a843502873ca2a016c9fbd2a031e8cd43</anchor>
      <arglist>(const math::vector2z &amp;dims)</arglist>
    </member>
    <member kind="variable">
      <type>rcppsw::ds::grid2D&lt; ral::mt_size_t &gt;</type>
      <name>grid</name>
      <anchorfile>structrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__data.html</anchorfile>
      <anchor>a91720446563f9f0d0da9470c5f94335b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ral::mt_size_t</type>
      <name>total_count</name>
      <anchorfile>structrcppsw_1_1ds_1_1metrics_1_1grid2D__metrics__data.html</anchorfile>
      <anchor>a0377ff8c10e78e20dc9f079d54cf4061</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::metrics::grid3D_metrics_collector</name>
    <filename>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__collector.html</filename>
    <base>rcppsw::metrics::base_collector</base>
    <member kind="function">
      <type></type>
      <name>grid3D_metrics_collector</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__collector.html</anchorfile>
      <anchor>a0111de4487ef2ddd192d2623f184043c</anchor>
      <arglist>(std::unique_ptr&lt; rmetrics::base_sink &gt; sink, const math::vector3z &amp;dims)</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__collector.html</anchorfile>
      <anchor>a0ae541858dc10b30e640ce7659a954b6</anchor>
      <arglist>(Args &amp;&amp;... args) -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__collector.html</anchorfile>
      <anchor>a0ae541858dc10b30e640ce7659a954b6</anchor>
      <arglist>(Args &amp;&amp;... args) -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__collector.html</anchorfile>
      <anchor>a0ae541858dc10b30e640ce7659a954b6</anchor>
      <arglist>(Args &amp;&amp;... args) -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const rmetrics::base_data *</type>
      <name>data</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__collector.html</anchorfile>
      <anchor>a95c775666d5905bddf0a355c1e02a893</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>inc_cell_count</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__collector.html</anchorfile>
      <anchor>a3affa91d3b3208e8e9340548910d2657</anchor>
      <arglist>(const math::vector3z &amp;c, size_t count=1)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>inc_total_count</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__collector.html</anchorfile>
      <anchor>a50f46a73281a92036951075abb1d5d7b</anchor>
      <arglist>(size_t count=1)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::metrics::grid3D_metrics_csv_sink</name>
    <filename>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__csv__sink.html</filename>
    <templarg></templarg>
    <base>rcppsw::metrics::csv_sink</base>
    <member kind="function">
      <type></type>
      <name>grid3D_metrics_csv_sink</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__csv__sink.html</anchorfile>
      <anchor>ab173dab62aefb939e0a83e35d534907c</anchor>
      <arglist>(const std::string &amp;fpath_stem, const rmetrics::output_mode &amp;mode, const types::timestep &amp;interval)</arglist>
    </member>
    <member kind="function">
      <type>std::list&lt; std::string &gt;</type>
      <name>csv_header_cols</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__csv__sink.html</anchorfile>
      <anchor>a5cb4bed8b95ef64a834586caa629fce2</anchor>
      <arglist>(const rmetrics::base_data *data) const override</arglist>
    </member>
    <member kind="function">
      <type>boost::optional&lt; std::string &gt;</type>
      <name>csv_line_build</name>
      <anchorfile>classrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__csv__sink.html</anchorfile>
      <anchor>ab0eff365bb92b5d91f983dbd1d94bb28</anchor>
      <arglist>(const rmetrics::base_data *data, const rtypes::timestep &amp;t) override</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>rcppsw::ds::metrics::grid3D_metrics_data</name>
    <filename>structrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__data.html</filename>
    <base>rcppsw::metrics::base_data</base>
    <member kind="function">
      <type></type>
      <name>grid3D_metrics_data</name>
      <anchorfile>structrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__data.html</anchorfile>
      <anchor>a970fc62642b7b2973b205de82fa771fb</anchor>
      <arglist>(const math::vector3z &amp;dims)</arglist>
    </member>
    <member kind="variable">
      <type>rcppsw::ds::grid3D&lt; ral::mt_size_t &gt;</type>
      <name>grid</name>
      <anchorfile>structrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__data.html</anchorfile>
      <anchor>a8136d59a45a44e9b22fb438baed66d5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ral::mt_size_t</type>
      <name>total_count</name>
      <anchorfile>structrcppsw_1_1ds_1_1metrics_1_1grid3D__metrics__data.html</anchorfile>
      <anchor>a5d81f904b8bb2888704c80af84795d60</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::poisson_queue</name>
    <filename>classrcppsw_1_1ds_1_1poisson__queue.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>poisson_queue</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a2d88a7e757d18698a16868aa353bb365</anchor>
      <arglist>(const poisson_queue &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>poisson_queue</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>aefc3504e7b08b9fb406f3322c9aa26fe</anchor>
      <arglist>(double lambda, double mu, math::rng *rng)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a1d3117f7971bc149d4d38bcac031ce40</anchor>
      <arglist>(const T &amp;key) const</arglist>
    </member>
    <member kind="function">
      <type>boost::optional&lt; T &gt;</type>
      <name>dequeue</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>abdc9429ec4656fefd52202846966fd53</anchor>
      <arglist>(const types::timestep &amp;t, bool fake)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>dequeue_check</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>abed5cdf82164fe9fed62174fe6f2bced</anchor>
      <arglist>(const types::timestep &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>op_metadata</type>
      <name>dequeue_data</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a50b34a5f6fb667c3e65bc7fa53da1f76</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>enqueue</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a609ab14ea489f180bfe0f4fde6592e04</anchor>
      <arglist>(const T &amp;item, const types::timestep &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>enqueue_check</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a8e2343d5a9e84e3d1ac4dfc8f6499e2a</anchor>
      <arglist>(const types::timestep &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>op_metadata</type>
      <name>enqueue_data</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>aaff0fe8f7b42a26d1474e4abd6f7ca60</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a701ccfd4cf6b204df2ee05c182ebeae4</anchor>
      <arglist>(Args &amp;&amp;... args) -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a0aafa3dc89cb688ceb3c65ed1d96a766</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>lambda</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a6d24bf0b8fa3f6f67e032b3e86913c6b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>mu</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>af4c7166f6afa916545b9f376aaf4f9b6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const poisson_queue &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>adf98c441abafbae970c7c78076d40949</anchor>
      <arglist>(const poisson_queue &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset_metrics</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>ad3d4f66311f6822c6d4ee532a6adb68d</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::ds::poisson_queue::op_metadata</name>
    <filename>classrcppsw_1_1ds_1_1poisson__queue.html</filename>
    <anchor>structrcppsw_1_1ds_1_1poisson__queue_1_1op__metadata</anchor>
    <member kind="variable">
      <type>size_t</type>
      <name>count</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a18fd344168562e3a6e88a4da7d3279d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>types::timestep</type>
      <name>interval_accum</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>ab8ee7325dbbbec286735941d6f46ffca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>size_t</type>
      <name>total_count</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>a797c69f7315c9aa42e63ab2d93f07d72</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>types::timestep</type>
      <name>total_interval_accum</name>
      <anchorfile>classrcppsw_1_1ds_1_1poisson__queue.html</anchorfile>
      <anchor>ac14f5d9774cedd0beec1f950335f14eb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::rtree</name>
    <filename>classrcppsw_1_1ds_1_1rtree.html</filename>
    <templarg></templarg>
    <base protection="private">decorator&lt; TSpecType::tree_type &gt;</base>
    <member kind="typedef">
      <type>typename spec_type::coord_type</type>
      <name>coord_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a7c64c4a1254c2434d2bbea4927fef923</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::element_type</type>
      <name>element_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>ace1800dafdf6daed6b6c2bd153d405f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::geometry_type</type>
      <name>geometry_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>ad793e193bdeba029bd2a8eefcfd4a33d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TSpecType</type>
      <name>spec_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a9839a5d4fa134589d676b55df649ccda</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename spec_type::value_type</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a87914a1ab6098b747e35067e44afc883</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>rtree</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a4c918a9326f3a831ee698e4f0ba03d58</anchor>
      <arglist>(const rtree &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>rtree</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>ab38cad0f92eceb522bfd10ea76efe365</anchor>
      <arglist>(rtree &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>rtree</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>aa4de5f185c7e9701e0496c9c0e1a97d1</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a773b98e704f7ddb7483516b38ad73818</anchor>
      <arglist>(const value_type &amp;key) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a65cf686ea1ae2627b8d42bcce8be0ddf</anchor>
      <arglist>(const value_type &amp;value, const geometry_type &amp;key)</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; value_type &gt;</type>
      <name>intersections</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a251ac583c53d6807ffb9c1b48f3f0c01</anchor>
      <arglist>(const rtree_box&lt; coord_type &gt; &amp;query) const</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; value_type &gt;</type>
      <name>nearest</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a5d295fd83ae5297e278b724bbe1e92ca</anchor>
      <arglist>(const rtree_point&lt; coord_type &gt; &amp;query, size_t k) const</arglist>
    </member>
    <member kind="function">
      <type>const rtree &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a11e26ad5a252a429e4e07ab3f800bbaf</anchor>
      <arglist>(const rtree &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>rtree &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>aba93e1a3a67019c840f90e19dd5ee682</anchor>
      <arglist>(rtree &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>ae5ca1a2ef5598bf906647c9ab774617d</anchor>
      <arglist>(begin, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>ac3edf4479b072eb112914fa1b4135d56</anchor>
      <arglist>(end, const)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>aa63319e075ce6eed5cdf9ad455fca97e</anchor>
      <arglist>(insert)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RCPPSW_DECORATE_DECLDEF</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a3b86c0295c499d526cc86d6978669c4b</anchor>
      <arglist>(size, const)</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>remove</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>a0a5e061d3ed4cc55a93174110837c62d</anchor>
      <arglist>(const value_type &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>remove</name>
      <anchorfile>classrcppsw_1_1ds_1_1rtree.html</anchorfile>
      <anchor>ab20cf99176a0cf4861b6474b6cb6bde1</anchor>
      <arglist>(const value_type &amp;value, const geometry_type &amp;key)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::ds::rtree_spec</name>
    <filename>structrcppsw_1_1ds_1_1rtree__spec.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>MAXELTS</templarg>
    <member kind="typedef">
      <type>TCoordType</type>
      <name>coord_type</name>
      <anchorfile>structrcppsw_1_1ds_1_1rtree__spec.html</anchorfile>
      <anchor>a62782eab91ea05d56d3e46a3e503ab83</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::pair&lt; geometry_type, value_type &gt;</type>
      <name>element_type</name>
      <anchorfile>structrcppsw_1_1ds_1_1rtree__spec.html</anchorfile>
      <anchor>a1ccf4441fa945f636058717a30aebe55</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TGeometryType</type>
      <name>geometry_type</name>
      <anchorfile>structrcppsw_1_1ds_1_1rtree__spec.html</anchorfile>
      <anchor>aeff32467135c461250aaa77816f81093</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>bgi::rtree&lt; element_type, bgi::rstar&lt; MAXELTS &gt; &gt;</type>
      <name>tree_type</name>
      <anchorfile>structrcppsw_1_1ds_1_1rtree__spec.html</anchorfile>
      <anchor>aa95183b50b44572dd35053980e61d9c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TValueType</type>
      <name>value_type</name>
      <anchorfile>structrcppsw_1_1ds_1_1rtree__spec.html</anchorfile>
      <anchor>ab10ccdaf5115ed1cf50f2be9d4a5391e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr const size_t</type>
      <name>kMAXELTS</name>
      <anchorfile>structrcppsw_1_1ds_1_1rtree__spec.html</anchorfile>
      <anchor>af5fa4c1e311d91ac8b60050dbc7e1769</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::stacked_grid2D</name>
    <filename>classrcppsw_1_1ds_1_1stacked__grid2D.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>rcppsw::ds::grid2D_overlay&lt; value_type&lt; Index &gt; &gt;</type>
      <name>layer_value_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a300c2bf53fc47eb7382483d3a22eb407</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename std::tuple_element&lt; Index, TupleTypes &gt;::type</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>ad9742960b071ab063071b207db5da158</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>stacked_grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a80cc7ebceae23bf8aa0b889a9d3a5994</anchor>
      <arglist>(const math::vector2d &amp;origin, const math::vector2d &amp;dims, const types::discretize_ratio &amp;grid_res, const types::discretize_ratio &amp;field_res)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~stacked_grid2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a2250631b454f0b6744e889d150b098cf</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>layer_value_type&lt; Index &gt;::value_type &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a0dde45b8a31ba7ee6c4cbd55d8bad655</anchor>
      <arglist>(const math::vector2z &amp;d)</arglist>
    </member>
    <member kind="function">
      <type>const layer_value_type&lt; Index &gt;::value_type &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a6d32c11e50ac15865428d4d3921ca8b8</anchor>
      <arglist>(const math::vector2z &amp;d) const</arglist>
    </member>
    <member kind="function">
      <type>layer_value_type&lt; Index &gt;::value_type &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>ac29cc3be297831efe519a6d0a8ea3150</anchor>
      <arglist>(size_t i, size_t j)</arglist>
    </member>
    <member kind="function">
      <type>const layer_value_type&lt; Index &gt;::value_type &amp;</type>
      <name>access</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a792bd9b232b193fc814e1071d15be993</anchor>
      <arglist>(size_t i, size_t j) const</arglist>
    </member>
    <member kind="function">
      <type>rmath::vector2z</type>
      <name>ddims2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a394122d8ca05534138f2a6e6ee855263</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>layer_value_type&lt; Index &gt; *</type>
      <name>layer</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>aa31ce60dc795afe396ff0a7a9b71fc00</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const layer_value_type&lt; Index &gt; *</type>
      <name>layer</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a18ac38ff32f544310a6aa3ecab54de95</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>rmath::vector2d</type>
      <name>rdims2D</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a1a258b5a7a9d8afe9b666792cf964123</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const types::discretize_ratio &amp;</type>
      <name>resolution</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a33e3924c4b93385ce16f202deded4e6e</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>xdsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>ad0f08c39d0a9ed7ebc479b0cca29b71f</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>xrsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>abeda566887c56c64c084a591d2d176bb</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>ydsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>af4fa2b26493ee19729ebf2308640594f</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>yrsize</name>
      <anchorfile>classrcppsw_1_1ds_1_1stacked__grid2D.html</anchorfile>
      <anchor>a2cc384c51758f750f1f0fa53e0105444</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::ds::type_map</name>
    <filename>classrcppsw_1_1ds_1_1type__map.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>std::type_index</type>
      <name>key_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1type__map.html</anchorfile>
      <anchor>a0a3753df88efcab10bcad0fdba1191a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::container::map&lt; key_type, value_type &gt;</type>
      <name>map_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1type__map.html</anchorfile>
      <anchor>add21df97aecb31833dff7e27541e4eb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename boost::make_variant_over&lt; Typelist &gt;::type</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1ds_1_1type__map.html</anchorfile>
      <anchor>aba6e8e094f72dfe7ab2201f2de71751b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::er::client</name>
    <filename>classrcppsw_1_1er_1_1client.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac240653183e3bc50cdd7b94ab573dfdd</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6f82007aff2abc0424c3aea112f4d338</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~client</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a0e6a2aa2f2d0af9352f3ca3044e015d0</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>env_verify</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8dbae2145314c17f94296af27e986ec7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fca204898963d5d8ecb91e00cd84b88</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>log4cxx::LoggerPtr</type>
      <name>logger</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a6b752123f721497e565e028571a1a37b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>logger_name</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab40243dbcdd2e695bace0708788d7ee2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>client &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ac18e66461acd38f97e1cefe7611ca9fb</anchor>
      <arglist>(const client &amp;)=default</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logfile_set</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4fb3fcd567a3f7e65bbf8938ab5e8db7</anchor>
      <arglist>(const log4cxx::LoggerPtr &amp;logger, const std::string &amp;name)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>logging_init</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ae3f3005bc9b32db29bd751bc8511d72a</anchor>
      <arglist>(const std::string &amp;fpath)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_add</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a8e8addf09ab47c9ff19b70ebb72d614a</anchor>
      <arglist>(const std::string &amp;key, const std::string &amp;value)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>mdc_rm</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>ab8d0b0946f73dc6ed3c0f6c6981f7a93</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_pop</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a4b552cb8803ac3cc5c96a6a97deaaec0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>ndc_do_push</name>
      <anchorfile>classrcppsw_1_1er_1_1client.html</anchorfile>
      <anchor>a2b3dbedbca4f96b9e2e2ce91fb3bac3d</anchor>
      <arglist>(const std::string &amp;s)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::er::stringizable</name>
    <filename>classrcppsw_1_1er_1_1stringizable.html</filename>
    <member kind="function">
      <type></type>
      <name>stringizable</name>
      <anchorfile>classrcppsw_1_1er_1_1stringizable.html</anchorfile>
      <anchor>a613eefda69afcc13383029355cb8cfe9</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~stringizable</name>
      <anchorfile>classrcppsw_1_1er_1_1stringizable.html</anchorfile>
      <anchor>ad025418a3c3349948cbea5c6facdb391</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1er_1_1stringizable.html</anchorfile>
      <anchor>a0776b3b6278cc72e8b04448c016bc197</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::binned_powerlaw_distribution</name>
    <filename>classrcppsw_1_1math_1_1binned__powerlaw__distribution.html</filename>
    <base>rcppsw::math::powerlaw_distribution</base>
    <member kind="function">
      <type></type>
      <name>binned_powerlaw_distribution</name>
      <anchorfile>classrcppsw_1_1math_1_1binned__powerlaw__distribution.html</anchorfile>
      <anchor>aca957edf9869bf7fcc02a8d1d33f379c</anchor>
      <arglist>(size_t lb, size_t ub, size_t pwr)</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1math_1_1binned__powerlaw__distribution.html</anchorfile>
      <anchor>a5bc97e3affd7d7f1834540436752729b</anchor>
      <arglist>(rng *const rng)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::bounding_box</name>
    <filename>classrcppsw_1_1math_1_1bounding__box.html</filename>
    <templarg></templarg>
    <base>client&lt; bounding_box&lt; TCoord &gt; &gt;</base>
    <member kind="typedef">
      <type>TCoord</type>
      <name>coord_type</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a6392654bdbc1e9b668e701fb8f57f4d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename coord_type::value_type</type>
      <name>coord_value_type</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>ab1841326fcc193fc2ba0478f30ea1ab4</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a1d1f5f2a56ca309f3d31be7edb199454</anchor>
      <arglist>(bounding_box &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a363fc124849735028666e64e0f869394</anchor>
      <arglist>(const bounding_box &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>aae309dd23eceab4c0928dff3b0a1da54</anchor>
      <arglist>(const coord_type &amp;dims)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>ae7bf81c3f4456af9fa9eded666c29824</anchor>
      <arglist>(const coord_type &amp;dims, const coord_type &amp;anchor)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~bounding_box</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a32dcbbd1f5737eb07bafc85ee5b54a21</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>const coord_type &amp;</type>
      <name>anchor3D</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a437355a5679db1c8da23f33e281c2200</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>coord_type</type>
      <name>center3D</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a0c8d8d5f3aed11d183b07e66c7ac9f9c</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const coord_type &amp;</type>
      <name>dims3D</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>ab033fbae20c7c9957882494694cf3f3a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bounding_box &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a8ed3bb2228d316a2cd1ac9de1b20bb5b</anchor>
      <arglist>(bounding_box &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>bounding_box &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a989c2006933a16e55b2f44d9c6c04136</anchor>
      <arglist>(const bounding_box &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>update</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a5b31f2bdcb8354a75e069a82df903c38</anchor>
      <arglist>(const coord_type &amp;anchor)</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>xsize</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a2aaab567d1ef21d1de924bd9599a9bb0</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>rmath::range&lt; coord_value_type &gt;</type>
      <name>xspan</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a12caea8ed95ed35c9fb288db2380ce3d</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>ysize</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a806b2908f2061fe3328e1f388df8e36c</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>rmath::range&lt; coord_value_type &gt;</type>
      <name>yspan</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>a8653130ec36e1fe92240a8fb6c32258f</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>coord_value_type</type>
      <name>zsize</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>abcbd072fe3a5a3176e31514642509b8c</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>rmath::range&lt; coord_value_type &gt;</type>
      <name>zspan</name>
      <anchorfile>classrcppsw_1_1math_1_1bounding__box.html</anchorfile>
      <anchor>ac0fdd4b8c67d7f8f3016832c057894c3</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::math::config::ema_config</name>
    <filename>structrcppsw_1_1math_1_1config_1_1ema__config.html</filename>
    <base>rcppsw::config::base_config</base>
    <member kind="variable">
      <type>double</type>
      <name>alpha</name>
      <anchorfile>structrcppsw_1_1math_1_1config_1_1ema__config.html</anchorfile>
      <anchor>a681f0ab181e36917103771b9486cbd83</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::math::config::rng_config</name>
    <filename>structrcppsw_1_1math_1_1config_1_1rng__config.html</filename>
    <base>rcppsw::config::base_config</base>
    <member kind="variable">
      <type>int</type>
      <name>seed</name>
      <anchorfile>structrcppsw_1_1math_1_1config_1_1rng__config.html</anchorfile>
      <anchor>a3fb46000d5545f681c661655014d6935</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::math::config::sigmoid_config</name>
    <filename>structrcppsw_1_1math_1_1config_1_1sigmoid__config.html</filename>
    <base>rcppsw::config::base_config</base>
    <member kind="variable">
      <type>double</type>
      <name>gamma</name>
      <anchorfile>structrcppsw_1_1math_1_1config_1_1sigmoid__config.html</anchorfile>
      <anchor>aa3c76b21f8826757342246af07ab50ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>offset</name>
      <anchorfile>structrcppsw_1_1math_1_1config_1_1sigmoid__config.html</anchorfile>
      <anchor>a2dffbddfdf03a0a9ef1ea39a36a88ab0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>reactivity</name>
      <anchorfile>structrcppsw_1_1math_1_1config_1_1sigmoid__config.html</anchorfile>
      <anchor>a01db2614be056a3f6f5cd8cb077b101f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::config::xml::ema_parser</name>
    <filename>classrcppsw_1_1math_1_1config_1_1xml_1_1ema__parser.html</filename>
    <base>client&lt; ema_parser &gt;</base>
    <member kind="typedef">
      <type>ema_config</type>
      <name>config_type</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1ema__parser.html</anchorfile>
      <anchor>ab0c923e1399d64c3602b07f7dbf4cfb1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ema_parser</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1ema__parser.html</anchorfile>
      <anchor>a1f53772e7733b437b2971c0217c70c54</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1ema__parser.html</anchorfile>
      <anchor>a9e0286078849cea2b08d7d9945230b60</anchor>
      <arglist>(const ticpp::Element &amp;node) override</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>validate</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1ema__parser.html</anchorfile>
      <anchor>a4a1fc8576f638446c9f1add05fee7a1c</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>xml_root</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1ema__parser.html</anchorfile>
      <anchor>ad6bc6149f9b01135db053ed9708195d9</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kXMLRoot</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1ema__parser.html</anchorfile>
      <anchor>a3efd9be6039a5e2bb0b321b235862d98</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::config::xml::rng_parser</name>
    <filename>classrcppsw_1_1math_1_1config_1_1xml_1_1rng__parser.html</filename>
    <base>client&lt; rng_parser &gt;</base>
    <member kind="typedef">
      <type>rng_config</type>
      <name>config_type</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1rng__parser.html</anchorfile>
      <anchor>a2bc7e0676a9917f963550e24275b7bfb</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>rng_parser</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1rng__parser.html</anchorfile>
      <anchor>a5055a210b302792e6c08e9766a2f8555</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1rng__parser.html</anchorfile>
      <anchor>abc9c7b5b884bbe43b66fbfb0edc4dc53</anchor>
      <arglist>(const ticpp::Element &amp;node) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>xml_root</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1rng__parser.html</anchorfile>
      <anchor>a0a1ff451f160698aced8e02728a6e072</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kXMLRoot</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1rng__parser.html</anchorfile>
      <anchor>ab3b7344aa3187adf4924b7393057c15c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::config::xml::sigmoid_parser</name>
    <filename>classrcppsw_1_1math_1_1config_1_1xml_1_1sigmoid__parser.html</filename>
    <base>client&lt; sigmoid_parser &gt;</base>
    <member kind="typedef">
      <type>sigmoid_config</type>
      <name>config_type</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1sigmoid__parser.html</anchorfile>
      <anchor>a896e31b55428088548d37e0c4bc633d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>sigmoid_parser</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1sigmoid__parser.html</anchorfile>
      <anchor>aabf82848e7d584e51498e1e83730a909</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1sigmoid__parser.html</anchorfile>
      <anchor>a5f5cafcdf842b18c96748e3dd3403ea9</anchor>
      <arglist>(const ticpp::Element &amp;node) override</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>validate</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1sigmoid__parser.html</anchorfile>
      <anchor>af72a0ba38a70312b2d43b1294a94e2a1</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>xml_root</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1sigmoid__parser.html</anchorfile>
      <anchor>a792b459c2daa6cb3c850bc2c5c295201</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kXMLRoot</name>
      <anchorfile>classrcppsw_1_1math_1_1config_1_1xml_1_1sigmoid__parser.html</anchorfile>
      <anchor>a4dc532075918060e1422d357e34421e2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::degrees</name>
    <filename>classrcppsw_1_1math_1_1degrees.html</filename>
    <base>rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>degrees</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a60c362008cce3980fc310a1f10d1b5d7</anchor>
      <arglist>(const radians &amp;r)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>degrees</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a08f54095cf40db4a5c3c275f86e804d0</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>degrees</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>acce60a481b17de6565aec64f1f875fbb</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>ac2fb6b3897ef09502bc97f14108999d1</anchor>
      <arglist>(const degrees &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>abd3bf729743a8f89a691858d1cb76890</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>degrees</type>
      <name>operator*</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>af9b557e372c9a0bdc73f8fb33093b627</anchor>
      <arglist>(double value) const</arglist>
    </member>
    <member kind="function">
      <type>degrees &amp;</type>
      <name>operator*=</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a796450bda318af72e27fdaebafd315a6</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>degrees</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a289c712fe8f24553652e568912d841af</anchor>
      <arglist>(const degrees &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>degrees &amp;</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a185ee8cb73a871afdc50e928e76d56bb</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>degrees &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>abeb696849d45d8d7e5a75904658e7f2c</anchor>
      <arglist>(const degrees &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>degrees &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a274ab8681ed840b50040bbf29b88793d</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>degrees</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a55a073c04c4006164c444239b02e825b</anchor>
      <arglist>(const degrees &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>degrees</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>af60394475d3ac5dc173fa02ab9c4db2e</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>degrees &amp;</type>
      <name>operator-=</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a04cee97b1ad663da72f5f6302c241556</anchor>
      <arglist>(const degrees &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>degrees &amp;</type>
      <name>operator-=</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>ad941a8d2bd0b9872be101928f10216ac</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>aa811182eb59968a8de270332ca953d49</anchor>
      <arglist>(const degrees &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>degrees</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a5193d9447198871c73e67efa21db6fb2</anchor>
      <arglist>(double value) const</arglist>
    </member>
    <member kind="function">
      <type>degrees &amp;</type>
      <name>operator/=</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>ad0f05ef65d871d8583634b501bea76b5</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>af055f627e914acebd603555e615d15c6</anchor>
      <arglist>(const degrees &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>aa48f4bac046c35413fd5726b926b7a79</anchor>
      <arglist>(const degrees &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a1e38e5948d7a74800accc34ae24ce1fd</anchor>
      <arglist>(const degrees &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a666c8fa5da8019001e015f759ec5121a</anchor>
      <arglist>(const degrees &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>afbfbbbe9eadbfd9596cd1c957d922ee7</anchor>
      <arglist>(const degrees &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a4ed6a0fb16957b97bc4a57b20b72b5e2</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>degrees &amp;</type>
      <name>signed_normalize</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a3752c3a8c6875735822aaa0df8c66ad2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a2b9ac8293d697e031261d104259d501a</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>degrees &amp;</type>
      <name>unsigned_normalize</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a20e8205a28034b1cb6d5b8a771d7b822</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>v</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>a72ea4fc1769badaec4acc5f77817ec0a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const double</type>
      <name>kDEGREES_TO_RADIANS</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>aead0e7367bec51dbfab82500e67e0289</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1degrees.html</anchorfile>
      <anchor>ae05756b80d65072b3d4f8b4b721d47b6</anchor>
      <arglist>(std::istream &amp;is, degrees &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::ema</name>
    <filename>classrcppsw_1_1math_1_1ema.html</filename>
    <templarg></templarg>
    <base>rcppsw::math::expression</base>
    <member kind="function">
      <type></type>
      <name>ema</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>a49b02c1b467c68e2ed2e281bbec6b276</anchor>
      <arglist>(double alpha)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ema</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>a98d4468710952cdf4085c28d60af2f49</anchor>
      <arglist>(double alpha, const T &amp;result)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>alpha</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>ae02e87e7f3970969b2032019b9ea5149</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>ema &amp;</type>
      <name>calc</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>af5a1fab422faa3ef6195ad742af06b6a</anchor>
      <arglist>(const ema &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>calc</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>ae4985609d6aacf4900dda5f41a621923</anchor>
      <arglist>(const T &amp;measure)</arglist>
    </member>
    <member kind="function">
      <type>ema &amp;</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>aec5cda0f81742780f3bfa9c66cc42457</anchor>
      <arglist>(const ema &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>a62733d7d607b997ee9667e4abd7a7080</anchor>
      <arglist>(const T &amp;measure)</arglist>
    </member>
    <member kind="function">
      <type>ema</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>ab2fbe5f636d21064398e4531fc336d94</anchor>
      <arglist>(const ema &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>ema &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>af1442875ff9190623e346b4668cbe251</anchor>
      <arglist>(const ema &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>ema</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>a785bc7890406eb103fde69e849bc0f74</anchor>
      <arglist>(const ema &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>ema</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>aef586dcc33c69c23676f9c84d9f2c3ed</anchor>
      <arglist>(const ema &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1math_1_1ema.html</anchorfile>
      <anchor>a5ad1d4aa2fca8f8510bcd99ac7266223</anchor>
      <arglist>(const ema &amp;other) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::euler_angles</name>
    <filename>classrcppsw_1_1math_1_1euler__angles.html</filename>
    <member kind="function">
      <type></type>
      <name>euler_angles</name>
      <anchorfile>classrcppsw_1_1math_1_1euler__angles.html</anchorfile>
      <anchor>a10f7d9c718c70a73dfe59f06e7d9bf23</anchor>
      <arglist>(const rmath::radians &amp;x, const rmath::radians &amp;y, const rmath::radians &amp;z)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>euler_angles</name>
      <anchorfile>classrcppsw_1_1math_1_1euler__angles.html</anchorfile>
      <anchor>a8d0941eaf9396f1858582213d2e68e5a</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>const rmath::radians &amp;</type>
      <name>x</name>
      <anchorfile>classrcppsw_1_1math_1_1euler__angles.html</anchorfile>
      <anchor>ae38cd63749fb4e5051201c5b081c84e2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const rmath::radians &amp;</type>
      <name>y</name>
      <anchorfile>classrcppsw_1_1math_1_1euler__angles.html</anchorfile>
      <anchor>acc64be83786ecb4854c91c7ba00c100f</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const rmath::radians &amp;</type>
      <name>z</name>
      <anchorfile>classrcppsw_1_1math_1_1euler__angles.html</anchorfile>
      <anchor>af3a2c53222727d94fb5fca51f97e670d</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::expression</name>
    <filename>classrcppsw_1_1math_1_1expression.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>expression</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>aaf5f6c5239b011cc50e0660435796d42</anchor>
      <arglist>(const expression &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>expression</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>ad04caaa756da846454de4eb50a56c440</anchor>
      <arglist>(const T &amp;last)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>expression</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a93c2ef3e3dca75b4d332b3f3dbdeabcf</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~expression</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>af75b4f349110ceaac4efbf36cd278a82</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>eval</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a2ca96a1dc826983e83f6e1e78f9f7d91</anchor>
      <arglist>(const T &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a9cb4fefa68b3548f05417e43eb5277b0</anchor>
      <arglist>(const expression &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>expression &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a485d8341d75d4b27202152a55440508c</anchor>
      <arglist>(const expression &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>afa8fda64acb803192fc82eab2e3ac2c1</anchor>
      <arglist>(const expression &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>ad8efa9b86f5cc28bd10a4b6418830667</anchor>
      <arglist>(const expression &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>aa9e95f4e981ff13149304f3ead544aaa</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>v</name>
      <anchorfile>classrcppsw_1_1math_1_1expression.html</anchorfile>
      <anchor>a80f64efdd897e7287fef8624ef456810</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::ientropy</name>
    <filename>classrcppsw_1_1math_1_1ientropy.html</filename>
    <base>expression&lt; double &gt;</base>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1math_1_1ientropy.html</anchorfile>
      <anchor>ac8234d814950bd53a746377e69a0d619</anchor>
      <arglist>(const std::vector&lt; double &gt; &amp;groups)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::powerlaw_distribution</name>
    <filename>classrcppsw_1_1math_1_1powerlaw__distribution.html</filename>
    <member kind="function">
      <type></type>
      <name>powerlaw_distribution</name>
      <anchorfile>classrcppsw_1_1math_1_1powerlaw__distribution.html</anchorfile>
      <anchor>af1536ee8f046ac025aa7d1cc84780442</anchor>
      <arglist>(size_t lb, size_t ub, size_t pwr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~powerlaw_distribution</name>
      <anchorfile>classrcppsw_1_1math_1_1powerlaw__distribution.html</anchorfile>
      <anchor>af3636b0253fd5ff86178a886b55008fc</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>lb</name>
      <anchorfile>classrcppsw_1_1math_1_1powerlaw__distribution.html</anchorfile>
      <anchor>a6093dce9f467aaf8be5aab56e397b016</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1math_1_1powerlaw__distribution.html</anchorfile>
      <anchor>a4bacb02537c5822d2d0e1d3d73bbc64c</anchor>
      <arglist>(rng *rng)</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>pwr</name>
      <anchorfile>classrcppsw_1_1math_1_1powerlaw__distribution.html</anchorfile>
      <anchor>abd28f840ac9d9c0d6b1d35aa6aec6fc9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>ub</name>
      <anchorfile>classrcppsw_1_1math_1_1powerlaw__distribution.html</anchorfile>
      <anchor>ae5f8beeef09660158fc6134af8cfde1a</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::radians</name>
    <filename>classrcppsw_1_1math_1_1radians.html</filename>
    <base>rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>radians</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>afead1a731b75e57a9df3c0f717ca80d6</anchor>
      <arglist>(const degrees &amp;d)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>radians</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>ad9d93dffcb4c687ebe5328f76a265d33</anchor>
      <arglist>(double value) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>radians</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a448a434f8d6ea017243b942b9e6ed560</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>is_equal</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a49c8c7b9dce20c718226484a51df75a6</anchor>
      <arglist>(const radians &amp;other, double tol=kDOUBLE_EPSILON) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a844bbf089aae0e90e713313810f84634</anchor>
      <arglist>(const radians &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>operator*</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a07a787831d8f6df3b338bb39bfc51bb5</anchor>
      <arglist>(double value) const</arglist>
    </member>
    <member kind="function">
      <type>radians &amp;</type>
      <name>operator*=</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>ab7f255f9f2f543948981fcfc8b88a879</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>aa3d25f59aad5dd28790833bcd70ff2cb</anchor>
      <arglist>(const radians &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>radians &amp;</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>ab5deb8ee70e3dbad7d9f8a95ea6b616f</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>radians &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a8e00936103e3f994ff85f6f1c9367100</anchor>
      <arglist>(const radians &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>acd7ccc932fe9892b54c885c2e8ed655e</anchor>
      <arglist>(const radians &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a955f7010234504e8d4cc4250ac66891a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>radians &amp;</type>
      <name>operator-=</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>ace510f37073f43bb2a70e68fc9e86d8f</anchor>
      <arglist>(const radians &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>aae88f9bed018f1b31ff715dc5d255c9c</anchor>
      <arglist>(const radians &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a6a913c25479cb322b58167796186c6c1</anchor>
      <arglist>(double value) const</arglist>
    </member>
    <member kind="function">
      <type>radians &amp;</type>
      <name>operator/=</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a87662a3844a347ac700f1150e4fcad0b</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a5f448065ee7a68ef839366d98fd4b6e3</anchor>
      <arglist>(const radians &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a4aedb5bf219a5591959111df5c8dca75</anchor>
      <arglist>(const radians &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a008819e5ae6b23c2d3421c8e9483de0a</anchor>
      <arglist>(const radians &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a3848f7ae598cee919f55b06a736346ff</anchor>
      <arglist>(const radians &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a0b68b796c6fdfb92baef31d254b9bf61</anchor>
      <arglist>(const radians &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a8897f1a8a11ffef0319ab97453743775</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>radians &amp;</type>
      <name>signed_normalize</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>adec8fa0947dfb11575045d3acb391b57</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>aefe7c811628dee4db881ce70cead7049</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>radians &amp;</type>
      <name>unsigned_normalize</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>ae47181227d4bcb853008913fe2dbfb8a</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>v</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>ae9552b3ff8dcb07c7401bb22ec0ef682</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const radians</type>
      <name>kPI</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>ac6666621cf37a0312b44a010c62e1c21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const radians</type>
      <name>kPI_OVER_FOUR</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>aa42d44efa418456ab6d1670ed7a57617</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const radians</type>
      <name>kPI_OVER_THREE</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>adcca601e283f51853009eb8708008501</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const radians</type>
      <name>kPI_OVER_TWO</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a71d334b5e3df842691aed60f15e71991</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const double</type>
      <name>kRADIANS_TO_DEGREES</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>aec6d9b1af292a107807a6e67dbb9a6ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const radians</type>
      <name>kTHREE_PI_OVER_TWO</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a745e6ea1aaf1e8d23f30b9ba644955bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const radians</type>
      <name>kTWO_PI</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a4fde1ae3b5fcba300f9996d11cc3bf3a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const radians</type>
      <name>kZERO</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a5dd19637678a4e9f979374b64f912db4</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1radians.html</anchorfile>
      <anchor>a1ad22c437af591159abe07565d7a9f88</anchor>
      <arglist>(std::istream &amp;is, radians &amp;r)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::range</name>
    <filename>classrcppsw_1_1math_1_1range.html</filename>
    <templarg></templarg>
    <base>client&lt; range&lt; T &gt; &gt;</base>
    <base protection="private">rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>range</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a3ab0c3bc0145a373b8402326e48832f4</anchor>
      <arglist>(const T &amp;lb, const T &amp;ub) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>range</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a51646a21baf91b11727e42bae296f1f3</anchor>
      <arglist>(void) noexcept</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>center</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a7fd959194720f7109c79bbe9a3899e18</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a236cd91f4d84f3bf342adc67c50a2879</anchor>
      <arglist>(const range&lt; T &gt; &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a935c2fb3c1f164d146619bfc573d5e6c</anchor>
      <arglist>(const T &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a935c2fb3c1f164d146619bfc573d5e6c</anchor>
      <arglist>(const T &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lb</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>ad7874a03108e2d36070b758e26eed0e3</anchor>
      <arglist>(const T &amp;lb)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>lb</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a98216301a5274242d0807fdb6ef0a9e5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>overlaps_with</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a37e7e41044185c0a22991162843b1797</anchor>
      <arglist>(const range&lt; T &gt; &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>range</type>
      <name>recenter</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a3b2461aa1d5ea6949e1c3f1369f71617</anchor>
      <arglist>(const T &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>af0a4297b73f93d2ec286cf308976a73c</anchor>
      <arglist>(const T &amp;lb, const T &amp;ub)</arglist>
    </member>
    <member kind="function">
      <type>range</type>
      <name>shrink</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a98d5d14dd91aa4e10d26ec82ea1113df</anchor>
      <arglist>(const T &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>span</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a4b26e811d65942ad13b8df83c17a16db</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a0ade48e4a0e80910b805169e2c186bd4</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>range</type>
      <name>translate</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a0d9bc5b47f120de08c42a5a00a4b0563</anchor>
      <arglist>(const T &amp;value) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ub</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a0213db565ba4678555abe0f8ef66bc85</anchor>
      <arglist>(const T &amp;ub)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>ub</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>af8213dcf44eddc9ebec8803d87db67fa</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>wrap_value</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a564e5d1adac98d5e1ff4e6d0542b3ae7</anchor>
      <arglist>(T value) const</arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a4659bf314aa29a0ca9b3847e68e819bd</anchor>
      <arglist>(std::ostream &amp;stream, const range &amp;c_range)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1range.html</anchorfile>
      <anchor>a5d38c5c46b1f429c37395c60ba4474ad</anchor>
      <arglist>(std::istream &amp;is, range &amp;r)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::rngm</name>
    <filename>classrcppsw_1_1math_1_1rngm.html</filename>
    <base>caching_factory&lt; rng, uint &gt;</base>
    <base>singleton&lt; rngm &gt;</base>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::sigmoid</name>
    <filename>classrcppsw_1_1math_1_1sigmoid.html</filename>
    <base>expression&lt; double &gt;</base>
    <member kind="function">
      <type></type>
      <name>sigmoid</name>
      <anchorfile>classrcppsw_1_1math_1_1sigmoid.html</anchorfile>
      <anchor>a02040f1094116d33a077abb3558fed91</anchor>
      <arglist>(const config::sigmoid_config *const config)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>sigmoid</name>
      <anchorfile>classrcppsw_1_1math_1_1sigmoid.html</anchorfile>
      <anchor>a714164a89762f4cd66d6b360fad3f54d</anchor>
      <arglist>(double reactivity, double offset, double gamma)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>sigmoid</name>
      <anchorfile>classrcppsw_1_1math_1_1sigmoid.html</anchorfile>
      <anchor>ac730323cab6d88df5a89cd6f1d3aa7fc</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchorfile>classrcppsw_1_1math_1_1sigmoid.html</anchorfile>
      <anchor>a7b8f300631bfdab0293a6fd3f76b6b39</anchor>
      <arglist>(double reactivity, double offset, double gamma)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>double</type>
      <name>gamma</name>
      <anchorfile>classrcppsw_1_1math_1_1sigmoid.html</anchorfile>
      <anchor>a3fa81eb07154adda31c801310526c7f6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>double</type>
      <name>offset</name>
      <anchorfile>classrcppsw_1_1math_1_1sigmoid.html</anchorfile>
      <anchor>aa8d1dd1c69577d5f3c617d7f2efd9835</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>double</type>
      <name>reactivity</name>
      <anchorfile>classrcppsw_1_1math_1_1sigmoid.html</anchorfile>
      <anchor>a16796586e0f2566e10f597f73fc289d2</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::sphere_vector</name>
    <filename>classrcppsw_1_1math_1_1sphere__vector.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>sphere_vector</name>
      <anchorfile>classrcppsw_1_1math_1_1sphere__vector.html</anchorfile>
      <anchor>a2a4f23e8ec57af6e672c9587d8c57be5</anchor>
      <arglist>(const T &amp;radius, const rmath::radians &amp;zenith, const rmath::radians &amp;azimuth)</arglist>
    </member>
    <member kind="function">
      <type>const rmath::radians &amp;</type>
      <name>azimuth</name>
      <anchorfile>classrcppsw_1_1math_1_1sphere__vector.html</anchorfile>
      <anchor>a747fdf0ba928e6e52ea762e4a5a8d52d</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>radius</name>
      <anchorfile>classrcppsw_1_1math_1_1sphere__vector.html</anchorfile>
      <anchor>ae4de7c5d190156ebf49075c769c49ed1</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const rmath::radians &amp;</type>
      <name>zenith</name>
      <anchorfile>classrcppsw_1_1math_1_1sphere__vector.html</anchorfile>
      <anchor>a19cdabe5d5b88e37cb3569f7720a17c4</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::vector2</name>
    <filename>classrcppsw_1_1math_1_1vector2.html</filename>
    <templarg></templarg>
    <base>rcppsw::er::stringizable</base>
    <class kind="struct">rcppsw::math::vector2::componentwise_compare</class>
    <class kind="struct">rcppsw::math::vector2::key_compare</class>
    <member kind="typedef">
      <type>T</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a7e5b525e0b7e431d64af94215883b759</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>vector2</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a0ba40675c3c7ca4923551bb43a406115</anchor>
      <arglist>(const T &amp;length, const radians &amp;angle) noexcept</arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>vector2</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a42c0f68cb1440f07bd6656ec5fcf4722</anchor>
      <arglist>(const T &amp;x, const T &amp;y) noexcept</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>vector2</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>add2bdb95ae0c25a39877f085d9994972</anchor>
      <arglist>(void) noexcept=default</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>angle</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a7c53548293281c0fca4ecbbde70ce066</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>is_pd</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>ad6ce28e3ad3a1e84d2838269ce9051b8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>is_psd</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a3c1e03281f29d933bd4d846a8dc56b7a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>length</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>ae38aa00899e5813531de630c321d0696</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>vector2 &amp;</type>
      <name>normalize</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>ad0c6da565111c56585a8a36fb48ce321</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>aece5bee19d9750547d2aa7c910461949</anchor>
      <arglist>(const vector2 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>vector2</type>
      <name>operator*</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a09dc555a2cebcd5d54c95624c572c58d</anchor>
      <arglist>(T val) const</arglist>
    </member>
    <member kind="function">
      <type>vector2 &amp;</type>
      <name>operator*=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a9837f0b42cd764b9bbea27427666a4f7</anchor>
      <arglist>(T val)</arglist>
    </member>
    <member kind="function">
      <type>vector2</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a655d7521092e47fd6e8a6d58dda26b6d</anchor>
      <arglist>(const vector2 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>vector2 &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>ab7e8a33e958bea218a71dd4723ba25ce</anchor>
      <arglist>(const vector2 &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>vector2&lt; T &gt;</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>af22a050079f8f9a719420c1d4abdd90a</anchor>
      <arglist>(const vector2 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>vector2</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a8a5d8e95fa268af6f73edbe42e32ce22</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>vector2 &amp;</type>
      <name>operator-=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a1f58836d47916598211295947745aec0</anchor>
      <arglist>(const vector2 &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>vector2</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a079a41ccc0bc9fe6e64c1d6e3a522399</anchor>
      <arglist>(T val) const</arglist>
    </member>
    <member kind="function">
      <type>vector2 &amp;</type>
      <name>operator/=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a73487d60a055da721bfc0a4e9ad55641</anchor>
      <arglist>(T val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>adf05073902c035328fa17711b777aecc</anchor>
      <arglist>(const vector2 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>aec7108fb58050b2133ea1f16ec9326b7</anchor>
      <arglist>(const vector2 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a19bf17e72c5665104d97ec590025cbc9</anchor>
      <arglist>(const vector2 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a19bf17e72c5665104d97ec590025cbc9</anchor>
      <arglist>(const vector2 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a07b4f802e8d0db5d970ff2429688d544</anchor>
      <arglist>(const vector2 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a438863900d3eb7c5a3e92a27a648aef3</anchor>
      <arglist>(const vector2 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>vector2 &amp;</type>
      <name>rotate</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a6d8f8da9866d4c88997ef4070c990a43</anchor>
      <arglist>(const radians &amp;angle)</arglist>
    </member>
    <member kind="function">
      <type>vector2 &amp;</type>
      <name>scale</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a6943b6641c2c09f2360ddc1deb2bd79d</anchor>
      <arglist>(const T &amp;factor)</arglist>
    </member>
    <member kind="function">
      <type>vector2 &amp;</type>
      <name>scale</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>acd1742b5f06be9d11b3a5b8729f3586c</anchor>
      <arglist>(const T &amp;scale_x, const T &amp;scale_y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a64d5d47b4abcafa40e7737479caf9158</anchor>
      <arglist>(const T &amp;x, const T &amp;y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_from_polar</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>aee877a4058765564791575ab19f2f0f5</anchor>
      <arglist>(const T &amp;length, const radians &amp;angle)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>square_length</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>aeb0949a504e124a29709581cbad2d1f1</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a234346d2bf083d6effbbc67b21369fe2</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>x</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a1d1f2363b4f183c0b99d6323e78a24b7</anchor>
      <arglist>(const T &amp;x)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>x</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>af6b34be0d7fab15a93723bf246171910</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>x</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>ab49ec569e91bc163cca609c9b9a4e602</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>y</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a74c2211bc5de734d0bcef2b7fd39918c</anchor>
      <arglist>(const T &amp;y)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>y</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>aea0d9eeaaf6e39905818271cf972cc36</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>y</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>ac7d27917987f863002d6a740c5741c0f</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static size_t</type>
      <name>l1norm</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>ae022f14d7122d578f70a19a15dbe4505</anchor>
      <arglist>(const vector2&lt; U &gt; &amp;v1, const vector2&lt; V &gt; &amp;v2)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr size_t</type>
      <name>kDIMENSIONALITY</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a7ab00ac0a0ffd09f359be6eb1ac94d04</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const vector2&lt; T &gt;</type>
      <name>X</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a86bb9438e66f82a931041dbaad4fe167</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const vector2&lt; T &gt;</type>
      <name>Y</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a0216944863c26963c16d2f0d5472515f</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>a5316cad4bb288e7d083ce3126c9657c2</anchor>
      <arglist>(std::ostream &amp;stream, const vector2 &amp;v)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1vector2.html</anchorfile>
      <anchor>aba90eb5fb6550060c108da4008962358</anchor>
      <arglist>(std::istream &amp;is, vector2&lt; T &gt; &amp;v)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::math::vector2::componentwise_compare</name>
    <filename>structrcppsw_1_1math_1_1vector2_1_1componentwise__compare.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1math_1_1vector2_1_1componentwise__compare.html</anchorfile>
      <anchor>ace479ac4b6cffc43131b9851baead20f</anchor>
      <arglist>(const vector2&lt; T &gt; &amp;lhs, const vector2&lt; T &gt; &amp;rhs) const</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::math::vector2::key_compare</name>
    <filename>structrcppsw_1_1math_1_1vector2_1_1key__compare.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1math_1_1vector2_1_1key__compare.html</anchorfile>
      <anchor>a25daf3d229e29e5b75fc074bf135977b</anchor>
      <arglist>(const vector2&lt; U &gt; &amp;lhs, const vector2&lt; U &gt; &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1math_1_1vector2_1_1key__compare.html</anchorfile>
      <anchor>a25daf3d229e29e5b75fc074bf135977b</anchor>
      <arglist>(const vector2&lt; U &gt; &amp;lhs, const vector2&lt; U &gt; &amp;rhs) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::math::vector3</name>
    <filename>classrcppsw_1_1math_1_1vector3.html</filename>
    <templarg></templarg>
    <base>rcppsw::er::stringizable</base>
    <class kind="struct">rcppsw::math::vector3::componentwise_compare</class>
    <class kind="struct">rcppsw::math::vector3::key_compare</class>
    <member kind="typedef">
      <type>T</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a739ce11cfdb230ad302f9bc8d015ea59</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>constexpr</type>
      <name>vector3</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a6cf8b83fe9b381b6dba5f127238a0854</anchor>
      <arglist>(const T &amp;x, const T &amp;y, const T &amp;z)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>vector3</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a708562e6ace86390ab4ccf98a1f9c992</anchor>
      <arglist>(const vector2&lt; T &gt; &amp;v)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>vector3</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a6b571ba519a42a0a2a01371e0e0d13b9</anchor>
      <arglist>(const vector2&lt; T &gt; &amp;v, const T &amp;z)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>vector3</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>ad289346fb20b1556ce77bb4abff45f94</anchor>
      <arglist>(void) noexcept=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>is_pd</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a7a57d77550cf228cc68c2b3b4caf2598</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>is_psd</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a226263beff3f224787bb66a2a4a4ae49</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>length</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a30553f030523ffea82ee4572c3ba2990</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>vector3</type>
      <name>mask</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>adf8370d65a8d6bfe42d5c1d3a743d20b</anchor>
      <arglist>(const vector3 &amp;the_mask) const</arglist>
    </member>
    <member kind="function">
      <type>vector3 &amp;</type>
      <name>normalize</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>ae41ac681f082dd801b6ad9d1db95f8af</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a03cd69520169ee49edc9d3e585529262</anchor>
      <arglist>(const vector3 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>vector3</type>
      <name>operator*</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a66afcd7b1135737a499f5e77aa817153</anchor>
      <arglist>(const T &amp;val) const</arglist>
    </member>
    <member kind="function">
      <type>vector3 &amp;</type>
      <name>operator*=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a953c4eb0133320addd861608161bf190</anchor>
      <arglist>(const T &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>vector3</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a72322a01ac4b0f852c1b9ec6f5153a5c</anchor>
      <arglist>(const vector3 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>vector3 &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a8be1ab84c0fc3ac51355b7347ff18e1a</anchor>
      <arglist>(const vector3 &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>vector3&lt; T &gt;</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>adef32e4a5953b5da3f27d46200dae1ca</anchor>
      <arglist>(const vector3 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>vector3</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a8311b043688e8046ba24a89ac6455278</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>vector3 &amp;</type>
      <name>operator-=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a9f1949fc3bf3925d01ecd47cd5c5705c</anchor>
      <arglist>(const vector3 &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>vector3</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>ada42e246e5ff48f8b34a28706cba0fdc</anchor>
      <arglist>(const T &amp;val) const</arglist>
    </member>
    <member kind="function">
      <type>vector3 &amp;</type>
      <name>operator/=</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a9a0d83dc5e6d9e346687c8e509369f92</anchor>
      <arglist>(const T &amp;val)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a2d40303f578168224e057f0b406388c9</anchor>
      <arglist>(const vector3 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a2d40303f578168224e057f0b406388c9</anchor>
      <arglist>(const vector3 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a2c051ae63c3855eee41cf12ff81096cd</anchor>
      <arglist>(const vector3 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a2c051ae63c3855eee41cf12ff81096cd</anchor>
      <arglist>(const vector3 &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>vector2&lt; T &gt;</type>
      <name>project_on_xy</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>abc15df272ca5f34fb6e0125b6e5496bc</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>vector2&lt; T &gt;</type>
      <name>project_on_xz</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a0a2270f74ac620c48125a88a2706d2ee</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>vector2&lt; T &gt;</type>
      <name>project_on_yz</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a7f5062a957b84c4714c5f59bfaefb3bc</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>vector3 &amp;</type>
      <name>scale</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a760dbe17d724e05562c7635ff247c332</anchor>
      <arglist>(const T &amp;factor)</arglist>
    </member>
    <member kind="function">
      <type>vector3 &amp;</type>
      <name>scale</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>ac027990eb820257587b44a13e315f1c5</anchor>
      <arglist>(const T &amp;scale_x, const T &amp;scale_y, const T &amp;scale_z)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>ae5d6e4c3ec99f5f4c3983de6b43f1ee1</anchor>
      <arglist>(const T &amp;x, const T &amp;y, const T &amp;z)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>square_length</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>adebe9e210da98636efede25cc1e88b8e</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>vector2&lt; T &gt;</type>
      <name>to_2D</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a8260ef63ae96ce2c8b1ab96e9d438b58</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>sphere_vector&lt; T &gt;</type>
      <name>to_spherical</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a0b454e398870a844c776cf4f144ef951</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>af3f46555472226e6249d1d0a4c73c749</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>x</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a1a4e7832538fbc198c08ed30e5cdbbd4</anchor>
      <arglist>(const T &amp;x)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>x</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>af99af271d2aed6d806dccf2b9966ddfd</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>x</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>aee373928453e09ce4e1a1631fe25e2f9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>xangle</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a90a7caf85fe7c470c148885a93b9fa26</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>y</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>ad9f4def6cf134f23a899f1f77ad9fae9</anchor>
      <arglist>(const T &amp;y)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>y</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>ab28e8dab3f10afa3a18eb125cfe7e56c</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>y</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a291c8f4ebbac2a3fb1fee59ee28ed6c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>yangle</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a80b4a4ff1e4f76a467ae560ecaa78c5a</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>z</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>aeeb435e7f32406e79f582dd79296aa76</anchor>
      <arglist>(const T &amp;z)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>z</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>ad9ca2096fd3b063623246722dd0cf68b</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>z</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>ae1e7015cf7b040f4e1b0aacd794b2b91</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>zangle</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a83934a52c83d0b25b37094b7b5884de5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr size_t</type>
      <name>kDIMENSIONALITY</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a93980b91c27120cfe690a6996116f287</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const vector3&lt; T &gt;</type>
      <name>X</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a55bb07c75717b618ba64df1ad8bd2ed7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const vector3&lt; T &gt;</type>
      <name>Y</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a0c41e403a6df01fcf37b0a578ca62ebc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const vector3&lt; T &gt;</type>
      <name>Z</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a8a95bc145378e7ed938f639342e61c6c</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a1863fd7f5a2da8679ca0bc725f1f00bb</anchor>
      <arglist>(std::ostream &amp;stream, const vector3 &amp;v)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1math_1_1vector3.html</anchorfile>
      <anchor>a9c58ecd78127822b1012ec5675efbb74</anchor>
      <arglist>(std::istream &amp;is, vector3&lt; T &gt; &amp;v)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::math::vector3::componentwise_compare</name>
    <filename>structrcppsw_1_1math_1_1vector3_1_1componentwise__compare.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1math_1_1vector3_1_1componentwise__compare.html</anchorfile>
      <anchor>adfb638d58b92fce26cb61758689d5fcf</anchor>
      <arglist>(const vector3&lt; U &gt; &amp;lhs, const vector3&lt; U &gt; &amp;rhs) const</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::math::vector3::key_compare</name>
    <filename>structrcppsw_1_1math_1_1vector3_1_1key__compare.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1math_1_1vector3_1_1key__compare.html</anchorfile>
      <anchor>a7f01eb24b7cd100dc7cd98eb3cc6d4e0</anchor>
      <arglist>(const vector3&lt; U &gt; &amp;lhs, const vector3&lt; U &gt; &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1math_1_1vector3_1_1key__compare.html</anchorfile>
      <anchor>a7f01eb24b7cd100dc7cd98eb3cc6d4e0</anchor>
      <arglist>(const vector3&lt; U &gt; &amp;lhs, const vector3&lt; U &gt; &amp;rhs) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::base_collector</name>
    <filename>classrcppsw_1_1metrics_1_1base__collector.html</filename>
    <base>client&lt; base_collector &gt;</base>
    <member kind="function">
      <type></type>
      <name>base_collector</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>a3e5df8d514725acf00cd8917bdfc0c95</anchor>
      <arglist>(std::unique_ptr&lt; base_sink &gt; sink)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_collector</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>a4d0ba973e177e1a003a39b5652e2db9c</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>collect</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>a2ea13b8891f64d4f9c508e01aa1fb84d</anchor>
      <arglist>(const rcppsw::metrics::base_metrics &amp;metrics)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const rmetrics::base_data *</type>
      <name>data</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>a65ee808c4f9ce878a1cc172dfc2473d6</anchor>
      <arglist>(void) const =0</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>finalize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>a65d77f74eb89ae2648fc03a5e3208d71</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>write_status</type>
      <name>flush</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>ac802aa3e05bed414bb1a0c741c1f9310</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>a0e211e635c7452e3cb000518f1735c3f</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>interval_reset</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>a357c5d4d01dedf0ca5a0298066cc8fb8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>types::timestep</type>
      <name>timestep</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>abd4351fa4f7d837c4f68bfb8a0cf230d</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>timestep_inc</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>a47c206d306e62b30110281108e19e58a</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>reset_after_interval</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__collector.html</anchorfile>
      <anchor>afcdf89f71d05cc03018ea2b19a0c1510</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>rcppsw::metrics::base_data</name>
    <filename>structrcppsw_1_1metrics_1_1base__data.html</filename>
    <member kind="function">
      <type></type>
      <name>base_data</name>
      <anchorfile>structrcppsw_1_1metrics_1_1base__data.html</anchorfile>
      <anchor>ace48ba7589a9d7bddfea013e981b9ea2</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_data</name>
      <anchorfile>structrcppsw_1_1metrics_1_1base__data.html</anchorfile>
      <anchor>a18701c89bbbcdd6fe05d7d3a52c53c1e</anchor>
      <arglist>(void)=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::base_manager</name>
    <filename>classrcppsw_1_1metrics_1_1base__manager.html</filename>
    <member kind="function">
      <type></type>
      <name>base_manager</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>a8bbb1e653e3eeda4c7e6f229fd289763</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_manager</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>af1eed86e00ad1557925cc07f33d86e97</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>collect</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>a0c8cb07c3e3aaac94854c345a74597ff</anchor>
      <arglist>(const std::string &amp;scoped_name, const T &amp;collectee)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>collect_if</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>a9ada1fd8998e902a52e67c4b8eb30476</anchor>
      <arglist>(const std::string &amp;scoped_name, const T &amp;collectee, const std::function&lt; bool(const rmetrics::base_metrics &amp;)&gt; &amp;pred)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>collector_preregister</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>ac400893189c8599c6b362433b5fdec11</anchor>
      <arglist>(const std::string &amp;scoped_name, const rmetrics::output_mode &amp;mode)=0</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>collector_register</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>ab4c78173cfdbd539b96e319b5a6b8f26</anchor>
      <arglist>(const std::string &amp;scoped_name, Args &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>collector_unregister</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>a803b2fd9fe0072dc8bd4438c005d257b</anchor>
      <arglist>(const std::string &amp;scoped_name)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>finalize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>a0fe2f062a289ae6064aeb539fcb123ba</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>flush</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>a885a1c83f6b6cd6c4bd758144672354e</anchor>
      <arglist>(const rmetrics::output_mode &amp;mode)=0</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>get</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>a759f30a9314723cc72b1e96242c4666f</anchor>
      <arglist>(const std::string &amp;key)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>aee2d6c7bcba2625b53a0341a6c17cf4f</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>interval_reset</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>ac393bd539adbd14781d44d1fc18c6303</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>timestep_inc</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>ab8d4923c9f9a641d76c72c424ff0943e</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="typedef" protection="protected">
      <type>std::map&lt; std::string, rmetrics::collector_group * &gt;</type>
      <name>collector_map_type</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>ab4b144bce60014574080956e061e2f78</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>collector_map_type *</type>
      <name>collector_map</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__manager.html</anchorfile>
      <anchor>a76debcfab748d9e56fc6c46f03a95cc7</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>rcppsw::metrics::base_metrics</name>
    <filename>classrcppsw_1_1metrics_1_1base__metrics.html</filename>
    <member kind="function">
      <type></type>
      <name>base_metrics</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__metrics.html</anchorfile>
      <anchor>ad207239f697c6f12f05e78770c9b1a15</anchor>
      <arglist>(const base_metrics &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_metrics</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__metrics.html</anchorfile>
      <anchor>ad5df2f2d1e3e443ca5ba3373d605f0c8</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_metrics</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__metrics.html</anchorfile>
      <anchor>a77ae43c4c0a08b4b48e70ae0b16994eb</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>base_metrics &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__metrics.html</anchorfile>
      <anchor>ab597778da5489e749d297fa924ebba08</anchor>
      <arglist>(const base_metrics &amp;)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>reset_metrics</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__metrics.html</anchorfile>
      <anchor>ae1b5be3e6687a19ba27d7eefe9c22680</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::base_sink</name>
    <filename>classrcppsw_1_1metrics_1_1base__sink.html</filename>
    <base>client&lt; base_sink &gt;</base>
    <member kind="function">
      <type></type>
      <name>base_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__sink.html</anchorfile>
      <anchor>a30d0e24af23d9d416bbe2541752b53d3</anchor>
      <arglist>(const rmetrics::output_mode &amp;mode, const rtypes::timestep &amp;interval)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__sink.html</anchorfile>
      <anchor>ae644dfd6d29ce48030897690de5dff19</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>finalize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__sink.html</anchorfile>
      <anchor>a0ad1688ea1c8a323d6f6435280274a4d</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual write_status</type>
      <name>flush</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__sink.html</anchorfile>
      <anchor>a6c44de6709e712b9c5e54cb96a12764c</anchor>
      <arglist>(const rmetrics::base_data *data, const rtypes::timestep &amp;t)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__sink.html</anchorfile>
      <anchor>ad360db7add933a07e862ebee79a9b4a1</anchor>
      <arglist>(const rmetrics::base_data *data)=0</arglist>
    </member>
    <member kind="function">
      <type>const rtypes::timestep &amp;</type>
      <name>output_interval</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__sink.html</anchorfile>
      <anchor>a33bce9116b8249d17c2c5ed7088aa6ff</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const rmetrics::output_mode &amp;</type>
      <name>output_mode</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__sink.html</anchorfile>
      <anchor>a8ee14d13a97dfaf7166e6dccfdbb96ba</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>ready_to_flush</name>
      <anchorfile>classrcppsw_1_1metrics_1_1base__sink.html</anchorfile>
      <anchor>ae6c46d822bd9c6384bc46e8bb1c5f1ee</anchor>
      <arglist>(const rtypes::timestep &amp;t) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::collector_group</name>
    <filename>classrcppsw_1_1metrics_1_1collector__group.html</filename>
    <member kind="typedef">
      <type>std::string</type>
      <name>key_type</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>ace196cc8b4dba7196e0019f45fd217d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::unique_ptr&lt; base_collector &gt;</type>
      <name>mapped_type</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>a3e516d5b4e103704b564d0fc1bdf1d79</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>collector_group</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>a02a4359dd2cd6701774c4359d093c89d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~collector_group</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>adc945b32925db0c5f558d7c9b71113e6</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>collect</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>a2c84a509242e695ece1a1bdb8913fb7b</anchor>
      <arglist>(const key_type &amp;name, const base_metrics &amp;metrics)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>collect</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>a1d81c739802b925ddc9616f5d602d107</anchor>
      <arglist>(const key_type &amp;name, const TNetworkHandle &amp;handle)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>collect_if</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>ad9f9e75d10a93f49ce6eb92f286d9773</anchor>
      <arglist>(const key_type &amp;name, const base_metrics &amp;metrics, const std::function&lt; bool(const base_metrics &amp;)&gt; &amp;predicate)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>collector_register</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>ad30b871dbfac96f7384c17b870b00a36</anchor>
      <arglist>(const key_type &amp;name, Args &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>collector_unregister</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>aed16d0548444b278056354ed89fd0204</anchor>
      <arglist>(const key_type &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>finalize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>aca92644952284f9eb41f5879ff61543a</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>flush</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>a6eb030086e19dee9e9f7ef063a22f0cb</anchor>
      <arglist>(bool fail_ok)</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>get</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>a54fd312a23df2644d385be0d4f04411f</anchor>
      <arglist>(const key_type &amp;key)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>ab5a0b85257c72d34ef06260a66a1b5a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>interval_reset</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>a158e9534e8654ea1d4cea07d9d819572</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>timestep_inc</name>
      <anchorfile>classrcppsw_1_1metrics_1_1collector__group.html</anchorfile>
      <anchor>a23ddbcd59ffecbb724ef65e52216463e</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::metrics::collector_registration_spec</name>
    <filename>namespacercppsw_1_1metrics.html</filename>
    <anchor>structrcppsw_1_1metrics_1_1collector__registration__spec</anchor>
    <templarg></templarg>
    <member kind="variable">
      <type>bool</type>
      <name>is_enabled</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a2426c1971ac8d5e5b4559c5404ec2dd6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::unique_ptr&lt; TSink &gt;</type>
      <name>sink</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a395ebc5719baefeb343dd27387d66e9e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::metrics::config::file_sink_config</name>
    <filename>structrcppsw_1_1metrics_1_1config_1_1file__sink__config.html</filename>
    <base>rcppsw::config::base_config</base>
    <member kind="variable">
      <type>rmetrics::config::output_mode_config</type>
      <name>append</name>
      <anchorfile>structrcppsw_1_1metrics_1_1config_1_1file__sink__config.html</anchorfile>
      <anchor>a77129cc9c5c3c49a53b9a03fd7dd2273</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>rmetrics::config::output_mode_config</type>
      <name>create</name>
      <anchorfile>structrcppsw_1_1metrics_1_1config_1_1file__sink__config.html</anchorfile>
      <anchor>adac5cd2d02c30e619beb7e0258f01394</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>rmetrics::config::output_mode_config</type>
      <name>truncate</name>
      <anchorfile>structrcppsw_1_1metrics_1_1config_1_1file__sink__config.html</anchorfile>
      <anchor>a49e1cf5f1aeb9cd28edc7059e441c401</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::metrics::config::metrics_config</name>
    <filename>structrcppsw_1_1metrics_1_1config_1_1metrics__config.html</filename>
    <base>rcppsw::config::base_config</base>
    <member kind="variable">
      <type>rmconfig::file_sink_config</type>
      <name>csv</name>
      <anchorfile>structrcppsw_1_1metrics_1_1config_1_1metrics__config.html</anchorfile>
      <anchor>a66016b842e5447753846a6907340d3ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>fs::path</type>
      <name>metrics_path</name>
      <anchorfile>structrcppsw_1_1metrics_1_1config_1_1metrics__config.html</anchorfile>
      <anchor>a03a4d5ce60dfccffcecace24f987747d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>rmconfig::network_sink_config</type>
      <name>network</name>
      <anchorfile>structrcppsw_1_1metrics_1_1config_1_1metrics__config.html</anchorfile>
      <anchor>aa02faf2d4edd8151dc6faf2990fc2913</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::metrics::config::network_sink_config</name>
    <filename>structrcppsw_1_1metrics_1_1config_1_1network__sink__config.html</filename>
    <base>rcppsw::config::base_config</base>
    <member kind="variable">
      <type>rmetrics::config::output_mode_config</type>
      <name>stream</name>
      <anchorfile>structrcppsw_1_1metrics_1_1config_1_1network__sink__config.html</anchorfile>
      <anchor>abf014c41d350763c4d5c4f450535e8af</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::metrics::config::output_mode_config</name>
    <filename>namespacercppsw_1_1metrics_1_1config.html</filename>
    <anchor>structrcppsw_1_1metrics_1_1config_1_1output__mode__config</anchor>
    <member kind="typedef">
      <type>std::map&lt; std::string, std::string &gt;</type>
      <name>enabled_map_type</name>
      <anchorfile>namespacercppsw_1_1metrics_1_1config.html</anchorfile>
      <anchor>a6a47448a338cb200de291ee59a20223a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>enabled_map_type</type>
      <name>enabled</name>
      <anchorfile>namespacercppsw_1_1metrics_1_1config.html</anchorfile>
      <anchor>aa41ae2eb0f29d5073cb2f413a329103d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>rtypes::timestep</type>
      <name>output_interval</name>
      <anchorfile>namespacercppsw_1_1metrics_1_1config.html</anchorfile>
      <anchor>abcf55d00ff374cf307df926460f31190</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::config::xml::base_sink_parser</name>
    <filename>classrcppsw_1_1metrics_1_1config_1_1xml_1_1base__sink__parser.html</filename>
    <base>client&lt; base_sink_parser &gt;</base>
    <member kind="function">
      <type></type>
      <name>base_sink_parser</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1base__sink__parser.html</anchorfile>
      <anchor>a67d784a1e3335c92312f54c033dbb37e</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~base_sink_parser</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1base__sink__parser.html</anchorfile>
      <anchor>a9f0a64db6a8940284dc1c26288f7eaf7</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>is_collector_name</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1base__sink__parser.html</anchorfile>
      <anchor>a89fb56f4d736196973ea1e8a19712dfb</anchor>
      <arglist>(const ticpp::Attribute &amp;attr) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>output_mode_parse</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1base__sink__parser.html</anchorfile>
      <anchor>a7505fcecb2d6eed30277eb9d2603e321</anchor>
      <arglist>(const ticpp::Element &amp;element, rmetrics::config::output_mode_config *config)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::config::xml::file_sink_parser</name>
    <filename>classrcppsw_1_1metrics_1_1config_1_1xml_1_1file__sink__parser.html</filename>
    <base>client&lt; file_sink_parser &gt;</base>
    <member kind="typedef">
      <type>file_sink_config</type>
      <name>config_type</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1file__sink__parser.html</anchorfile>
      <anchor>a820ee9512ccfe5ad63efa6091a9c3c6d</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>file_sink_parser</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1file__sink__parser.html</anchorfile>
      <anchor>a78f9425da7dc1e2d64c6abfb140e9841</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~file_sink_parser</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1file__sink__parser.html</anchorfile>
      <anchor>a0c95246765647f7d338a201ee3884e92</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1file__sink__parser.html</anchorfile>
      <anchor>a8175c977c7363766f325ddf2f08b00db</anchor>
      <arglist>(const ticpp::Element &amp;node) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>xml_root</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1file__sink__parser.html</anchorfile>
      <anchor>a1086ac8aa85266727196e9a6e753d405</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kXMLRoot</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1file__sink__parser.html</anchorfile>
      <anchor>a18a61416e6e5eafcbc56d1d88789f59e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::config::xml::metrics_parser</name>
    <filename>classrcppsw_1_1metrics_1_1config_1_1xml_1_1metrics__parser.html</filename>
    <base>client&lt; metrics_parser &gt;</base>
    <member kind="typedef">
      <type>metrics_config</type>
      <name>config_type</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1metrics__parser.html</anchorfile>
      <anchor>a748c2dfe256b74215badbaf3a5924669</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>metrics_parser</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1metrics__parser.html</anchorfile>
      <anchor>ae162302ec835967d6f76aeda28abaed7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~metrics_parser</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1metrics__parser.html</anchorfile>
      <anchor>a6d25cab731ec5bfa7aca39794c27dda5</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1metrics__parser.html</anchorfile>
      <anchor>a273b99fdc31f9ac26ba245c89c16054c</anchor>
      <arglist>(const ticpp::Element &amp;node) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>xml_root</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1metrics__parser.html</anchorfile>
      <anchor>a6be7cbebcfd3ccbe042e339db124cc77</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kXMLRoot</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1metrics__parser.html</anchorfile>
      <anchor>a589cbb6232037397593bd31a7058a435</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::config::xml::network_sink_parser</name>
    <filename>classrcppsw_1_1metrics_1_1config_1_1xml_1_1network__sink__parser.html</filename>
    <base>client&lt; network_sink_parser &gt;</base>
    <member kind="typedef">
      <type>network_sink_config</type>
      <name>config_type</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1network__sink__parser.html</anchorfile>
      <anchor>a516a4aef9fa4891a1ea07eeeb08a28ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>network_sink_parser</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1network__sink__parser.html</anchorfile>
      <anchor>a4fc52df764201bbafe9096b477974f04</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~network_sink_parser</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1network__sink__parser.html</anchorfile>
      <anchor>af25a5be18774d177b5cb2ebbb74d8ea3</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1network__sink__parser.html</anchorfile>
      <anchor>a1c9c5ef4cb33d914fdc3c14195e43b08</anchor>
      <arglist>(const ticpp::Element &amp;node) override</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>xml_root</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1network__sink__parser.html</anchorfile>
      <anchor>ae0a6a4bd5636610ac647831c3b509f7c</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kXMLRoot</name>
      <anchorfile>classrcppsw_1_1metrics_1_1config_1_1xml_1_1network__sink__parser.html</anchorfile>
      <anchor>ae18837474a346c1a0b0de2bbaa263d37</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::metrics::creatable_collector_spec</name>
    <filename>namespacercppsw_1_1metrics.html</filename>
    <anchor>structrcppsw_1_1metrics_1_1creatable__collector__spec</anchor>
    <member kind="variable">
      <type>std::type_index</type>
      <name>id</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a6390a65d0a7a5881811c5f964ac67bfd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>input_name</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>ac0ddc4b80b6e4f7fb7abd7ff21fd3298</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>scoped_name</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a8240ce8ad6fa16304301eb50e3f82a1a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>rmetrics::output_mode</type>
      <name>valid_modes</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a55e908c9a9495d99060944f5a3cc0896</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::csv_sink</name>
    <filename>classrcppsw_1_1metrics_1_1csv__sink.html</filename>
    <base>rcppsw::metrics::file_sink</base>
    <base>client&lt; csv_sink &gt;</base>
    <member kind="function">
      <type></type>
      <name>csv_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>a3ab1564a8a30cfb2e3371a276c3881d9</anchor>
      <arglist>(fs::path fpath, const rmetrics::output_mode &amp;mode, const rtypes::timestep &amp;interval)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~csv_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>ad70c9f5b7ce74901f17d4f02c2e730be</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>finalize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>a465a3dcbcb00f4f802fcbbb54b468cc6</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function">
      <type>write_status</type>
      <name>flush</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>ae5a5abf2b9970700890cea317b19c7f2</anchor>
      <arglist>(const rmetrics::base_data *data, const rtypes::timestep &amp;t) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>a8a80d487979b8cf299c98861e5933dff</anchor>
      <arglist>(const rmetrics::base_data *data) override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>std::string</type>
      <name>csv_entry_domavg</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>a10ecbaca06a54da222c68dc04c3daaa5</anchor>
      <arglist>(const T &amp;sum, const U &amp;count, bool last=false) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>std::string</type>
      <name>csv_entry_intavg</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>a5b7de877691ddf0ddf91af350e197bbe</anchor>
      <arglist>(const T &amp;sum, bool last=false) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>std::string</type>
      <name>csv_entry_tsavg</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>a289090fa1bdd45959d2d96a27a28975e</anchor>
      <arglist>(const T &amp;sum, const rtypes::timestep &amp;t, bool last=false) const</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual std::list&lt; std::string &gt;</type>
      <name>csv_header_cols</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>ae322c7b3480dad5c9c0acc055cc52b75</anchor>
      <arglist>(const rmetrics::base_data *data) const =0</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>csv_header_write</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>adb5b6ba9d507686bb0776f8b731b1604</anchor>
      <arglist>(const rmetrics::base_data *data)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="pure">
      <type>virtual boost::optional&lt; std::string &gt;</type>
      <name>csv_line_build</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>a864f67c5dbdc5a9824084ee9aa8534d8</anchor>
      <arglist>(const rmetrics::base_data *data, const rtypes::timestep &amp;t)=0</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>std::list&lt; std::string &gt;</type>
      <name>dflt_csv_header_cols</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>aac2c32da9f80eee0458b2fe79a343df5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const std::string &amp;</type>
      <name>separator</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>a28553f32e242b0a4787243520bc5f1ef</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const std::string</type>
      <name>mc_separator</name>
      <anchorfile>classrcppsw_1_1metrics_1_1csv__sink.html</anchorfile>
      <anchor>a800932f6484931752cd57c34caf94b97</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::metrics::detail::creatable_collector_set_comparator</name>
    <filename>structrcppsw_1_1metrics_1_1detail_1_1creatable__collector__set__comparator.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>operator()</name>
      <anchorfile>structrcppsw_1_1metrics_1_1detail_1_1creatable__collector__set__comparator.html</anchorfile>
      <anchor>a63c80ce3b0daf1c3e89f97e93465468d</anchor>
      <arglist>(const creatable_collector_spec &amp;lhs, const creatable_collector_spec &amp;rhs) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::file_sink</name>
    <filename>classrcppsw_1_1metrics_1_1file__sink.html</filename>
    <base>client&lt; file_sink &gt;</base>
    <base>rcppsw::metrics::base_sink</base>
    <member kind="function">
      <type></type>
      <name>file_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink.html</anchorfile>
      <anchor>ad43844ff4f9c9502bfd3ca74e4967c3f</anchor>
      <arglist>(fs::path fpath, const rmetrics::output_mode &amp;mode, const rtypes::timestep &amp;interval)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~file_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink.html</anchorfile>
      <anchor>a2b95fa5bb1151a10c24448406e0bdd66</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const fs::path &amp;</type>
      <name>fpath</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink.html</anchorfile>
      <anchor>a1c6dcbd414a50e24cc65f46d3a684136</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>std::ofstream *</type>
      <name>ofile</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink.html</anchorfile>
      <anchor>a4b52acd537867288ec6fbbbc0dc2ba5c</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>retry_io</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink.html</anchorfile>
      <anchor>ae1af0e39e5af916ea1da34c4f151b939</anchor>
      <arglist>(const std::function&lt; void(void)&gt; &amp;cb)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::file_sink_registerer</name>
    <filename>classrcppsw_1_1metrics_1_1file__sink__registerer.html</filename>
    <base>client&lt; file_sink_registerer &gt;</base>
    <member kind="function">
      <type></type>
      <name>file_sink_registerer</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink__registerer.html</anchorfile>
      <anchor>a02b9047b12dd851c7e91ad2874c153d3</anchor>
      <arglist>(const file_sink_registerer &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>file_sink_registerer</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink__registerer.html</anchorfile>
      <anchor>ab1c2540b310e318373a66986197030af</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>collector_registration_spec&lt; TSink &gt;</type>
      <name>calc_registration_spec</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink__registerer.html</anchorfile>
      <anchor>a9c8b39ada0dc9af61bbf17eecbf40e12</anchor>
      <arglist>(fs_output_manager *manager, const rmconfig::file_sink_config *const config, const std::string &amp;xml_name, const rmetrics::output_mode &amp;allowed) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>emit_diagnostic</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink__registerer.html</anchorfile>
      <anchor>afea04903f2c7dc18de9b25dbe388beb1</anchor>
      <arglist>(const TIterator &amp;it, const collector_registration_spec&lt; TSink &gt; &amp;spec)</arglist>
    </member>
    <member kind="function">
      <type>file_sink_registerer &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1metrics_1_1file__sink__registerer.html</anchorfile>
      <anchor>aa2b3d5f634af5e6c4feca337953a8dcd</anchor>
      <arglist>(const file_sink_registerer &amp;)=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::fs_output_manager</name>
    <filename>classrcppsw_1_1metrics_1_1fs__output__manager.html</filename>
    <base>client&lt; fs_output_manager &gt;</base>
    <base>rcppsw::metrics::base_manager</base>
    <member kind="function">
      <type></type>
      <name>fs_output_manager</name>
      <anchorfile>classrcppsw_1_1metrics_1_1fs__output__manager.html</anchorfile>
      <anchor>a3d3d483b116801516461d12074b7f81a</anchor>
      <arglist>(const rmconfig::metrics_config *mconfig, const fs::path &amp;output_root)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~fs_output_manager</name>
      <anchorfile>classrcppsw_1_1metrics_1_1fs__output__manager.html</anchorfile>
      <anchor>a4cef3f8a13f707a690fa7832790de833</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>collector_preregister</name>
      <anchorfile>classrcppsw_1_1metrics_1_1fs__output__manager.html</anchorfile>
      <anchor>a997d09a6f858d87dd63401de9c138288</anchor>
      <arglist>(const std::string &amp;scoped_name, const rmetrics::output_mode &amp;mode) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>finalize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1fs__output__manager.html</anchorfile>
      <anchor>adf94cef27fba9e24f8aa9405b9930da6</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>flush</name>
      <anchorfile>classrcppsw_1_1metrics_1_1fs__output__manager.html</anchorfile>
      <anchor>afc172d19400e7cd33bbeb287bffb5f98</anchor>
      <arglist>(const rmetrics::output_mode &amp;mode) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1fs__output__manager.html</anchorfile>
      <anchor>a45b3ffdde94b1ef6e63d3e00b08301ee</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>interval_reset</name>
      <anchorfile>classrcppsw_1_1metrics_1_1fs__output__manager.html</anchorfile>
      <anchor>a8e60a5b664259e30bcf970356d383121</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function">
      <type>const fs::path &amp;</type>
      <name>metrics_path</name>
      <anchorfile>classrcppsw_1_1metrics_1_1fs__output__manager.html</anchorfile>
      <anchor>a3dd662269c6ef990f22750d1a5c9c5bc</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>timestep_inc</name>
      <anchorfile>classrcppsw_1_1metrics_1_1fs__output__manager.html</anchorfile>
      <anchor>a48064828936c8c36fb4de3dc4ecc372b</anchor>
      <arglist>(void) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::network_output_manager</name>
    <filename>classrcppsw_1_1metrics_1_1network__output__manager.html</filename>
    <base>client&lt; network_output_manager &gt;</base>
    <base>rcppsw::metrics::base_manager</base>
    <member kind="function">
      <type></type>
      <name>network_output_manager</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__output__manager.html</anchorfile>
      <anchor>a7fe6c273b229d5fdb5c9aaf0995c53de</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~network_output_manager</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__output__manager.html</anchorfile>
      <anchor>a9b2332e1dcb4bfe8ce8da95e02e51c08</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>collector_preregister</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__output__manager.html</anchorfile>
      <anchor>a25ff616824b471c8885d185f131655cc</anchor>
      <arglist>(const std::string &amp;scoped_name, const rmetrics::output_mode &amp;mode) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>finalize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__output__manager.html</anchorfile>
      <anchor>a779dcdd9871d9c6f0506b6af5eba82f4</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>flush</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__output__manager.html</anchorfile>
      <anchor>a8c11bc304d813efe4cd02ed433ed9e1a</anchor>
      <arglist>(const rmetrics::output_mode &amp;mode) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>initialize</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__output__manager.html</anchorfile>
      <anchor>afe5609252ab6298dcb2d1a9ed0f7ee7e</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>interval_reset</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__output__manager.html</anchorfile>
      <anchor>a7be1ba72b5c41a5cb8a5c68ce7e1f96d</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>timestep_inc</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__output__manager.html</anchorfile>
      <anchor>ac35707ad934b1d2b4f24f444e505371a</anchor>
      <arglist>(void) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::network_sink</name>
    <filename>classrcppsw_1_1metrics_1_1network__sink.html</filename>
    <base>rcppsw::metrics::base_sink</base>
    <base>client&lt; network_sink &gt;</base>
    <member kind="function">
      <type></type>
      <name>network_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__sink.html</anchorfile>
      <anchor>ace8e2a0c987f47a4b7b53ace14086314</anchor>
      <arglist>(const std::string &amp;dest, const rmetrics::output_mode &amp;mode, const rtypes::timestep &amp;interval)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~network_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__sink.html</anchorfile>
      <anchor>a452b0b4d122e859590b7094ad3185858</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>dest</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__sink.html</anchorfile>
      <anchor>a636f9bd96eb8a80f075114f3f3ab19ce</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::network_sink_registerer</name>
    <filename>classrcppsw_1_1metrics_1_1network__sink__registerer.html</filename>
    <base>client&lt; network_sink_registerer &gt;</base>
    <member kind="function">
      <type></type>
      <name>network_sink_registerer</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__sink__registerer.html</anchorfile>
      <anchor>afd0e352056c799c5c6b8d20029ed7ed8</anchor>
      <arglist>(const network_sink_registerer &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>network_sink_registerer</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__sink__registerer.html</anchorfile>
      <anchor>a1dd9239e9f4568f5f82fae05a202d901</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>collector_registration_spec&lt; TSink &gt;</type>
      <name>calc_registration_spec</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__sink__registerer.html</anchorfile>
      <anchor>a98115d3c0ff1a4e538424950a84616dc</anchor>
      <arglist>(network_output_manager *, const rmconfig::network_sink_config *const config, const std::string &amp;xml_name, const rmetrics::output_mode &amp;allowed) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>emit_diagnostic</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__sink__registerer.html</anchorfile>
      <anchor>a918a62594da5be8b63a933594633537b</anchor>
      <arglist>(const TIterator &amp;it, const collector_registration_spec&lt; TSink &gt; &amp;spec)</arglist>
    </member>
    <member kind="function">
      <type>network_sink_registerer &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1metrics_1_1network__sink__registerer.html</anchorfile>
      <anchor>af42c05a0495c7247bb4fc6440eaccdc0</anchor>
      <arglist>(const network_sink_registerer &amp;)=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::register_using_config</name>
    <filename>classrcppsw_1_1metrics_1_1register__using__config.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>register_using_config</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__using__config.html</anchorfile>
      <anchor>a9e69d369ed3f4494b4d0ef5568b537ff</anchor>
      <arglist>(const register_using_config &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>register_using_config</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__using__config.html</anchorfile>
      <anchor>a73390b2a85706f6212b88b7abb669b83</anchor>
      <arglist>(const TSinkRegisterer &amp;&amp;registerer, const TConfig *config)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__using__config.html</anchorfile>
      <anchor>a125f562d60b1d2ce2011c5868e286494</anchor>
      <arglist>(const TPair &amp;pair)</arglist>
    </member>
    <member kind="function">
      <type>register_using_config &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__using__config.html</anchorfile>
      <anchor>a40c0a445f3768cb2bf912face4fe07b8</anchor>
      <arglist>(const register_using_config &amp;)=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::metrics::register_with_sink</name>
    <filename>classrcppsw_1_1metrics_1_1register__with__sink.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
    <base>client&lt; register_with_sink&lt; TMetricsManager, TSinkMixin, void &gt; &gt;</base>
    <member kind="typedef">
      <type>typename std::conditional&lt; std::is_same&lt; TExtraArgsType, void &gt;::value, std::tuple&lt; int &gt;, TExtraArgsType &gt;::type</type>
      <name>extra_args_type</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>a330b3fef4514d2ea2030c8b1fa149b46</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename std::is_same&lt; T, void &gt;</type>
      <name>no_extra_args</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>ab7879c9376d1842e0fc217cf0d1232f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>register_with_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>a9b289bb9175ccee5f5c5017e2fa81cd5</anchor>
      <arglist>(const register_with_sink &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>register_with_sink</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>aeccf64a10e94bf3d3d8fa87cc3173ddd</anchor>
      <arglist>(TMetricsManager *const manager, const creatable_collector_set &amp;set, const extra_args_type &amp;extra_args={})</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>a3769b44c3d58a6865979236860051b49</anchor>
      <arglist>(const TSinkTypeWrapped &amp;, const TConfig *config)</arglist>
    </member>
    <member kind="function">
      <type>register_with_sink &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>af512fd717da51304eaf5e9a35c7ddf6d</anchor>
      <arglist>(const register_with_sink &amp;)=default</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const creatable_collector_set &amp;</type>
      <name>creatable_set</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>aa7c9a0424d4e5697f93823ec392ee1b9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>do_register</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>a6e8cf5c695c72c3cbdbac87c00055fe8</anchor>
      <arglist>(const std::string &amp;scoped_name, collector_registration_spec&lt; TSink &gt; &amp;&amp;spec)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>do_register</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>a6e8cf5c695c72c3cbdbac87c00055fe8</anchor>
      <arglist>(const std::string &amp;scoped_name, collector_registration_spec&lt; TSink &gt; &amp;&amp;spec)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TMetricsManager *</type>
      <name>manager</name>
      <anchorfile>classrcppsw_1_1metrics_1_1register__with__sink.html</anchorfile>
      <anchor>ab18137473187b4379212122c217ee405</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::can_static_cast</name>
    <filename>structrcppsw_1_1mpl_1_1can__static__cast.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg></templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::can_static_cast&lt; T, U, std::void_t&lt; decltype(static_cast&lt; U &gt;(std::declval&lt; T &gt;()))&gt; &gt;</name>
    <filename>structrcppsw_1_1mpl_1_1can__static__cast_3_01T_00_01U_00_01std_1_1void__t_3_01decltype_07static_37ec0c91c9199650d131864804302a11.html</filename>
    <templarg></templarg>
    <templarg></templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::detail::detector</name>
    <filename>namespacercppsw_1_1mpl_1_1detail.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1detail_1_1detector</anchor>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>TFuncDecltype</templarg>
    <templarg>Args</templarg>
    <member kind="typedef">
      <type>TFailType</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1mpl_1_1detail.html</anchorfile>
      <anchor>ab860e0a6756333ac2bb98fc57ab894ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::false_type</type>
      <name>value</name>
      <anchorfile>namespacercppsw_1_1mpl_1_1detail.html</anchorfile>
      <anchor>a9af41ea9921a879a6d69a1d5b187eb2d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::detail::detector&lt; TFailType, std::void_t&lt; TFuncDecltype&lt; Args... &gt; &gt;, TFuncDecltype, Args... &gt;</name>
    <filename>namespacercppsw_1_1mpl_1_1detail.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1detail_1_1detector_3_01TFailType_00_01std_1_1void__t_3_01TFuncDecltype_3_32bc8d388b776506b636a744392f8897</anchor>
    <templarg></templarg>
    <templarg>TFuncDecltype</templarg>
    <templarg>Args</templarg>
    <member kind="typedef">
      <type>TFuncDecltype&lt; Args... &gt;</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1mpl_1_1detail.html</anchorfile>
      <anchor>a29a26c97ce0a8cb012ae19fb0a8ab883</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::true_type</type>
      <name>value</name>
      <anchorfile>namespacercppsw_1_1mpl_1_1detail.html</anchorfile>
      <anchor>aa2d617c475f75108cc651e8126c067cf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::detail::ExtendTList</name>
    <filename>namespacercppsw_1_1mpl_1_1detail.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1detail_1_1ExtendTList</anchor>
    <templarg></templarg>
    <templarg></templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::detail::ExtendTList&lt; std::tuple&lt; Ts... &gt;, T &gt;</name>
    <filename>namespacercppsw_1_1mpl_1_1detail.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1detail_1_1ExtendTList_3_01std_1_1tuple_3_01Ts_8_8_8_01_4_00_01T_01_4</anchor>
    <templarg></templarg>
    <templarg>Ts</templarg>
    <member kind="typedef">
      <type>std::tuple&lt; Ts..., T &gt;</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1mpl_1_1detail.html</anchorfile>
      <anchor>a8c86f16114b42799f8e104e8a9c89572</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::detail::ExtendTList&lt; std::tuple&lt; void &gt;, T &gt;</name>
    <filename>namespacercppsw_1_1mpl_1_1detail.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1detail_1_1ExtendTList_3_01std_1_1tuple_3_01void_01_4_00_01T_01_4</anchor>
    <templarg></templarg>
    <member kind="typedef">
      <type>std::tuple&lt; T &gt;</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1mpl_1_1detail.html</anchorfile>
      <anchor>a6fdcd6d47c09b9ba8b101a05c91e3d44</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::detail::rename_impl</name>
    <filename>namespacercppsw_1_1mpl_1_1detail.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1detail_1_1rename__impl</anchor>
    <templarg></templarg>
    <templarg>B</templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::detail::rename_impl&lt; A&lt; T... &gt;, B &gt;</name>
    <filename>namespacercppsw_1_1mpl_1_1detail.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1detail_1_1rename__impl_3_01A_3_01T_8_8_8_01_4_00_01B_01_4</anchor>
    <templarg>A</templarg>
    <templarg>T</templarg>
    <templarg>B</templarg>
    <member kind="typedef">
      <type>B&lt; T... &gt;</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1mpl_1_1detail.html</anchorfile>
      <anchor>a231486196efc151ec7f5b95c3bf4043a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::mpl::identity</name>
    <filename>namespacercppsw_1_1mpl.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1identity</anchor>
    <templarg></templarg>
    <member kind="typedef">
      <type>T</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a87b6b32f2c2e6c987a498c9676eca417</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::is_specialization</name>
    <filename>structrcppsw_1_1mpl_1_1is__specialization.html</filename>
    <templarg></templarg>
    <templarg>Template</templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::is_specialization&lt; Template&lt; Args... &gt;, Template &gt;</name>
    <filename>structrcppsw_1_1mpl_1_1is__specialization_3_01Template_3_01Args_8_8_8_01_4_00_01Template_01_4.html</filename>
    <templarg>Template</templarg>
    <templarg>Args</templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::no_such_trait</name>
    <filename>structrcppsw_1_1mpl_1_1no__such__trait.html</filename>
    <member kind="function">
      <type></type>
      <name>no_such_trait</name>
      <anchorfile>structrcppsw_1_1mpl_1_1no__such__trait.html</anchorfile>
      <anchor>abb2036221a6be3ea18d637ead7833bcb</anchor>
      <arglist>()=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>no_such_trait</name>
      <anchorfile>structrcppsw_1_1mpl_1_1no__such__trait.html</anchorfile>
      <anchor>ab3c4e1083b691c8062026845e0dcece4</anchor>
      <arglist>(no_such_trait const &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~no_such_trait</name>
      <anchorfile>structrcppsw_1_1mpl_1_1no__such__trait.html</anchorfile>
      <anchor>ae5852cb9d82abbc270fb965225f7f00d</anchor>
      <arglist>()=delete</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>structrcppsw_1_1mpl_1_1no__such__trait.html</anchorfile>
      <anchor>aafb81fdcca886058f36126bf98a9ea92</anchor>
      <arglist>(no_such_trait const &amp;)=delete</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::mpl::reflectable</name>
    <filename>classrcppsw_1_1mpl_1_1reflectable.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~reflectable</name>
      <anchorfile>classrcppsw_1_1mpl_1_1reflectable.html</anchorfile>
      <anchor>a7b1025532b03e6fe7619811597ed8781</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::type_index</type>
      <name>type_index</name>
      <anchorfile>classrcppsw_1_1mpl_1_1reflectable.html</anchorfile>
      <anchor>a9f48ae849aaca6d7dc638cc89625d5a4</anchor>
      <arglist>(void) const =0</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::typelist_wrap_into</name>
    <filename>namespacercppsw_1_1mpl.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1typelist__wrap__into</anchor>
    <templarg>WrapperType</templarg>
    <templarg>WrapperTypeArgs</templarg>
  </compound>
  <compound kind="struct">
    <name>rcppsw::mpl::typelist_wrap_into::apply</name>
    <filename>namespacercppsw_1_1mpl.html</filename>
    <anchor>structrcppsw_1_1mpl_1_1typelist__wrap__into_1_1apply</anchor>
    <templarg>ApplyArgs</templarg>
    <member kind="typedef">
      <type>WrapperType&lt; ApplyArgs..., WrapperTypeArgs... &gt;</type>
      <name>type</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>abe33e62fdc251b0bf8411c66180e8a06</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::multiprocess::forkable</name>
    <filename>classrcppsw_1_1multiprocess_1_1forkable.html</filename>
    <member kind="function">
      <type></type>
      <name>forkable</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1forkable.html</anchorfile>
      <anchor>a1bcd483d9d6d566e754715623b673b74</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~forkable</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1forkable.html</anchorfile>
      <anchor>a5514402bdb1689f2dfd676fb2048f1bd</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>pid_t</type>
      <name>pid</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1forkable.html</anchorfile>
      <anchor>ace8aca0b043e59d17704803b6a1b846e</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>proc_main</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1forkable.html</anchorfile>
      <anchor>a58dff0ac93ea2dad017c0c8c80899851</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function">
      <type>pid_t</type>
      <name>start</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1forkable.html</anchorfile>
      <anchor>a1aa329ad122f73b47497646382a241ce</anchor>
      <arglist>(const std::string &amp;new_wd, int core=-1)</arglist>
    </member>
    <member kind="function">
      <type>pid_t</type>
      <name>start</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1forkable.html</anchorfile>
      <anchor>a198f77b7c15252aa0a86b4537824f840</anchor>
      <arglist>(int core=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>term</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1forkable.html</anchorfile>
      <anchor>aa3890fb6502b176c11d3cf325e88523e</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>terminated</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1forkable.html</anchorfile>
      <anchor>afdcc1f1ca6c887bfe5c332f532fcd75d</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::multiprocess::ipc_queue</name>
    <filename>classrcppsw_1_1multiprocess_1_1ipc__queue.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>bip::allocator&lt; T, bip::managed_shared_memory::segment_manager &gt;</type>
      <name>allocator_type</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>a836cfee1a48aa7f051e99976ec108dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ipc_queue</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>aff4d27a914500b1a2505c0ed5a1ebd96</anchor>
      <arglist>(allocator_type alloc)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>adc4e7e3e17dc639b748d724444eaea36</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>is_empty</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>aa9cf47972f0b547ab320b4d87596055d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>pop</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>aa719051f801b8c4314920e27e84b8490</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>pop_timed_wait</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>aaed593576202cac7d3ec4fb46ddf59de</anchor>
      <arglist>(T *const element, int to_sec)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>pop_try</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>a67313b521681ee48539ca013abd0abca</anchor>
      <arglist>(T *const element)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>pop_wait</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>a9f81062818670ade7f8a2d77549655ea</anchor>
      <arglist>(T *const element)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>push</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>a1048d7baafead7675460b6a5b8ded80b</anchor>
      <arglist>(T element)</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>size</name>
      <anchorfile>classrcppsw_1_1multiprocess_1_1ipc__queue.html</anchorfile>
      <anchor>a0e863292433bcd72c393696df5708710</anchor>
      <arglist>() const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::multithread::lockable</name>
    <filename>classrcppsw_1_1multithread_1_1lockable.html</filename>
    <member kind="function">
      <type></type>
      <name>lockable</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>a7f8d2ca723c77c97f69df373c24a226e</anchor>
      <arglist>(const lockable &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>lockable</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>a4a57948a6905677a60b0226342b8eded</anchor>
      <arglist>(lockable &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>lockable</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>a3da8c8e084fa236201fa7b7d45bdf00d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~lockable</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>ab6b444cfb796c73351a1552e0079529c</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lock_rd</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>af2733e55cc4b9602b1534cd0d004d2c7</anchor>
      <arglist>(std::shared_mutex *mtx) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lock_wr</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>ac2d3b0309d2e3abef4a0bb1b29d4e5d6</anchor>
      <arglist>(std::shared_mutex *mtx)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>maybe_lock_rd</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>a75286e74c37a908615a7a4c57ca95ceb</anchor>
      <arglist>(std::shared_mutex *mtx, bool cond) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>maybe_lock_wr</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>ac5f9bff5360285c3e54d4e2cf48f46a9</anchor>
      <arglist>(std::shared_mutex *mtx, bool cond)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>maybe_unlock_rd</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>a812f2cfd92e4137de647320f265d34bd</anchor>
      <arglist>(std::shared_mutex *mtx, bool cond) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>maybe_unlock_wr</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>a3d04959c9167145978422a66c2737309</anchor>
      <arglist>(std::shared_mutex *mtx, bool cond)</arglist>
    </member>
    <member kind="function">
      <type>const lockable &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>a7523b8edbd1f63347abaebb883119d43</anchor>
      <arglist>(const lockable &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>lockable &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>ada13577a604c8734a0aaf25b6faf19b8</anchor>
      <arglist>(lockable &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unlock_rd</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>a6f7ebdb93c8940e99dd08302cfbae919</anchor>
      <arglist>(std::shared_mutex *mtx) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unlock_wr</name>
      <anchorfile>classrcppsw_1_1multithread_1_1lockable.html</anchorfile>
      <anchor>aaa9230cd9f7ea275a0abd9978783e3a1</anchor>
      <arglist>(std::shared_mutex *mtx)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::multithread::mt_fsm</name>
    <filename>classrcppsw_1_1multithread_1_1mt__fsm.html</filename>
    <base>rcppsw::patterns::fsm::base_fsm</base>
    <member kind="function">
      <type></type>
      <name>mt_fsm</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__fsm.html</anchorfile>
      <anchor>a3aa40101a78cf217013c0be48c82622e</anchor>
      <arglist>(uint8_t max_states, uint8_t initial_state=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~mt_fsm</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__fsm.html</anchorfile>
      <anchor>a3c6a87c7eb68e7a3142e027e46ec15b2</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__fsm.html</anchorfile>
      <anchor>a712ce65d39e644896cec722296767b86</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>external_event</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__fsm.html</anchorfile>
      <anchor>ae49edf11d684e827d1551563bc958ab6</anchor>
      <arglist>(uint8_t new_state, std::unique_ptr&lt; sm::event_data &gt; data) override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::multithread::mt_queue</name>
    <filename>classrcppsw_1_1multithread_1_1mt__queue.html</filename>
    <templarg></templarg>
    <base>decorator&lt; std::deque&lt; T &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>mt_queue</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__queue.html</anchorfile>
      <anchor>a6b162fc767aea1cb4cdd0ae5a5711861</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>dequeue</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__queue.html</anchorfile>
      <anchor>a5f27543cd548d2f4118286d5c0182120</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>enqueue</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__queue.html</anchorfile>
      <anchor>a56437ecee9d10320c52cdbbad7751710</anchor>
      <arglist>(const T &amp;data)</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__queue.html</anchorfile>
      <anchor>a03e23ef6cd9bddcd69711119403776d8</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(rpdecorator::decorator&lt; T &gt;::decoratee())&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__queue.html</anchorfile>
      <anchor>a03e23ef6cd9bddcd69711119403776d8</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(rpdecorator::decorator&lt; T &gt;::decoratee())&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__queue.html</anchorfile>
      <anchor>a03e23ef6cd9bddcd69711119403776d8</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(rpdecorator::decorator&lt; T &gt;::decoratee())&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__queue.html</anchorfile>
      <anchor>a03e23ef6cd9bddcd69711119403776d8</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(rpdecorator::decorator&lt; T &gt;::decoratee())&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__queue.html</anchorfile>
      <anchor>a03e23ef6cd9bddcd69711119403776d8</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(rpdecorator::decorator&lt; T &gt;::decoratee())&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__queue.html</anchorfile>
      <anchor>a03e23ef6cd9bddcd69711119403776d8</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(rpdecorator::decorator&lt; T &gt;::decoratee())&gt;().Func(args...))</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::multithread::mt_vector</name>
    <filename>classrcppsw_1_1multithread_1_1mt__vector.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>typename std::vector&lt; T &gt;::const_iterator</type>
      <name>const_iterator</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__vector.html</anchorfile>
      <anchor>a139f7d7d0672468747a19e133c5cddee</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>mt_vector</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__vector.html</anchorfile>
      <anchor>a7a4f43d0b4cd8db2c4b1be45d3e25c51</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__vector.html</anchorfile>
      <anchor>a3ad67f3d7cb97af6ffdab45f209f7155</anchor>
      <arglist>(Args &amp;&amp;... args) -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__vector.html</anchorfile>
      <anchor>a49bc892aa394754b32d5425d34e31aeb</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__vector.html</anchorfile>
      <anchor>a49bc892aa394754b32d5425d34e31aeb</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>auto</type>
      <name>Func</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__vector.html</anchorfile>
      <anchor>a49bc892aa394754b32d5425d34e31aeb</anchor>
      <arglist>(Args &amp;&amp;... args) const -&gt; decltype(std::declval&lt; decltype(Member)&gt;().Func(args...))</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>push_back</name>
      <anchorfile>classrcppsw_1_1multithread_1_1mt__vector.html</anchorfile>
      <anchor>adc4c6c0dce0345bd2db43ce6afa71b55</anchor>
      <arglist>(const T &amp;data)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::multithread::threadable</name>
    <filename>classrcppsw_1_1multithread_1_1threadable.html</filename>
    <member kind="function">
      <type></type>
      <name>threadable</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>a8a88b65989e47d2fa7cf4e4b7f22c7cf</anchor>
      <arglist>(const threadable &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>threadable</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>ae1082e3cabb7f10d94701f7609f47433</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~threadable</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>a84af36ca4a1b5623190f4aea1a5eb57d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>join</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>ab16685fa3dfd268468a04c9d435054ec</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>threadable &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>abb754eb863ad7870af44dac57adec344</anchor>
      <arglist>(const threadable &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>status_t</type>
      <name>start</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>ad0c3ee8f133c56e0cad5b9c6ef6fd397</anchor>
      <arglist>(void *arg, int core=-1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>term</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>a1154f96356b7ed6609db39f56806f002</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void *</type>
      <name>thread_main</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>abd675da47c1456146727e6d095d6a9af</anchor>
      <arglist>(void *arg)=0</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>exit</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>afffdf59b6d1651307e24107d1264228b</anchor>
      <arglist>(void *ret=nullptr)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>terminated</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>a985a5b76b26acb46cd27f2013ad4236b</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>pthread_t</type>
      <name>thread_handle</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>ac2973e83a76951ab840c86bfb0164241</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int64_t</type>
      <name>thread_id</name>
      <anchorfile>classrcppsw_1_1multithread_1_1threadable.html</anchorfile>
      <anchor>ae958a1996893228ed5f6413281a3e3c9</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::decorator::decorator</name>
    <filename>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>TDecoratee</type>
      <name>decoratee_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a741c896a38d2c22bfcd68382fc0aee64</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>decorator&lt; decoratee_type &gt;</type>
      <name>decorator_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1b8e1bf59abf4cb7039f657c1351dbf5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0e7167ad4e2d030d6c451a867db8af5e</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a32c13ab58d3bd71c61030090590a9d62</anchor>
      <arglist>(decoratee_type &amp;&amp;arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a3856e90a033659fc506a77c613bfc89f</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a280934f4a5829a42c7916ba29560d645</anchor>
      <arglist>(std::initializer_list&lt; U &gt; args)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a64c494d06f4fcbc9e52345db78510791</anchor>
      <arglist>(TArgs... args)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~decorator</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a1816de4c343796e84f48c3603b8041ab</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a519a95005089f4b8c476dc3b5dc0f3ab</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const decoratee_type &amp;</type>
      <name>decoratee</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a34ab8f2525dae8185bf161985885e8c2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>a0f947db92e941d973426b19c1aa1fa9c</anchor>
      <arglist>(const decorator &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>decorator &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa7dcaa3ec447cb1af590f4a64de10b09</anchor>
      <arglist>(decorator &amp;&amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>aa91bf92ef0eda53cc43ce584c40f5c49</anchor>
      <arglist>(TArgs &amp;&amp;... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>redecorate_with</name>
      <anchorfile>classrcppsw_1_1patterns_1_1decorator_1_1decorator.html</anchorfile>
      <anchor>af34e316851d6ccde1ab339f9dadf0c2a</anchor>
      <arglist>(const decoratee_type &amp;d)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::factory::detail::base_factory</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</filename>
    <templarg></templarg>
    <templarg>TPointerWrapper</templarg>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>Args</templarg>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a000d4b0250412166a44ddef9e75ab21d</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>TPointerWrapper&lt; TBase &gt;</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>ab4878ff7354eb99c0a3a52a2c8c6ea6d</anchor>
      <arglist>(const TKeyType &amp;name, Args... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>a6d82ea282d6e32ce743632f249fb724a</anchor>
      <arglist>(const TKeyType &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unregister_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1base__factory.html</anchorfile>
      <anchor>afa8c84b04fd09d44cd97b2c6505c67b4</anchor>
      <arglist>(const TKeyType &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>rcppsw::patterns::factory::detail::factory_releasing_type</name>
    <filename>namespacercppsw_1_1patterns_1_1factory_1_1detail.html</filename>
    <anchor>structrcppsw_1_1patterns_1_1factory_1_1detail_1_1factory__releasing__type</anchor>
  </compound>
  <compound kind="struct">
    <name>rcppsw::patterns::factory::detail::factory_sharing_type</name>
    <filename>namespacercppsw_1_1patterns_1_1factory_1_1detail.html</filename>
    <anchor>structrcppsw_1_1patterns_1_1factory_1_1detail_1_1factory__sharing__type</anchor>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::factory::detail::factory_singleton</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1factory__singleton.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>Args</templarg>
    <base>singleton&lt; base_factory&lt; TType, std::unique_ptr, TBase, Args... &gt; &gt;</base>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::factory::detail::multifactory</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1multifactory.html</filename>
    <templarg></templarg>
    <templarg>TPointerWrapper</templarg>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>multifactory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1multifactory.html</anchorfile>
      <anchor>a7aea995f16d899b4eb3ce20c891b9716</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~multifactory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1multifactory.html</anchorfile>
      <anchor>a7645498b980dcd47cc365de1abfc9532</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>TPointerWrapper&lt; TBase &gt;</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1multifactory.html</anchorfile>
      <anchor>a448cef77182ecef716177f7b2c6b0d73</anchor>
      <arglist>(const std::string &amp;name, Args...args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1detail_1_1multifactory.html</anchorfile>
      <anchor>a1e227e19a25a827e7e441c62a4758967</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::factory::releasing_factory</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1releasing__factory.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>Args</templarg>
    <base>base_factory&lt; detail::factory_releasing_type, std::unique_ptr, TBase, TKeyType, Args... &gt;</base>
    <member kind="function">
      <type></type>
      <name>~releasing_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1releasing__factory.html</anchorfile>
      <anchor>a931a4c9130d95d9158243580f7b48ace</anchor>
      <arglist>(void) override=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::factory::sharing_factory</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1sharing__factory.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>Args</templarg>
    <base>base_factory&lt; detail::factory_sharing_type, std::shared_ptr, TBase, TKeyType, Args... &gt;</base>
    <member kind="function">
      <type></type>
      <name>~sharing_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1sharing__factory.html</anchorfile>
      <anchor>a4a72638b4415afc7384536d8074d2990</anchor>
      <arglist>(void) override=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::base_fsm</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</filename>
    <base>client&lt; base_fsm &gt;</base>
    <member kind="function">
      <type></type>
      <name>base_fsm</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a02f75749183246e300210cd6a7a308d8</anchor>
      <arglist>(const base_fsm &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>base_fsm</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a6b0ab3c20b50882d7e145bfbabffed92</anchor>
      <arglist>(uint8_t max_states, uint8_t initial_state=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~base_fsm</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a14bebe9ef1225637a95971f17734eecd</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>current_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a857086bfbdd54b829cf2e839a8f78587</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>init</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a28dcbf6903171b491f9f49e76b380a47</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>inject_event</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a585739cca322eda48b2d788e16cb36a3</anchor>
      <arglist>(int signal, int type)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>inject_event</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a5f3eb45a6e8c0d402e8ba3fbe18027eb</anchor>
      <arglist>(std::unique_ptr&lt; event_data &gt; event)</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>last_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a22ed6eb5646dd2bfcdfd29effb44c895</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>max_states</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>abc6dd4426ea4b66799d82084301e5d56</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>base_fsm &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a7a56e00ed9b58320416ff440c173fead</anchor>
      <arglist>(const base_fsm &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>previous_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a0d83a8f65d17d2932608bc33aa015581</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>class event_data *</type>
      <name>event_data</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a7e7f9c272b0db4c1a8766f6f76cb0585</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>const class event_data *</type>
      <name>event_data</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>ae81d3007d6d0e4aa1b6c9521ae59455f</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>event_data_hold</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>af18293d39b40e1e2c60a81cded8a9e5a</anchor>
      <arglist>(bool b)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>event_data_hold</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a82ea8aed531c4b4951b095bb863f091f</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>std::unique_ptr&lt; class event_data &gt;</type>
      <name>event_data_release</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a70d0b834423157fe8b09690afa80a83d</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>external_event</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>adb6921a6426dec4efed0e16cba15cbe4</anchor>
      <arglist>(uint8_t new_state)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>external_event</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>aa7fbf7096bfea773455ec2f9265e0b1b</anchor>
      <arglist>(uint8_t new_state, std::unique_ptr&lt; class event_data &gt; data)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>generated_event</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a00a0983368a370e3a807a831c24709f4</anchor>
      <arglist>(bool b)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>has_generated_event</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a9b5897b7785ebcabce2a118daf57b4a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>uint8_t</type>
      <name>initial_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>ad97c446c7cb456dabbcc93b96b8076c5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>internal_event</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>ab6ab7bbe02e3f0bcdba23e6547d8afa5</anchor>
      <arglist>(uint8_t new_state)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>internal_event</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>afeb001abffdcc060bde5d9bbdfd1af37</anchor>
      <arglist>(uint8_t new_state, std::unique_ptr&lt; class event_data &gt; data)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>next_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a2ace41a1c2879201b362ede5898e0047</anchor>
      <arglist>(uint8_t next_state)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>uint8_t</type>
      <name>next_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a363425a1ba6f260851673e2f1b78efee</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>state_engine</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a3c5718316ff2a98a9459307fcf4c148e</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>state_engine_step</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>afddb540ea0cc710481164d8a2890fcae</anchor>
      <arglist>(const state_map_ex_row *c_row_ex)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>state_engine_step</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a18b15e2f252daaf1e15ee0ea502b5370</anchor>
      <arglist>(const state_map_row *c_row)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual const state_map_row *</type>
      <name>state_map</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>a8e5583c34d8c99b092fb60e948748090</anchor>
      <arglist>(size_t)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual const state_map_ex_row *</type>
      <name>state_map_ex</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>add40018c388e8fb9f4d76a7df7546582</anchor>
      <arglist>(size_t)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>update_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1base__fsm.html</anchorfile>
      <anchor>ab5d7452fd568e2beef757bcb56649ad9</anchor>
      <arglist>(uint8_t new_state)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::event_data</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1event__data.html</filename>
    <member kind="function">
      <type></type>
      <name>event_data</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__data.html</anchorfile>
      <anchor>ae5d46e23fb325bc0320530e81be056dd</anchor>
      <arglist>(int signal, int type=event_type::ekNORMAL)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>event_data</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__data.html</anchorfile>
      <anchor>a37a6cea9d76da256f6d574654d864fe6</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~event_data</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__data.html</anchorfile>
      <anchor>ab91f697dcb0e1c8f7e491481b3c00020</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__data.html</anchorfile>
      <anchor>a4b52acccdcd60dae62843e7a3145c974</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>signal</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__data.html</anchorfile>
      <anchor>a736a15c5942edc741eac236bd84a81d3</anchor>
      <arglist>(int signal)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>signal</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__data.html</anchorfile>
      <anchor>a8236d8d3654fd2127c235e5bc85df12f</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__data.html</anchorfile>
      <anchor>a4db06e520182cf9ba89782879efb2bfb</anchor>
      <arglist>(int type)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__data.html</anchorfile>
      <anchor>a0489b7b8bcb463185bb0d438caafa160</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::event_signal</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</filename>
    <member kind="enumvalue">
      <name>ekEXTERNAL_SIGNALS</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a5d10d7249aa2765720aef8506b50da60</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekFATAL</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a238493360658526d1c0645b9c89778a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekHANDLED</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a4dd7177517305a54770dcd36ff94bec8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekIGNORED</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a6936548aa7b50c598d7638d37f967729</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekRUN</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a0f7fe3e925bd12ef093a6af49e31beda</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekUNHANDLED</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88af12ba96dbdd357dd79626a1d119ec596</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekIGNORED</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a6936548aa7b50c598d7638d37f967729</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekFATAL</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a238493360658526d1c0645b9c89778a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekHANDLED</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a4dd7177517305a54770dcd36ff94bec8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekUNHANDLED</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88af12ba96dbdd357dd79626a1d119ec596</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekRUN</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a0f7fe3e925bd12ef093a6af49e31beda</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekEXTERNAL_SIGNALS</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__signal.html</anchorfile>
      <anchor>af5e4be7e8737e5a31fac049059e5fe88a5d10d7249aa2765720aef8506b50da60</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::event_type</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1event__type.html</filename>
    <member kind="enumvalue">
      <name>ekNORMAL</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__type.html</anchorfile>
      <anchor>a4f25bc6ab040618d7184758739008fc4a58e644f0aac2b5af59ac5bd21baa6acc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekCHILD</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__type.html</anchorfile>
      <anchor>a4f25bc6ab040618d7184758739008fc4a57d821f860506bdb3e4e745b229ec849</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekEXTERNAL_TYPES</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__type.html</anchorfile>
      <anchor>a4f25bc6ab040618d7184758739008fc4ac74d5bbd9dd0d0a5567bac475d696aeb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekCHILD</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__type.html</anchorfile>
      <anchor>a4f25bc6ab040618d7184758739008fc4a57d821f860506bdb3e4e745b229ec849</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekEXTERNAL_TYPES</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__type.html</anchorfile>
      <anchor>a4f25bc6ab040618d7184758739008fc4ac74d5bbd9dd0d0a5567bac475d696aeb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekNORMAL</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1event__type.html</anchorfile>
      <anchor>a4f25bc6ab040618d7184758739008fc4a58e644f0aac2b5af59ac5bd21baa6acc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::hfsm</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1hfsm.html</filename>
    <base>rcppsw::patterns::fsm::base_fsm</base>
    <base>client&lt; hfsm &gt;</base>
    <member kind="function">
      <type></type>
      <name>hfsm</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm.html</anchorfile>
      <anchor>ab972b29b2e2bc2a546db6dbd9ce203ba</anchor>
      <arglist>(uint8_t max_states, uint8_t initial_state=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~hfsm</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm.html</anchorfile>
      <anchor>a9fad16bf2241fc85cad45190b5f3f7e0</anchor>
      <arglist>() override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>change_parent</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm.html</anchorfile>
      <anchor>aa1061578cad33acdfda315e9dfbd84ca</anchor>
      <arglist>(uint8_t state, rcppsw::patterns::fsm::state *new_parent)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm.html</anchorfile>
      <anchor>a6418e104518e7f0b4c6e89e994249b05</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>ST_top_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm.html</anchorfile>
      <anchor>a61e88139080279ad7cd17a361cde8361</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>hfsm_state_action0&lt; hfsm, &amp;hfsm::ST_top_state &gt; *</type>
      <name>top_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm.html</anchorfile>
      <anchor>a8302a271ce6a8b8abc64f2835e2d5019</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::hfsm_state</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state.html</filename>
    <base>rcppsw::patterns::fsm::state</base>
    <member kind="function">
      <type></type>
      <name>hfsm_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state.html</anchorfile>
      <anchor>ad735282dd42da06f59f8b994b589241c</anchor>
      <arglist>(const hfsm_state &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>hfsm_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state.html</anchorfile>
      <anchor>a32dfa6e4b98b84b7bb5c9438847736a3</anchor>
      <arglist>(hfsm_state *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~hfsm_state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state.html</anchorfile>
      <anchor>ad564015589ba2e1c9f4980f71b15f520</anchor>
      <arglist>() override=default</arglist>
    </member>
    <member kind="function">
      <type>hfsm_state &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state.html</anchorfile>
      <anchor>a9df9ce9a9d78a76d72e88c0f7932cafe</anchor>
      <arglist>(const hfsm_state &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parent</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state.html</anchorfile>
      <anchor>ac78ff2658dfb74144a37ae37fbfc2b8f</anchor>
      <arglist>(rcppsw::patterns::fsm::state *parent)</arglist>
    </member>
    <member kind="function">
      <type>rcppsw::patterns::fsm::state *</type>
      <name>parent</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state.html</anchorfile>
      <anchor>a13da60f5e2a5993712f74c3aa67cafab</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::hfsm_state_action0</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action0.html</filename>
    <templarg></templarg>
    <templarg>Handler</templarg>
    <base>rcppsw::patterns::fsm::hfsm_state</base>
    <member kind="function">
      <type></type>
      <name>hfsm_state_action0</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action0.html</anchorfile>
      <anchor>a61a2c21e3fb0b51480377d105d0e883e</anchor>
      <arglist>(hfsm_state *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~hfsm_state_action0</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action0.html</anchorfile>
      <anchor>abcd21a5d6fb5e80c503ac2d71525a667</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>invoke_state_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action0.html</anchorfile>
      <anchor>a25b82048ef7cfba76a34c2cd07ed17d9</anchor>
      <arglist>(base_fsm *fsm, event_data *) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::hfsm_state_action1</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action1.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>Handler</templarg>
    <base>rcppsw::patterns::fsm::hfsm_state</base>
    <member kind="function">
      <type></type>
      <name>hfsm_state_action1</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action1.html</anchorfile>
      <anchor>a522e3becda60a040fefc3df17d21d7ad</anchor>
      <arglist>(hfsm_state *parent)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~hfsm_state_action1</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action1.html</anchorfile>
      <anchor>afa2ac61ee00be44878241d9d443476fd</anchor>
      <arglist>() override=default</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>invoke_state_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1hfsm__state__action1.html</anchorfile>
      <anchor>a491d1acb9146b6ed579daca9b9d24589</anchor>
      <arglist>(base_fsm *fsm, event_data *event) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::no_event_data</name>
    <filename>namespacercppsw_1_1patterns_1_1fsm.html</filename>
    <anchor>classrcppsw_1_1patterns_1_1fsm_1_1no__event__data</anchor>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state.html</filename>
    <member kind="function">
      <type></type>
      <name>state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state.html</anchorfile>
      <anchor>a990ded646f9c5c46c0c99212c0856797</anchor>
      <arglist>(const state &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state.html</anchorfile>
      <anchor>ae8e0476fb14103a9ee266aa2ba4e96b3</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state.html</anchorfile>
      <anchor>a786e9d8746a76418b78dd7df21dd8136</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>invoke_state_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state.html</anchorfile>
      <anchor>a4eccda20940c245258784556c9713eee</anchor>
      <arglist>(base_fsm *sm, event_data *data) const =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_action0</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__action0.html</filename>
    <templarg></templarg>
    <templarg>Func</templarg>
    <base>rcppsw::patterns::fsm::state</base>
    <member kind="function">
      <type></type>
      <name>state_action0</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__action0.html</anchorfile>
      <anchor>a4b0357cefef978eb07b3ee48617b1f41</anchor>
      <arglist>(const state_action0 &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>state_action0</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__action0.html</anchorfile>
      <anchor>a9a7bd3a49322d6be6d143ffd8d17bfb9</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~state_action0</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__action0.html</anchorfile>
      <anchor>a8ac062ce1eabbaf371f7db85098dd70c</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>invoke_state_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__action0.html</anchorfile>
      <anchor>a0f7bb062aa3f05be77558d2a6be5e7e6</anchor>
      <arglist>(base_fsm *sm, event_data *) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_action1</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__action1.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>Func</templarg>
    <base>rcppsw::patterns::fsm::state</base>
    <member kind="function">
      <type></type>
      <name>state_action1</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__action1.html</anchorfile>
      <anchor>a86b8f106891320354e6afbbc9222f3db</anchor>
      <arglist>(const state_action1 &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>state_action1</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__action1.html</anchorfile>
      <anchor>aab067b1e70f4d49a6b387f1202759919</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~state_action1</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__action1.html</anchorfile>
      <anchor>ae3cca0b7d2261f60c91cc8c02094d8ba</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>invoke_state_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__action1.html</anchorfile>
      <anchor>abe1d989fcb1eb61735adf9399b3f64b0</anchor>
      <arglist>(base_fsm *sm, event_data *data) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_entry</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__entry.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~state_entry</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__entry.html</anchorfile>
      <anchor>a15b784bfbd75ee3889aceb1e3df49962</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>invoke_entry_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__entry.html</anchorfile>
      <anchor>a5e9a3f1e559f4b1a1f01a39f035d0ede</anchor>
      <arglist>(base_fsm *sm, const event_data *data) const =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_entry_action0</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__entry__action0.html</filename>
    <templarg></templarg>
    <templarg>Func</templarg>
    <base>rcppsw::patterns::fsm::state_entry</base>
    <member kind="function">
      <type></type>
      <name>~state_entry_action0</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__entry__action0.html</anchorfile>
      <anchor>ada371eb169c13ddf788c0092d9318161</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invoke_entry_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__entry__action0.html</anchorfile>
      <anchor>a870c0d3e53589d8cde9d4fa34b1390d0</anchor>
      <arglist>(base_fsm *sm, const event_data *) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_entry_action1</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__entry__action1.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>Func</templarg>
    <base>rcppsw::patterns::fsm::state_entry</base>
    <member kind="function">
      <type></type>
      <name>~state_entry_action1</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__entry__action1.html</anchorfile>
      <anchor>a7c306b7a9e7215dee5203ca4f785c297</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invoke_entry_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__entry__action1.html</anchorfile>
      <anchor>a57c959cd10685790d05c34dbbf47c07e</anchor>
      <arglist>(base_fsm *sm, const event_data *data) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_exit</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__exit.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~state_exit</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__exit.html</anchorfile>
      <anchor>a9abe2c072e1ff2b4653f303dccaf74eb</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>invoke_exit_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__exit.html</anchorfile>
      <anchor>a7559869b70c96a58f545b6adaaeb6f94</anchor>
      <arglist>(base_fsm *sm) const =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_exit_action</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__exit__action.html</filename>
    <templarg></templarg>
    <templarg>Func</templarg>
    <base>rcppsw::patterns::fsm::state_exit</base>
    <member kind="function">
      <type></type>
      <name>~state_exit_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__exit__action.html</anchorfile>
      <anchor>ae5fc3e2e8b3511cb7d1660784dd2e444</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>invoke_exit_action</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__exit__action.html</anchorfile>
      <anchor>a41ec770cde01a270ae71041870421b36</anchor>
      <arglist>(base_fsm *sm) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_guard</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__guard.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~state_guard</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__guard.html</anchorfile>
      <anchor>ae53d9b86decff789563840ca8255a862</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>invoke_guard_condition</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__guard.html</anchorfile>
      <anchor>ab4fc458dfd439257b0439a070bc59716</anchor>
      <arglist>(base_fsm *sm, const event_data *) const =0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_guard_condition0</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__guard__condition0.html</filename>
    <templarg></templarg>
    <templarg>Func</templarg>
    <base>rcppsw::patterns::fsm::state_guard</base>
    <member kind="function">
      <type></type>
      <name>~state_guard_condition0</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__guard__condition0.html</anchorfile>
      <anchor>aa452b2ff90fdd595e2568c1f9247af08</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>invoke_guard_condition</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__guard__condition0.html</anchorfile>
      <anchor>a571228012b8298330b5cb12d282ee8a6</anchor>
      <arglist>(base_fsm *sm, const event_data *) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_guard_condition1</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__guard__condition1.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <templarg>Func</templarg>
    <base>rcppsw::patterns::fsm::state_guard</base>
    <member kind="function">
      <type></type>
      <name>~state_guard_condition1</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__guard__condition1.html</anchorfile>
      <anchor>add75eefd014290c710ad3a8ad4d6daf2</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>invoke_guard_condition</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__guard__condition1.html</anchorfile>
      <anchor>a68932eb848f27d91363aed9ab0a4704a</anchor>
      <arglist>(base_fsm *sm, const event_data *data) const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_map_ex_row</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__map__ex__row.html</filename>
    <member kind="function">
      <type></type>
      <name>state_map_ex_row</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__map__ex__row.html</anchorfile>
      <anchor>a3f12521926833f45a8c5806980744256</anchor>
      <arglist>(rpfsm::state *state, state_guard *guard, state_entry *entry, state_exit *exit)</arglist>
    </member>
    <member kind="function">
      <type>state_entry *</type>
      <name>entry</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__map__ex__row.html</anchorfile>
      <anchor>a891e65cec8dd652b6d3f65484dd25013</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>state_exit *</type>
      <name>exit</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__map__ex__row.html</anchorfile>
      <anchor>a411ebeadb97da33dcfed108abc3a9818</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>state_guard *</type>
      <name>guard</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__map__ex__row.html</anchorfile>
      <anchor>a7bac8679563abd28f33a1fe5cdbbf30c</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>rpfsm::state *</type>
      <name>state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__map__ex__row.html</anchorfile>
      <anchor>a0f1990024a86b7f362767ad25e031d12</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::fsm::state_map_row</name>
    <filename>classrcppsw_1_1patterns_1_1fsm_1_1state__map__row.html</filename>
    <member kind="function">
      <type></type>
      <name>state_map_row</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__map__row.html</anchorfile>
      <anchor>ae9001a4195e58d0baa3a9f0551b5755f</anchor>
      <arglist>(rcppsw::patterns::fsm::state *state)</arglist>
    </member>
    <member kind="function">
      <type>rcppsw::patterns::fsm::state *</type>
      <name>state</name>
      <anchorfile>classrcppsw_1_1patterns_1_1fsm_1_1state__map__row.html</anchorfile>
      <anchor>ab12e8da584c1539ae75bb449e7a60c4b</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::pimpl::pimpl</name>
    <filename>structrcppsw_1_1patterns_1_1pimpl_1_1pimpl.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>pimpl</name>
      <anchorfile>structrcppsw_1_1patterns_1_1pimpl_1_1pimpl.html</anchorfile>
      <anchor>aab9d5df949565f14f078392e4e06031f</anchor>
      <arglist>(Args &amp;&amp;... args)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~pimpl</name>
      <anchorfile>structrcppsw_1_1patterns_1_1pimpl_1_1pimpl.html</anchorfile>
      <anchor>ab2b1961b68805d2638e37df2e397bdb4</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="variable">
      <type>std::unique_ptr&lt; TImpl &gt;</type>
      <name>impl</name>
      <anchorfile>structrcppsw_1_1patterns_1_1pimpl_1_1pimpl.html</anchorfile>
      <anchor>ac96d3d30a82efc2ba646ef49fa71d73b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::prototype::caching_factory</name>
    <filename>classrcppsw_1_1patterns_1_1prototype_1_1caching__factory.html</filename>
    <templarg></templarg>
    <templarg>Args</templarg>
    <member kind="function">
      <type>TBase *</type>
      <name>create</name>
      <anchorfile>classrcppsw_1_1patterns_1_1prototype_1_1caching__factory.html</anchorfile>
      <anchor>a4bab8f07f5cf01ee0652c3c3c42aba52</anchor>
      <arglist>(const std::string &amp;name, Args... args)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>register_type</name>
      <anchorfile>classrcppsw_1_1patterns_1_1prototype_1_1caching__factory.html</anchorfile>
      <anchor>afc718b5957ca25141ce476ad792f5ce2</anchor>
      <arglist>(const std::string &amp;name)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::prototype::clonable</name>
    <filename>classrcppsw_1_1patterns_1_1prototype_1_1clonable.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>clonable</name>
      <anchorfile>classrcppsw_1_1patterns_1_1prototype_1_1clonable.html</anchorfile>
      <anchor>a9685eea9186584a14c426c44d757dd69</anchor>
      <arglist>(const clonable &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>clonable</name>
      <anchorfile>classrcppsw_1_1patterns_1_1prototype_1_1clonable.html</anchorfile>
      <anchor>a8f14f762f8570d0ea3cb27d2d0784642</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~clonable</name>
      <anchorfile>classrcppsw_1_1patterns_1_1prototype_1_1clonable.html</anchorfile>
      <anchor>a63c8bd02f1a9701eb87963043dea17b9</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::unique_ptr&lt; T &gt;</type>
      <name>clone</name>
      <anchorfile>classrcppsw_1_1patterns_1_1prototype_1_1clonable.html</anchorfile>
      <anchor>a777274bf47dba8ae03529bf7ac1fc936</anchor>
      <arglist>(void) const =0</arglist>
    </member>
    <member kind="function">
      <type>clonable &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1prototype_1_1clonable.html</anchorfile>
      <anchor>abb7c5101a6cb0452cb8c7973c89b543d</anchor>
      <arglist>(const clonable &amp;)=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::singleton::singleton</name>
    <filename>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a1a4420728a87f18d237d14a9fbb8a8bd</anchor>
      <arglist>(singleton &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a7c6f169aa093f4606aa656d5a01cdcac</anchor>
      <arglist>(singleton const &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>singleton &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>aefa0b0e4d0dba612e0db004016b1a0ef</anchor>
      <arglist>(singleton &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>singleton &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>afe5efa34b5fc04803e8c3583ec255317</anchor>
      <arglist>(singleton const &amp;)=delete</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static T &amp;</type>
      <name>instance</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a080214d86ac9c51f69da83a896d331e8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a91423fa6a5a9062bbfc1c1c7162e4a64</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>~singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a867cf961a5992f3555d6c7273f04137f</anchor>
      <arglist>(void)=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::visitor::detail::polymorphic_accept_set_helper</name>
    <filename>classrcppsw_1_1patterns_1_1visitor_1_1detail_1_1polymorphic__accept__set__helper.html</filename>
    <templarg></templarg>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~polymorphic_accept_set_helper</name>
      <anchorfile>classrcppsw_1_1patterns_1_1visitor_1_1detail_1_1polymorphic__accept__set__helper.html</anchorfile>
      <anchor>a6bedb556cb2eb54ee8963c0740990029</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>accept</name>
      <anchorfile>classrcppsw_1_1patterns_1_1visitor_1_1detail_1_1polymorphic__accept__set__helper.html</anchorfile>
      <anchor>ad681ab3094fe51fbc422c1c5d39d44a5</anchor>
      <arglist>(T &amp;visitor)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::patterns::visitor::detail::visit_set_helper</name>
    <filename>classrcppsw_1_1patterns_1_1visitor_1_1detail_1_1visit__set__helper.html</filename>
    <templarg></templarg>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~visit_set_helper</name>
      <anchorfile>classrcppsw_1_1patterns_1_1visitor_1_1detail_1_1visit__set__helper.html</anchorfile>
      <anchor>a46b1de9a0c5ebe2d62e230f6d1c965aa</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>visit</name>
      <anchorfile>classrcppsw_1_1patterns_1_1visitor_1_1detail_1_1visit__set__helper.html</anchorfile>
      <anchor>ab278cb93b0fb1a064a6dae7340921b74</anchor>
      <arglist>(T &amp;visitee)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::types::distance_measure</name>
    <filename>classrcppsw_1_1types_1_1distance__measure.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <base>named_type&lt; T, Tag &gt;</base>
    <base>client&lt; distance_measure&lt; T, Tag &gt; &gt;</base>
    <member kind="typedef">
      <type>T</type>
      <name>value_type</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>aea4a37b0610e8c0aafd27b41d60278d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>distance_measure</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a8b9eabce8e4ef1226385264a358f7467</anchor>
      <arglist>(const distance_measure &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>distance_measure</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a1a2df64630ac102d9d432373922e0900</anchor>
      <arglist>(const T &amp;value, bool check_psd=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~distance_measure</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a90138f34ada5eb86657b6fb869d07bb5</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a4c1fef0674c235cd8523abb84047654e</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a174ee7f7675692e22288c07948a4b8b6</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a119ce1e7927cd4ad28c6ed556fc6269a</anchor>
      <arglist>(T rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>a313e22de24f4a672f66da8e593aa7425</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>ae5abceecbe8e7ee73a12142c080bb4c9</anchor>
      <arglist>(T rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>aa9ba96ab2957ce3cdad5857c55fc097d</anchor>
      <arglist>(const distance_measure &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1distance__measure.html</anchorfile>
      <anchor>afebaafc7a799abb0b72e086d9f06a2a6</anchor>
      <arglist>(T rhs) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::types::manhattan_dist</name>
    <filename>classrcppsw_1_1types_1_1manhattan__dist.html</filename>
    <base>distance_measure&lt; int, struct manhattan_dist_tag &gt;</base>
    <member kind="function">
      <type></type>
      <name>manhattan_dist</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>a29f075442496a4687e14234d8793a859</anchor>
      <arglist>(const int &amp;v, bool check_psd=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>manhattan_dist</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>aa81f2a1594dbbe78da3b16eb928f9b39</anchor>
      <arglist>(const manhattan_dist &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~manhattan_dist</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>a648004842e8c96ff03cb97a2cebfd71a</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator*</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>a0474e2dfbb19167b1a2a2107c4097286</anchor>
      <arglist>(const manhattan_dist &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator*</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>affb2cadaaaac0d2576669a5e4bd3ed75</anchor>
      <arglist>(int rhs) const</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>ab8ff728cc820c48178aacd2852e9698d</anchor>
      <arglist>(const manhattan_dist &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>aa424686a052fab9f5028b421498beaa4</anchor>
      <arglist>(int rhs) const</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>a24e6b397cd8446197c6beb79b396f888</anchor>
      <arglist>(const manhattan_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>a40497f6b805c9af1c4cde2737d78d75d</anchor>
      <arglist>(const manhattan_dist &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>aadb5cd8a4d696f2a26eff5caf5b850b6</anchor>
      <arglist>(int rhs) const</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist &amp;</type>
      <name>operator-=</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>a2a630779a4f82efa4c075957dc10618f</anchor>
      <arglist>(int rhs)</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>a735df41ed8f60c276dc873ccd98dd567</anchor>
      <arglist>(const manhattan_dist &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>a28b6d8e450468d387a6280967a768fd6</anchor>
      <arglist>(int rhs) const</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>ad2b82a03e08cd3d81b8ad680279b1279</anchor>
      <arglist>(const manhattan_dist &amp;rhs)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static manhattan_dist</type>
      <name>make</name>
      <anchorfile>classrcppsw_1_1types_1_1manhattan__dist.html</anchorfile>
      <anchor>a6ea2f9c8352ee2b5b0dbbd0cc9e0f313</anchor>
      <arglist>(const int &amp;value)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::types::named_type</name>
    <filename>classrcppsw_1_1types_1_1named__type.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <base>rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a45531d5cc915d48d5132f711dfb5541b</anchor>
      <arglist>(T const &amp;value) noexcept</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~named_type</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ad2fd23fa3879f2cfd77c5ad9c65b9a57</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>set</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ae3adaef7b9d236a163a83fdfc2e8a5c8</anchor>
      <arglist>(const T &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a5be785b00b2a79f27ede7953446c9bad</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>v</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>ab5e5d9c79710dbd92eea31dbe0357de5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>a61be9ff951c2a54898fc3e0d6037adcc</anchor>
      <arglist>(std::ostream &amp;stream, const named_type &amp;c_type)</arglist>
    </member>
    <member kind="friend">
      <type>friend std::istream &amp;</type>
      <name>operator&gt;&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1named__type.html</anchorfile>
      <anchor>afea5f975654f3c41ef3eb12cec92914d</anchor>
      <arglist>(std::istream &amp;stream, named_type &amp;n)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::types::spatial_dist</name>
    <filename>classrcppsw_1_1types_1_1spatial__dist.html</filename>
    <base>distance_measure&lt; double, struct spatial_dist_tag &gt;</base>
    <member kind="function">
      <type></type>
      <name>spatial_dist</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>a887596d1cb23279dcd1d7dc99c9ce64e</anchor>
      <arglist>(const double &amp;v)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>spatial_dist</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>a08fb715aaca1ebbfd356e3c31f189bcc</anchor>
      <arglist>(const spatial_dist &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~spatial_dist</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>aa4c4fa45b80a4d8c6db532ba002e4fb0</anchor>
      <arglist>(void) override=default</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator*</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>af3d605d6b5a324235634f68423f77454</anchor>
      <arglist>(const spatial_dist &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator*</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>a4ebbe2a13a1cfa896aceb4bd949995da</anchor>
      <arglist>(double rhs) const</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>abf23970ff98c35f9db3f2a6fb1e53423</anchor>
      <arglist>(const spatial_dist &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>ac5178c200d42b19d86b0a17bc7c4cc84</anchor>
      <arglist>(double rhs) const</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>aa6bf23f3b956e01dbb3a1e2ec11de8fd</anchor>
      <arglist>(const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>afadf0b87509f903dba2023c45c71a2b3</anchor>
      <arglist>(const spatial_dist &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>ad623c1e1b4e8f4790ccb5c9d93dc062c</anchor>
      <arglist>(double rhs) const</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist &amp;</type>
      <name>operator-=</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>ac32f75b75c298829c4e750d2732a68b3</anchor>
      <arglist>(double rhs)</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>af6eff1d573a2e3588f8fba702218e80d</anchor>
      <arglist>(const spatial_dist &amp;rhs) const</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator/</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>a51bb9e6a2f6c366c80cb1b02417d647e</anchor>
      <arglist>(double rhs) const</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>a3628c7006b56b285487d0460e9605c9b</anchor>
      <arglist>(const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static spatial_dist</type>
      <name>make</name>
      <anchorfile>classrcppsw_1_1types_1_1spatial__dist.html</anchorfile>
      <anchor>ac9c8ad41267f2b62636cd9467186c0fd</anchor>
      <arglist>(const double &amp;value)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::types::timestep</name>
    <filename>classrcppsw_1_1types_1_1timestep.html</filename>
    <base>named_type&lt; size_t, struct timestep_tag &gt;</base>
    <member kind="function">
      <type></type>
      <name>timestep</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a4fdc5392074ed843db261df74149a700</anchor>
      <arglist>(const timestep &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>timestep</type>
      <name>operator%</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>affe7cfce414d59f72f432af438c6e17f</anchor>
      <arglist>(const timestep &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>timestep</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a4602591eefbb62ce1dfc32d3529f2124</anchor>
      <arglist>(const timestep &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>timestep</type>
      <name>operator+</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>adecd92bf3692d96d46c2b48304bc17bd</anchor>
      <arglist>(size_t n) const</arglist>
    </member>
    <member kind="function">
      <type>timestep &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a880fabd3c6d2e5a75bc0c9f7b576aa9c</anchor>
      <arglist>(const timestep &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>timestep &amp;</type>
      <name>operator+=</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a9c7ffc46d25eccd895dc94a4e40a0bb9</anchor>
      <arglist>(size_t n)</arglist>
    </member>
    <member kind="function">
      <type>timestep</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a24660d10a678ec880594159efd0c6ea4</anchor>
      <arglist>(const timestep &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>timestep</type>
      <name>operator-</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a33a0eb6636e7c077b6bcce1562990af8</anchor>
      <arglist>(size_t n) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a22369560bcf26f7469759f34e4c4af80</anchor>
      <arglist>(const T &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>ae404aef7a0274eeda44bf132c52b03d0</anchor>
      <arglist>(const timestep &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>timestep &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a2ccc0cba158cbb4e0a5d224eec44c693</anchor>
      <arglist>(const timestep &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a026ed5ea81d076a73ce57c987166c0a2</anchor>
      <arglist>(const T &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>ab0144b8bd5d3cbaab63e72ea4a1d87b3</anchor>
      <arglist>(const timestep &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a581a2b5b041f98439e710dd2765e82c0</anchor>
      <arglist>(const T &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>ae9819e0c5739c0ca21fe47c6dd253d6b</anchor>
      <arglist>(const timestep &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>ad22cb5899d66b737b21e6b535a3d16d7</anchor>
      <arglist>(const T &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classrcppsw_1_1types_1_1timestep.html</anchorfile>
      <anchor>a1dbd62eab324df350e0c99401ec8bc73</anchor>
      <arglist>(const timestep &amp;other) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::utils::base_cli</name>
    <filename>classrcppsw_1_1utils_1_1base__cli.html</filename>
    <member kind="function">
      <type></type>
      <name>base_cli</name>
      <anchorfile>classrcppsw_1_1utils_1_1base__cli.html</anchorfile>
      <anchor>a3424a155f9bb0f727958244b65136d7f</anchor>
      <arglist>(const std::string &amp;mnemonic=&quot;&quot;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~base_cli</name>
      <anchorfile>classrcppsw_1_1utils_1_1base__cli.html</anchorfile>
      <anchor>afaef0b6cca6f61adcb2085d5601d9915</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>bpo::options_description *</type>
      <name>desc</name>
      <anchorfile>classrcppsw_1_1utils_1_1base__cli.html</anchorfile>
      <anchor>a09d0b7b6202e3f2d631c322453bd1ffa</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>status_t</type>
      <name>parse</name>
      <anchorfile>classrcppsw_1_1utils_1_1base__cli.html</anchorfile>
      <anchor>a365b9d4a1cda3766c4b2966986eabd53</anchor>
      <arglist>(int argc, char **argv)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>print</name>
      <anchorfile>classrcppsw_1_1utils_1_1base__cli.html</anchorfile>
      <anchor>a4ca33620ef34f2f572be84bf8750110f</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>prog_name</name>
      <anchorfile>classrcppsw_1_1utils_1_1base__cli.html</anchorfile>
      <anchor>a75bc985d3cb5b9ccf5b91c1a8ca42a31</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>validate</name>
      <anchorfile>classrcppsw_1_1utils_1_1base__cli.html</anchorfile>
      <anchor>aa92da8272f44010d76970ef2ce2c7551</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const bpo::variables_map &amp;</type>
      <name>vm</name>
      <anchorfile>classrcppsw_1_1utils_1_1base__cli.html</anchorfile>
      <anchor>a08d227d102563a23cf7f3d6bb56dc933</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::utils::color</name>
    <filename>classrcppsw_1_1utils_1_1color.html</filename>
    <base>rcppsw::er::stringizable</base>
    <member kind="function">
      <type></type>
      <name>color</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a72b000429b44d72712102b1ab1dcbc4d</anchor>
      <arglist>(const color &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>color</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>acb05fb4367e48c4d80131fa22bff9c8f</anchor>
      <arglist>(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>color</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a760814e4557f9a1ed936950be0f96c91</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>alpha</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a8c04ca0d31be2cde6b5f82266baefc38</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>alpha</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>af3e8d0eefc1e8711854a47fe96029366</anchor>
      <arglist>(uint8_t alpha)</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>blue</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a6eb4cd25dc99e510931d6b70e552a0f6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>blue</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a369bc027d2eb39e59d98fe174aff916e</anchor>
      <arglist>(uint8_t blue)</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>green</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>ab02424227508af2e8c8afbd967172bd2</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>green</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a1f54f4b8f752df8ebcf05e0aea1928e1</anchor>
      <arglist>(uint8_t green)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>aa014b71a4cf2715cd9fb425cdae3e721</anchor>
      <arglist>(const color &amp;c_color2) const</arglist>
    </member>
    <member kind="function">
      <type>color &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a8724d21e3fa28905b1d4f6913ae2ebe3</anchor>
      <arglist>(const color &amp;)=default</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a8bbda303f6428d493465628eeb13a6a1</anchor>
      <arglist>(const color &amp;c_color2) const</arglist>
    </member>
    <member kind="function">
      <type>uint8_t</type>
      <name>red</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>aaa67de22e38a997687e0ef74020c601c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>red</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a6d5d089d69dec861136c7db4ceb0ebb6</anchor>
      <arglist>(uint8_t red)</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_str</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a2fde472bf5988d8be1aa27fb82e42199</anchor>
      <arglist>(void) const override</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kBLACK</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a43f1f53ecd05b56843d3738007450ddc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kBLUE</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>afe38b3f08ef1e1aba9221640d09edb17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kBROWN</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>aa29d21a45c10fc95e3f99344157449dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kCYAN</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>ab29a9d0cd873ec791385528044d7841c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGRAY10</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a91aa5a4b8f7b16393d645e9a43a2ba47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGRAY20</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>ac1ad79909fe4f47823f4c97addf79a25</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGRAY30</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>ab8a47a5dc3bcdf8a58d772608f7a99d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGRAY40</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a27736622de0229f6ada7eb659d079a70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGRAY50</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a771dc9b3875d55be647e3969d6b52ce6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGRAY60</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a1e66c808aa0f68e9b57154c965b28dfb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGRAY70</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a54405239143717a254436bd289ea5822</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGRAY80</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>a31d78077433be73c2cf7bbce34078886</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGRAY90</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>ab7b09fa6cbfb5673279bbc5152ed86ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kGREEN</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>afc100cfbaf9d43890491ca94fb0f1467</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kMAGENTA</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>ab53b155c72ea451c1462ef9b1f6b8fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kORANGE</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>ae2478bca34c664ee01d43078684a3a94</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kPURPLE</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>ac7f5d9b0171253ed66b5819d90d832a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kRED</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>aab4b755e0c5e87994773471696d160e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kWHITE</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>aca413c780ac543f1f0c02751ab56a08e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const color</type>
      <name>kYELLOW</name>
      <anchorfile>classrcppsw_1_1utils_1_1color.html</anchorfile>
      <anchor>ab900ab14a2ac2b9bc8f31bdf70fbca29</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::utils::file_parser</name>
    <filename>classrcppsw_1_1utils_1_1file__parser.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>file_parser</name>
      <anchorfile>classrcppsw_1_1utils_1_1file__parser.html</anchorfile>
      <anchor>a12dd3cb3d6d026312c3ab949ad36f15a</anchor>
      <arglist>(const std::string &amp;fname)</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; T &gt; *</type>
      <name>parse_file</name>
      <anchorfile>classrcppsw_1_1utils_1_1file__parser.html</anchorfile>
      <anchor>a57c3cd88e7a3a42f62045578d8c77f96</anchor>
      <arglist>(char delim)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rcppsw::utils::line_parser</name>
    <filename>classrcppsw_1_1utils_1_1line__parser.html</filename>
    <member kind="function">
      <type></type>
      <name>line_parser</name>
      <anchorfile>classrcppsw_1_1utils_1_1line__parser.html</anchorfile>
      <anchor>ae4a861a4a4136e2c676e55da681fbb12</anchor>
      <arglist>(char delim)</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; std::string &gt;</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1utils_1_1line__parser.html</anchorfile>
      <anchor>a1d1209243bc995944e6841cba8ec4bd2</anchor>
      <arglist>(const std::string &amp;line) const</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; std::string &gt;</type>
      <name>operator()</name>
      <anchorfile>classrcppsw_1_1utils_1_1line__parser.html</anchorfile>
      <anchor>ab46d9ab2e0502d17edeae098c3e9f403</anchor>
      <arglist>(std::stringstream &amp;ss) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static std::vector&lt; T &gt;</type>
      <name>as</name>
      <anchorfile>classrcppsw_1_1utils_1_1line__parser.html</anchorfile>
      <anchor>a5a1e25cc600f5b5185a606ef0442d943</anchor>
      <arglist>(const std::vector&lt; std::string &gt; &amp;v)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>releasing_factory&lt; base_waveform, std::string, const config::waveform_config * &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1releasing__factory.html</filename>
    <base>base_factory&lt; detail::factory_releasing_type, std::unique_ptr, base_waveform, std::string, Args... &gt;</base>
    <member kind="function">
      <type></type>
      <name>~releasing_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1releasing__factory.html</anchorfile>
      <anchor>a931a4c9130d95d9158243580f7b48ace</anchor>
      <arglist>(void) override=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>releasing_multifactory</name>
    <filename>classreleasing__multifactory.html</filename>
    <templarg></templarg>
    <templarg>Args</templarg>
    <member kind="function">
      <type></type>
      <name>~releasing_multifactory</name>
      <anchorfile>classreleasing__multifactory.html</anchorfile>
      <anchor>a2969ee382cf6c770587b6a90eb91a061</anchor>
      <arglist>(void) override=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>rng</name>
    <filename>classrng.html</filename>
    <member kind="function">
      <type></type>
      <name>rng</name>
      <anchorfile>classrng.html</anchorfile>
      <anchor>a66941b058dcc602e2d80b7efddb061b1</anchor>
      <arglist>(size_t seed)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~rng</name>
      <anchorfile>classrng.html</anchorfile>
      <anchor>ab18cfec8df971f3778552ddc78cb24fc</anchor>
      <arglist>(void) override</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>bernoulli</name>
      <anchorfile>classrng.html</anchorfile>
      <anchor>a2c502c6565aac52db7ff9283201b494e</anchor>
      <arglist>(double p)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>exponential</name>
      <anchorfile>classrng.html</anchorfile>
      <anchor>a87be3fc53217acb4049c6f8dedde1d0e</anchor>
      <arglist>(double lambda)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>gaussian</name>
      <anchorfile>classrng.html</anchorfile>
      <anchor>aba86d0fa8248a60eaea060f871a14423</anchor>
      <arglist>(double mean, double std_dev)</arglist>
    </member>
    <member kind="function">
      <type>size_t</type>
      <name>seed</name>
      <anchorfile>classrng.html</anchorfile>
      <anchor>a2534cb52709dee8305640c950b24c4ff</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>uniform</name>
      <anchorfile>classrng.html</anchorfile>
      <anchor>a0fb53333f775ca28cd68c1033fc94773</anchor>
      <arglist>(const range&lt; T &gt; &amp;c_range)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>uniform</name>
      <anchorfile>classrng.html</anchorfile>
      <anchor>a5ed45300bbf2358aa5f024dee1baa0ea</anchor>
      <arglist>(const T &amp;lb, const T &amp;ub)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>sharing_factory&lt; rng, std::string, Args... &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1sharing__factory.html</filename>
    <base>base_factory&lt; detail::factory_sharing_type, std::shared_ptr, rng, std::string, Args... &gt;</base>
    <member kind="function">
      <type></type>
      <name>~sharing_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1sharing__factory.html</anchorfile>
      <anchor>a4a72638b4415afc7384536d8074d2990</anchor>
      <arglist>(void) override=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>sharing_factory&lt; TBase, std::string, Args... &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1sharing__factory.html</filename>
    <base>base_factory&lt; detail::factory_sharing_type, std::shared_ptr, TBase, std::string, Args... &gt;</base>
    <member kind="function">
      <type></type>
      <name>~sharing_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1sharing__factory.html</anchorfile>
      <anchor>a4a72638b4415afc7384536d8074d2990</anchor>
      <arglist>(void) override=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>sharing_factory&lt; xml_config_parser, std::string &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1factory_1_1sharing__factory.html</filename>
    <base>base_factory&lt; detail::factory_sharing_type, std::shared_ptr, xml_config_parser, std::string, Args... &gt;</base>
    <member kind="function">
      <type></type>
      <name>~sharing_factory</name>
      <anchorfile>classrcppsw_1_1patterns_1_1factory_1_1sharing__factory.html</anchorfile>
      <anchor>a4a72638b4415afc7384536d8074d2990</anchor>
      <arglist>(void) override=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>sharing_multifactory</name>
    <filename>classsharing__multifactory.html</filename>
    <templarg></templarg>
    <templarg>Args</templarg>
    <member kind="function">
      <type></type>
      <name>~sharing_multifactory</name>
      <anchorfile>classsharing__multifactory.html</anchorfile>
      <anchor>a848bd948b13cd074c4bb3aedf8711d09</anchor>
      <arglist>(void) override=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>singleton&lt; base_factory&lt; TType, std::unique_ptr, TBase, Args... &gt; &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</filename>
    <member kind="function">
      <type></type>
      <name>singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a1a4420728a87f18d237d14a9fbb8a8bd</anchor>
      <arglist>(singleton &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a7c6f169aa093f4606aa656d5a01cdcac</anchor>
      <arglist>(singleton const &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>singleton &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>aefa0b0e4d0dba612e0db004016b1a0ef</anchor>
      <arglist>(singleton &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>singleton &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>afe5efa34b5fc04803e8c3583ec255317</anchor>
      <arglist>(singleton const &amp;)=delete</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static base_factory&lt; TType, std::unique_ptr, TBase, Args... &gt; &amp;</type>
      <name>instance</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a080214d86ac9c51f69da83a896d331e8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a91423fa6a5a9062bbfc1c1c7162e4a64</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>~singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a867cf961a5992f3555d6c7273f04137f</anchor>
      <arglist>(void)=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>singleton&lt; rngm &gt;</name>
    <filename>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</filename>
    <member kind="function">
      <type></type>
      <name>singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a1a4420728a87f18d237d14a9fbb8a8bd</anchor>
      <arglist>(singleton &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a7c6f169aa093f4606aa656d5a01cdcac</anchor>
      <arglist>(singleton const &amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>singleton &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>aefa0b0e4d0dba612e0db004016b1a0ef</anchor>
      <arglist>(singleton &amp;&amp;)=delete</arglist>
    </member>
    <member kind="function">
      <type>singleton &amp;</type>
      <name>operator=</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>afe5efa34b5fc04803e8c3583ec255317</anchor>
      <arglist>(singleton const &amp;)=delete</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rngm &amp;</type>
      <name>instance</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a080214d86ac9c51f69da83a896d331e8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a91423fa6a5a9062bbfc1c1c7162e4a64</anchor>
      <arglist>(void)=default</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>~singleton</name>
      <anchorfile>classrcppsw_1_1patterns_1_1singleton_1_1singleton.html</anchorfile>
      <anchor>a867cf961a5992f3555d6c7273f04137f</anchor>
      <arglist>(void)=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>visit_set</name>
    <filename>visitor_8hpp.html</filename>
    <anchor>classvisit__set</anchor>
    <templarg>Ts</templarg>
  </compound>
  <compound kind="class">
    <name>visit_set&lt; T &gt;</name>
    <filename>classvisit__set_3_01T_01_4.html</filename>
    <templarg></templarg>
  </compound>
  <compound kind="class">
    <name>visit_set&lt; T, Ts... &gt;</name>
    <filename>classvisit__set_3_01T_00_01Ts_8_8_8_01_4.html</filename>
    <templarg></templarg>
    <templarg>Ts</templarg>
    <base>visit_set&lt; Ts... &gt;</base>
  </compound>
  <compound kind="class">
    <name>visit_set&lt; Ts... &gt;</name>
    <filename>visitor_8hpp.html</filename>
  </compound>
  <compound kind="namespace">
    <name>rcppsw</name>
    <filename>namespacercppsw.html</filename>
    <namespace>rcppsw::al</namespace>
    <namespace>rcppsw::algorithm</namespace>
    <namespace>rcppsw::config</namespace>
    <namespace>rcppsw::control</namespace>
    <namespace>rcppsw::detail</namespace>
    <namespace>rcppsw::ds</namespace>
    <namespace>rcppsw::er</namespace>
    <namespace>rcppsw::math</namespace>
    <namespace>rcppsw::metrics</namespace>
    <namespace>rcppsw::mpl</namespace>
    <namespace>rcppsw::multiprocess</namespace>
    <namespace>rcppsw::multithread</namespace>
    <namespace>rcppsw::patterns</namespace>
    <namespace>rcppsw::types</namespace>
    <namespace>rcppsw::utils</namespace>
    <member kind="function">
      <type>constexpr std::underlying_type&lt; TEnum &gt;::type</type>
      <name>as_underlying</name>
      <anchorfile>namespacercppsw.html</anchorfile>
      <anchor>a8947a64dc8b866fbf1b0e47526552828</anchor>
      <arglist>(const TEnum &amp;e) noexcept</arglist>
    </member>
    <member kind="function">
      <type>std::string</type>
      <name>to_string</name>
      <anchorfile>namespacercppsw.html</anchorfile>
      <anchor>a067e7fdc1e45476ca82cb106d0809015</anchor>
      <arglist>(const T &amp;obj)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::al</name>
    <filename>namespacercppsw_1_1al.html</filename>
    <member kind="typedef">
      <type>double</type>
      <name>mt_double_t</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>a120235a88ff5b87aecc2b6671e2aa34d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::size_t</type>
      <name>mt_size_t</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>adde22a9fc824f252937cfda2ceca8b18</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mt_add</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>a2b2f1a1104dd40f0ba23f12ad48ed8df</anchor>
      <arglist>(U &amp;lhs, const V &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mt_init</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>a9c316463739f65c5fc7994d9e38e96f7</anchor>
      <arglist>(LHS *lhs, RHS rhs)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>mt_load</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>aa2cfd83ab696496e080e73a168e31c21</anchor>
      <arglist>(const T &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mt_set</name>
      <anchorfile>namespacercppsw_1_1al.html</anchorfile>
      <anchor>a34ba8f4c71fd6d74cc9b1a2f70a47340</anchor>
      <arglist>(U &amp;lhs, const V &amp;rhs)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::algorithm</name>
    <filename>namespacercppsw_1_1algorithm.html</filename>
    <namespace>rcppsw::algorithm::clustering</namespace>
    <class kind="class">rcppsw::algorithm::closest_pair2D</class>
    <class kind="class">rcppsw::algorithm::convex_hull2D</class>
    <class kind="class">rcppsw::algorithm::max_subarray_finder</class>
    <class kind="struct">rcppsw::algorithm::result_type2D</class>
    <member kind="function">
      <type>OutputIterator</type>
      <name>transform_if</name>
      <anchorfile>namespacercppsw_1_1algorithm.html</anchorfile>
      <anchor>a708f58ee6c37c53495f944f28499ea28</anchor>
      <arglist>(InputIterator first, InputIterator last, OutputIterator result, const Predicate &amp;pred, const UnaryFunction &amp;f)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::algorithm::clustering</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering.html</filename>
    <namespace>rcppsw::algorithm::clustering::cluster</namespace>
    <namespace>rcppsw::algorithm::clustering::membership</namespace>
    <namespace>rcppsw::algorithm::clustering::policy</namespace>
    <class kind="interface">rcppsw::algorithm::clustering::base_clustering_impl</class>
    <class kind="class">rcppsw::algorithm::clustering::eh_cluster</class>
    <class kind="interface">rcppsw::algorithm::clustering::eh_clustering_impl</class>
    <class kind="class">rcppsw::algorithm::clustering::entropy_balch2000</class>
    <class kind="class">rcppsw::algorithm::clustering::entropy_eh_omp</class>
    <class kind="class">rcppsw::algorithm::clustering::kmeans</class>
    <class kind="class">rcppsw::algorithm::clustering::kmeans_omp</class>
    <class kind="class">rcppsw::algorithm::clustering::nc_cluster</class>
    <member kind="typedef">
      <type>typename membership::mapping&lt; Policy &gt;::type</type>
      <name>membership_type</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering.html</anchorfile>
      <anchor>ae4bdc3c1b255447703e70a19e7c90aef</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::algorithm::clustering::cluster</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1cluster.html</filename>
    <class kind="struct">rcppsw::algorithm::clustering::cluster::mapping</class>
    <class kind="struct">rcppsw::algorithm::clustering::cluster::mapping&lt; T, Policy, policy::is_eh&lt; Policy &gt; &gt;</class>
    <class kind="struct">rcppsw::algorithm::clustering::cluster::mapping&lt; T, Policy, policy::is_nc&lt; Policy &gt; &gt;</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::algorithm::clustering::membership</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1membership.html</filename>
    <class kind="struct">rcppsw::algorithm::clustering::membership::mapping</class>
    <class kind="struct">rcppsw::algorithm::clustering::membership::mapping&lt; Policy, policy::is_eh&lt; Policy &gt; &gt;</class>
    <class kind="struct">rcppsw::algorithm::clustering::membership::mapping&lt; Policy, policy::is_nc&lt; Policy &gt; &gt;</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::algorithm::clustering::policy</name>
    <filename>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</filename>
    <class kind="class">rcppsw::algorithm::clustering::policy::EH</class>
    <class kind="class">rcppsw::algorithm::clustering::policy::NC</class>
    <member kind="typedef">
      <type>typename std::enable_if_t&lt; is_eh_&lt; Policy &gt;::value &gt;</type>
      <name>is_eh</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</anchorfile>
      <anchor>a93e2541d4b7b87c962aa26a820961171</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::is_same&lt; Policy, EH &gt;</type>
      <name>is_eh_</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</anchorfile>
      <anchor>ae00d598179a3129379523bc8225148d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename std::enable_if_t&lt; is_nc_&lt; Policy &gt;::value &gt;</type>
      <name>is_nc</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</anchorfile>
      <anchor>a6ad2a498aaa8af4df9552dc8a64c81bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::is_same&lt; Policy, NC &gt;</type>
      <name>is_nc_</name>
      <anchorfile>namespacercppsw_1_1algorithm_1_1clustering_1_1policy.html</anchorfile>
      <anchor>ad73f8261d3fab385cbd1cf263d937e6f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::config</name>
    <filename>namespacercppsw_1_1config.html</filename>
    <namespace>rcppsw::config::xml</namespace>
    <class kind="struct">rcppsw::config::base_config</class>
    <class kind="class">rcppsw::config::streamable_parser</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::config::xml</name>
    <filename>namespacercppsw_1_1config_1_1xml.html</filename>
    <class kind="class">rcppsw::config::xml::xml_config_repository</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::control</name>
    <filename>namespacercppsw_1_1control.html</filename>
    <namespace>rcppsw::control::config</namespace>
    <class kind="class">rcppsw::control::base_waveform</class>
    <class kind="class">rcppsw::control::constant_waveform</class>
    <class kind="class">rcppsw::control::null_waveform</class>
    <class kind="class">rcppsw::control::pid_loop</class>
    <class kind="class">rcppsw::control::sawtooth_waveform</class>
    <class kind="class">rcppsw::control::sine_waveform</class>
    <class kind="class">rcppsw::control::square_waveform</class>
    <class kind="class">rcppsw::control::waveform_generator</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::control::config</name>
    <filename>namespacercppsw_1_1control_1_1config.html</filename>
    <namespace>rcppsw::control::config::xml</namespace>
    <class kind="struct">rcppsw::control::config::waveform_config</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::control::config::xml</name>
    <filename>namespacercppsw_1_1control_1_1config_1_1xml.html</filename>
    <class kind="class">rcppsw::control::config::xml::waveform_parser</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::detail</name>
    <filename>namespacercppsw_1_1detail.html</filename>
    <member kind="typedef">
      <type>decltype(std::declval&lt; T &gt;().to_str())</type>
      <name>to_str_type</name>
      <anchorfile>namespacercppsw_1_1detail.html</anchorfile>
      <anchor>ab58299866908c24e5cb4283812dd0b73</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::ds</name>
    <filename>namespacercppsw_1_1ds.html</filename>
    <namespace>rcppsw::ds::graph</namespace>
    <namespace>rcppsw::ds::metrics</namespace>
    <class kind="class">rcppsw::ds::base_grid2D</class>
    <class kind="class">rcppsw::ds::base_grid3D</class>
    <class kind="class">rcppsw::ds::base_grid_overlay</class>
    <class kind="class">rcppsw::ds::grid2D</class>
    <class kind="class">rcppsw::ds::grid2D_overlay</class>
    <class kind="class">rcppsw::ds::grid3D</class>
    <class kind="class">rcppsw::ds::grid3D_overlay</class>
    <class kind="class">rcppsw::ds::poisson_queue</class>
    <class kind="class">rcppsw::ds::rtree</class>
    <class kind="struct">rcppsw::ds::rtree_spec</class>
    <class kind="class">rcppsw::ds::stacked_grid2D</class>
    <class kind="class">rcppsw::ds::type_map</class>
    <member kind="typedef">
      <type>bg::model::box&lt; rtree_point&lt; TCoordType &gt; &gt;</type>
      <name>rtree_box</name>
      <anchorfile>namespacercppsw_1_1ds.html</anchorfile>
      <anchor>ab6204211b4072bc13dc807ed29c4119e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>bg::model::point&lt; typename TCoordType::value_type, TCoordType::kDIMENSIONALITY, bg::cs::cartesian &gt;</type>
      <name>rtree_point</name>
      <anchorfile>namespacercppsw_1_1ds.html</anchorfile>
      <anchor>a54d5b03ae8dd86c3ba54653e4713325e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>rtree_box&lt; TCoordType &gt;</type>
      <name>make_rtree_box</name>
      <anchorfile>namespacercppsw_1_1ds.html</anchorfile>
      <anchor>a7fa16818dd1112e1177d430d5c62fd4d</anchor>
      <arglist>(const TCoordType &amp;ll, const TCoordType &amp;ur)</arglist>
    </member>
    <member kind="function">
      <type>rtree_point&lt; TCoordType &gt;</type>
      <name>make_rtree_point</name>
      <anchorfile>namespacercppsw_1_1ds.html</anchorfile>
      <anchor>aff578e47a24623687163f1e8449538c7</anchor>
      <arglist>(const TCoordType &amp;c)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::ds::graph</name>
    <filename>namespacercppsw_1_1ds_1_1graph.html</filename>
    <namespace>rcppsw::ds::graph::detail</namespace>
    <class kind="struct">rcppsw::ds::graph::base_vertex_property</class>
    <class kind="class">rcppsw::ds::graph::directed_graph</class>
    <class kind="struct">rcppsw::ds::graph::directed_graph_spec</class>
    <class kind="class">rcppsw::ds::graph::grid_index_map</class>
    <class kind="class">rcppsw::ds::graph::hgrid3D</class>
    <class kind="struct">rcppsw::ds::graph::hgrid3D_spec</class>
    <class kind="struct">rcppsw::ds::graph::hgrid3D_vertex_property</class>
    <class kind="class">rcppsw::ds::graph::hgrid3D_view</class>
    <class kind="class">rcppsw::ds::graph::hgrid3D_view_filter_data</class>
    <member kind="typedef">
      <type>std::function&lt; bool(typename TSpecType::bgl_impl_type::edge_descriptor)&gt;</type>
      <name>hgrid3D_view_edge_filter_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a3d1aea379fd27c507e19570793754cb1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::function&lt; bool(typename TSpecType::bgl_impl_type::vertex_descriptor)&gt;</type>
      <name>hgrid3D_view_vertex_filter_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph.html</anchorfile>
      <anchor>a9ab64f12c0361cab4cae411667f942c0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::ds::graph::detail</name>
    <filename>namespacercppsw_1_1ds_1_1graph_1_1detail.html</filename>
    <class kind="class">rcppsw::ds::graph::detail::hgrid3D_view_builder</class>
    <class kind="class">rcppsw::ds::graph::detail::hgrid3D_view_filter</class>
    <class kind="struct">rcppsw::ds::graph::detail::is_decorator</class>
    <class kind="struct">rcppsw::ds::graph::detail::is_decorator&lt; T, std::void_t&lt; decltype(std::declval&lt; T &gt;().decoratee())&gt; &gt;</class>
    <member kind="typedef">
      <type>typename std::add_pointer&lt; decltype(std::declval&lt; TBGLGraphType &gt;().operator[](std::declval&lt; typename TBGLGraphType::vertex_descriptor &gt;())) &gt;::type</type>
      <name>find_result_type</name>
      <anchorfile>namespacercppsw_1_1ds_1_1graph_1_1detail.html</anchorfile>
      <anchor>a2c9bda01f8c338e7729fe49a9bedb89c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::ds::metrics</name>
    <filename>namespacercppsw_1_1ds_1_1metrics.html</filename>
    <class kind="class">rcppsw::ds::metrics::grid2D_metrics_collector</class>
    <class kind="class">rcppsw::ds::metrics::grid2D_metrics_csv_sink</class>
    <class kind="interface">rcppsw::ds::metrics::grid2D_metrics_data</class>
    <class kind="class">rcppsw::ds::metrics::grid3D_metrics_collector</class>
    <class kind="class">rcppsw::ds::metrics::grid3D_metrics_csv_sink</class>
    <class kind="interface">rcppsw::ds::metrics::grid3D_metrics_data</class>
    <member kind="typedef">
      <type>std::false_type</type>
      <name>cell_accum</name>
      <anchorfile>namespacercppsw_1_1ds_1_1metrics.html</anchorfile>
      <anchor>a0fd0a886443527d9cade0ae0000bcbb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>std::true_type</type>
      <name>cell_avg</name>
      <anchorfile>namespacercppsw_1_1ds_1_1metrics.html</anchorfile>
      <anchor>a8950dadfb171492419a562b3f4f9713c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::er</name>
    <filename>namespacercppsw_1_1er.html</filename>
    <class kind="class">rcppsw::er::client</class>
    <class kind="class">rcppsw::er::stringizable</class>
    <member kind="function">
      <type>void</type>
      <name>sigsegv_sighandler</name>
      <anchorfile>namespacercppsw_1_1er.html</anchorfile>
      <anchor>af85843c56e74e1e6ce8822a09d4615ad</anchor>
      <arglist>(int signum)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>terminate_handler</name>
      <anchorfile>namespacercppsw_1_1er.html</anchorfile>
      <anchor>a50ccdc4c3117669b5d38dd117cae9391</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::math</name>
    <filename>namespacercppsw_1_1math.html</filename>
    <namespace>rcppsw::math::config</namespace>
    <namespace>rcppsw::math::detail</namespace>
    <class kind="class">rcppsw::math::binned_powerlaw_distribution</class>
    <class kind="class">rcppsw::math::bounding_box</class>
    <class kind="class">rcppsw::math::degrees</class>
    <class kind="class">rcppsw::math::ema</class>
    <class kind="class">rcppsw::math::euler_angles</class>
    <class kind="class">rcppsw::math::expression</class>
    <class kind="class">rcppsw::math::ientropy</class>
    <class kind="class">rcppsw::math::powerlaw_distribution</class>
    <class kind="class">rcppsw::math::radians</class>
    <class kind="class">rcppsw::math::range</class>
    <class kind="class">rcppsw::math::rngm</class>
    <class kind="class">rcppsw::math::sigmoid</class>
    <class kind="class">rcppsw::math::sphere_vector</class>
    <class kind="class">rcppsw::math::vector2</class>
    <class kind="class">rcppsw::math::vector3</class>
    <member kind="typedef">
      <type>range&lt; double &gt;</type>
      <name>ranged</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a5ff0a4d528d5429045da4f1d3fd382f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>range&lt; int &gt;</type>
      <name>rangei</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a94eace0e741aaeada9e9e08d8de34e47</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>range&lt; size_t &gt;</type>
      <name>rangez</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>afc75f115f30ec3888181ea1bdd921e17</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector2&lt; double &gt;</type>
      <name>vector2d</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aeee4cbfec7ec35d102de51e287b8edeb</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector2&lt; int &gt;</type>
      <name>vector2i</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a5b451219559579141b097391f9fc0e80</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector2&lt; size_t &gt;</type>
      <name>vector2z</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aa61ac5b9e211ad9913993fe03c12af7c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector3&lt; double &gt;</type>
      <name>vector3d</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af66a56a5aa1b099f8fa9da9a346847f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector3&lt; int &gt;</type>
      <name>vector3i</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a013f4548331430677be3d5c65796845a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>vector3&lt; size_t &gt;</type>
      <name>vector3z</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a72e9a2c7f7fb0b33f22a664371912a36</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>TAngleType</type>
      <name>abs</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a08642e8d3e916a6836bd252d108b4d30</anchor>
      <arglist>(const TAngleType &amp;angle)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rangez</type>
      <name>drange2zrange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a9c696ef894fd3e9030aacf3b89dec0ba</anchor>
      <arglist>(const rangez &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2i</type>
      <name>dvec2ivec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a14ee837e88234393c8920fb33a0824b3</anchor>
      <arglist>(const vector2d &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3i</type>
      <name>dvec2ivec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af7679ef40e012ce00d194ceaf7c536b8</anchor>
      <arglist>(const vector3d &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2z</type>
      <name>dvec2zvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a4a74ff2c01803969fd82df02945e7953</anchor>
      <arglist>(const vector2d &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3z</type>
      <name>dvec2zvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a08e7a8d5d252fa7672c53e387bd6b807</anchor>
      <arglist>(const vector3d &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ranged</type>
      <name>irange2drange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a8d8df93fe4ad4d82761ea7b56bfaee81</anchor>
      <arglist>(const rangei &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ranged</type>
      <name>irange2drange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a9947aa65ad754480dfb5d59827424523</anchor>
      <arglist>(const rangei &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>is_equal</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ad738db774594efe4405af0852fb67c44</anchor>
      <arglist>(double lhs, double rhs, double tol=kDOUBLE_EPSILON)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>is_multiple_of</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a1a70d2e6d2170629c906200b59da2ade</anchor>
      <arglist>(double x, double y, double tol=kDOUBLE_EPSILON)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2d</type>
      <name>ivec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aa961b26521f8d4bca4d3421461cee713</anchor>
      <arglist>(const vector2i &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2d</type>
      <name>ivec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a670395d2d582fe4ca41d6bb7d44bd940</anchor>
      <arglist>(const vector2i &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3d</type>
      <name>ivec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a0a921ed8e23896267d945d86340ffd1d</anchor>
      <arglist>(const vector3i &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3d</type>
      <name>ivec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aff1888ba00c80210c00d8c55ee0dba2d</anchor>
      <arglist>(const vector3i &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static size_t</type>
      <name>l1norm</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a97ff44efd91cc0c6f7bde760e9d62ae1</anchor>
      <arglist>(const vector2&lt; U &gt; &amp;v1, const vector2&lt; V &gt; &amp;v2)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static size_t</type>
      <name>l1norm</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a3da7d798817b70e4de41527fabdbfc2f</anchor>
      <arglist>(const vector3&lt; U &gt; &amp;v1, const vector3&lt; V &gt; &amp;v2)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static double</type>
      <name>l2norm</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a8b3457a654bdbbf2923603c43b00bab0</anchor>
      <arglist>(const T &amp;lhs, const T &amp;rhs)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static double</type>
      <name>l2norm_squared</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a2666dc7f637c4452c0d51cff46ae07a4</anchor>
      <arglist>(const T &amp;lhs, const T &amp;rhs)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static double</type>
      <name>normalize</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a394f87378955773f4b26f4ee11f8e3c9</anchor>
      <arglist>(double min, double max, double val)</arglist>
    </member>
    <member kind="function">
      <type>degrees</type>
      <name>normalized_diff</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ad9e36b73d4cf7997dd91497a11002a31</anchor>
      <arglist>(const degrees &amp;angle1, const degrees &amp;angle2)</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>normalized_diff</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>acbaaea8cea9c437013e1d809eda674d9</anchor>
      <arglist>(const radians &amp;angle1, const radians &amp;angle2)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator*</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af676ea466603dec88e6310deccc2d150</anchor>
      <arglist>(const ema&lt; T &gt; &amp;lhs, const U &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator*</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a6be779cbac1a588dea6bb6ecfcde24cb</anchor>
      <arglist>(const U &amp;lhs, const ema&lt; T &gt; &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>rmath::radians</type>
      <name>operator*</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a502c47e9a9ff5cc05f0424ed28ec799b</anchor>
      <arglist>(double lhs, const rmath::radians &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator-</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ac21a96f6ef02624e0dc8742625e7ccce</anchor>
      <arglist>(const ema&lt; T &gt; &amp;lhs, const U &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator-</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af60bd71ea4af6a585f8c02220b5defe5</anchor>
      <arglist>(const U &amp;lhs, const ema&lt; T &gt; &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator/</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ac0b88164561f83eef7ab6c43cd126b6e</anchor>
      <arglist>(const ema&lt; T &gt; &amp;lhs, const double &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>ema&lt; T &gt;</type>
      <name>operator/</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>afd8c377515b4ac3383951e754edc9d20</anchor>
      <arglist>(const U &amp;lhs, const ema&lt; T &gt; &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ab9a74f174a2ea8affb6bff17a1179394</anchor>
      <arglist>(std::ostream &amp;stream, const degrees &amp;d)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>aca8039f34097e0ab3dbdfe4a05a09cc4</anchor>
      <arglist>(std::ostream &amp;stream, const radians &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a53c97519cd1429ba1ea1ace8ba1e0a4c</anchor>
      <arglist>(const T &amp;v, const ema&lt; T &gt; &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>degrees</type>
      <name>to_degrees</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>af5131d3da982b91cdb4ec521ddac59b8</anchor>
      <arglist>(const radians &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>radians</type>
      <name>to_radians</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a84f217d997fcca5cc7480e6973607a13</anchor>
      <arglist>(const degrees &amp;d)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::ranged</type>
      <name>xspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a06017d6613cca2a80d4313e9c85abfe8</anchor>
      <arglist>(const TCoord &amp;anchor, const double &amp;dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::rangez</type>
      <name>xspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a5fb321b2ade79ebbfd0ef1f3d41559b8</anchor>
      <arglist>(const TCoord &amp;anchor, size_t dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::ranged</type>
      <name>yspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a11db4f529af511f79b50e6750c81e603</anchor>
      <arglist>(const TCoord &amp;anchor, const double &amp;dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::rangez</type>
      <name>yspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a85847e546ad69933d10d3cfc5f909f10</anchor>
      <arglist>(const TCoord &amp;anchor, size_t dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ranged</type>
      <name>zrange2drange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a28a134c46abc211cb7a95e997c856663</anchor>
      <arglist>(const rangez &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ranged</type>
      <name>zrange2drange</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ac5b7f20bdffaad00d3c41740b7a59024</anchor>
      <arglist>(const rangez &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::ranged</type>
      <name>zspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a706469c24348832bda949a85709dd1d8</anchor>
      <arglist>(const TCoord &amp;anchor, const double &amp;dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static rmath::rangez</type>
      <name>zspan</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a33983279d2ba7a443a8a653056a123b7</anchor>
      <arglist>(const TCoord &amp;anchor, size_t dim)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2d</type>
      <name>zvec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a7899ac1ece0936beb822977a9accdfec</anchor>
      <arglist>(const vector2z &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector2d</type>
      <name>zvec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>ae0228cb269b52f2e835336b600b533aa</anchor>
      <arglist>(const vector2z &amp;other, double scale)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3d</type>
      <name>zvec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a6590e524799ca25849ac5a49f93e07ee</anchor>
      <arglist>(const vector3z &amp;other)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static vector3d</type>
      <name>zvec2dvec</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a454f55be44625cec03576bd2641e4a96</anchor>
      <arglist>(const vector3z &amp;other, double scale)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static constexpr double</type>
      <name>kDOUBLE_EPSILON</name>
      <anchorfile>namespacercppsw_1_1math.html</anchorfile>
      <anchor>a3de3b99c93e96d09928476864d7ecf59</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::math::config</name>
    <filename>namespacercppsw_1_1math_1_1config.html</filename>
    <namespace>rcppsw::math::config::xml</namespace>
    <class kind="struct">rcppsw::math::config::ema_config</class>
    <class kind="struct">rcppsw::math::config::rng_config</class>
    <class kind="struct">rcppsw::math::config::sigmoid_config</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::math::config::xml</name>
    <filename>namespacercppsw_1_1math_1_1config_1_1xml.html</filename>
    <class kind="class">rcppsw::math::config::xml::ema_parser</class>
    <class kind="class">rcppsw::math::config::xml::rng_parser</class>
    <class kind="class">rcppsw::math::config::xml::sigmoid_parser</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::math::detail</name>
    <filename>namespacercppsw_1_1math_1_1detail.html</filename>
    <member kind="typedef">
      <type>decltype(std::declval&lt; T &gt;().length())</type>
      <name>length_func_decltype</name>
      <anchorfile>namespacercppsw_1_1math_1_1detail.html</anchorfile>
      <anchor>a8df4a58ef0ebabc5c34175ea202ab1db</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::metrics</name>
    <filename>namespacercppsw_1_1metrics.html</filename>
    <namespace>rcppsw::metrics::config</namespace>
    <namespace>rcppsw::metrics::detail</namespace>
    <class kind="class">rcppsw::metrics::base_collector</class>
    <class kind="interface">rcppsw::metrics::base_data</class>
    <class kind="class">rcppsw::metrics::base_manager</class>
    <class kind="interface">rcppsw::metrics::base_metrics</class>
    <class kind="class">rcppsw::metrics::base_sink</class>
    <class kind="class">rcppsw::metrics::collector_group</class>
    <class kind="struct">rcppsw::metrics::collector_registration_spec</class>
    <class kind="struct">rcppsw::metrics::creatable_collector_spec</class>
    <class kind="class">rcppsw::metrics::csv_sink</class>
    <class kind="class">rcppsw::metrics::file_sink</class>
    <class kind="class">rcppsw::metrics::file_sink_registerer</class>
    <class kind="class">rcppsw::metrics::fs_output_manager</class>
    <class kind="class">rcppsw::metrics::network_output_manager</class>
    <class kind="class">rcppsw::metrics::network_sink</class>
    <class kind="class">rcppsw::metrics::network_sink_registerer</class>
    <class kind="class">rcppsw::metrics::register_using_config</class>
    <class kind="class">rcppsw::metrics::register_with_sink</class>
    <member kind="typedef">
      <type>std::multiset&lt; creatable_collector_spec, detail::creatable_collector_set_comparator &gt;</type>
      <name>creatable_collector_set</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>adc89b6e34f69346cce13197bc5c01330</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>output_mode</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>ac42f08cd0253142d3dacdf5339f3587f</anchor>
      <arglist></arglist>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587fa46ea291249caff31653a439e2a7fed9c">ekNONE</enumvalue>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587faeb6d39ff8f11b0c4148abaf0b9da90c5">ekAPPEND</enumvalue>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587fa36e7d4cce81688522a04e5435c1512d9">ekTRUNCATE</enumvalue>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587fa46f4cb8693fdba815a1187d688f3580e">ekCREATE</enumvalue>
      <enumvalue file="namespacercppsw_1_1metrics.html" anchor="ac42f08cd0253142d3dacdf5339f3587fafcb9fec17836aea1b6069f9d19f72f50">ekSTREAM</enumvalue>
    </member>
    <member kind="enumeration">
      <type></type>
      <name>write_status</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a9deb89f55ed769b27bdaf97be97c3d5b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekNO_ATTEMPT</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a9deb89f55ed769b27bdaf97be97c3d5baa58c01134d64c97192932b3f98d2647d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekFAILED</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a9deb89f55ed769b27bdaf97be97c3d5bab30168a8c0e4f097972513b87708bdc6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ekSUCCESS</name>
      <anchorfile>namespacercppsw_1_1metrics.html</anchorfile>
      <anchor>a9deb89f55ed769b27bdaf97be97c3d5ba2dbb241488e975a9a3ff19065d293570</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::metrics::config</name>
    <filename>namespacercppsw_1_1metrics_1_1config.html</filename>
    <namespace>rcppsw::metrics::config::xml</namespace>
    <class kind="struct">rcppsw::metrics::config::file_sink_config</class>
    <class kind="struct">rcppsw::metrics::config::metrics_config</class>
    <class kind="struct">rcppsw::metrics::config::network_sink_config</class>
    <class kind="struct">rcppsw::metrics::config::output_mode_config</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::metrics::config::xml</name>
    <filename>namespacercppsw_1_1metrics_1_1config_1_1xml.html</filename>
    <class kind="class">rcppsw::metrics::config::xml::base_sink_parser</class>
    <class kind="class">rcppsw::metrics::config::xml::file_sink_parser</class>
    <class kind="class">rcppsw::metrics::config::xml::metrics_parser</class>
    <class kind="class">rcppsw::metrics::config::xml::network_sink_parser</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::metrics::detail</name>
    <filename>namespacercppsw_1_1metrics_1_1detail.html</filename>
    <class kind="struct">rcppsw::metrics::detail::creatable_collector_set_comparator</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::mpl</name>
    <filename>namespacercppsw_1_1mpl.html</filename>
    <namespace>rcppsw::mpl::detail</namespace>
    <class kind="struct">rcppsw::mpl::can_static_cast</class>
    <class kind="struct">rcppsw::mpl::can_static_cast&lt; T, U, std::void_t&lt; decltype(static_cast&lt; U &gt;(std::declval&lt; T &gt;()))&gt; &gt;</class>
    <class kind="class">rcppsw::mpl::identity</class>
    <class kind="struct">rcppsw::mpl::is_specialization</class>
    <class kind="struct">rcppsw::mpl::is_specialization&lt; Template&lt; Args... &gt;, Template &gt;</class>
    <class kind="struct">rcppsw::mpl::no_such_trait</class>
    <class kind="class">rcppsw::mpl::reflectable</class>
    <class kind="struct">rcppsw::mpl::typelist_wrap_into</class>
    <member kind="typedef">
      <type>detail::detector&lt; TFailType, void, TFuncDecltype, Args... &gt;</type>
      <name>detected_or</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a06f783c764e189077611aff2eb5b3677</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename detail::detector&lt; no_such_trait, void, TFuncDecltype, Args... &gt;::type</type>
      <name>detected_t</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a03714aecbca890aef4edc33a86e331c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::mpl::empty&lt; Ts... &gt;</type>
      <name>empty</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a95f260d74410ea011c23268337bd9d02</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename detail::detector&lt; no_such_trait, void, TFuncDecltype, Args... &gt;::value</type>
      <name>is_detected</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>aa2874711ad74f595a443da11e77fdbf2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename boost::mpl::fold&lt; typename boost::mpl::fold&lt; Seq, boost::mpl::set&lt;&gt;, boost::mpl::insert&lt; boost::mpl::_1, boost::mpl::_2 &gt; &gt;::type, boost::tuple&lt; void &gt;, detail::ExtendTList&lt; boost::mpl::_1, boost::mpl::_2 &gt; &gt;</type>
      <name>make_tuple_type</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a7253bb9de384d7440b6631c56dd4fea3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename detail::rename_impl&lt; A, B &gt;</type>
      <name>rename</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a8f16170d63177182637c57126fa14c70</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>boost::mpl::vector&lt; Ts... &gt;</type>
      <name>typelist</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>a087641491e12b257b1c6ecf5414aa192</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>typename boost::mpl::transform&lt; Typelist, typelist_wrap_into&lt; WrapperType, Args... &gt; &gt;</type>
      <name>typelist_wrap_apply</name>
      <anchorfile>namespacercppsw_1_1mpl.html</anchorfile>
      <anchor>af62bfb86a6e582b117607194c2e0ec8e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::mpl::detail</name>
    <filename>namespacercppsw_1_1mpl_1_1detail.html</filename>
    <class kind="struct">rcppsw::mpl::detail::detector</class>
    <class kind="struct">rcppsw::mpl::detail::detector&lt; TFailType, std::void_t&lt; TFuncDecltype&lt; Args... &gt; &gt;, TFuncDecltype, Args... &gt;</class>
    <class kind="struct">rcppsw::mpl::detail::ExtendTList</class>
    <class kind="struct">rcppsw::mpl::detail::ExtendTList&lt; std::tuple&lt; Ts... &gt;, T &gt;</class>
    <class kind="struct">rcppsw::mpl::detail::ExtendTList&lt; std::tuple&lt; void &gt;, T &gt;</class>
    <class kind="struct">rcppsw::mpl::detail::rename_impl</class>
    <class kind="struct">rcppsw::mpl::detail::rename_impl&lt; A&lt; T... &gt;, B &gt;</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::multiprocess</name>
    <filename>namespacercppsw_1_1multiprocess.html</filename>
    <class kind="class">rcppsw::multiprocess::forkable</class>
    <class kind="class">rcppsw::multiprocess::ipc_queue</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::multithread</name>
    <filename>namespacercppsw_1_1multithread.html</filename>
    <class kind="class">rcppsw::multithread::lockable</class>
    <class kind="class">rcppsw::multithread::mt_fsm</class>
    <class kind="class">rcppsw::multithread::mt_queue</class>
    <class kind="class">rcppsw::multithread::mt_vector</class>
    <class kind="class">rcppsw::multithread::threadable</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns</name>
    <filename>namespacercppsw_1_1patterns.html</filename>
    <namespace>rcppsw::patterns::decorator</namespace>
    <namespace>rcppsw::patterns::factory</namespace>
    <namespace>rcppsw::patterns::fsm</namespace>
    <namespace>rcppsw::patterns::pimpl</namespace>
    <namespace>rcppsw::patterns::prototype</namespace>
    <namespace>rcppsw::patterns::singleton</namespace>
    <namespace>rcppsw::patterns::visitor</namespace>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns::decorator</name>
    <filename>namespacercppsw_1_1patterns_1_1decorator.html</filename>
    <class kind="class">rcppsw::patterns::decorator::decorator</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns::factory</name>
    <filename>namespacercppsw_1_1patterns_1_1factory.html</filename>
    <namespace>rcppsw::patterns::factory::detail</namespace>
    <class kind="class">rcppsw::patterns::factory::releasing_factory</class>
    <class kind="class">rcppsw::patterns::factory::sharing_factory</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns::factory::detail</name>
    <filename>namespacercppsw_1_1patterns_1_1factory_1_1detail.html</filename>
    <class kind="class">rcppsw::patterns::factory::detail::base_factory</class>
    <class kind="struct">rcppsw::patterns::factory::detail::factory_releasing_type</class>
    <class kind="struct">rcppsw::patterns::factory::detail::factory_sharing_type</class>
    <class kind="class">rcppsw::patterns::factory::detail::factory_singleton</class>
    <class kind="class">rcppsw::patterns::factory::detail::multifactory</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns::fsm</name>
    <filename>namespacercppsw_1_1patterns_1_1fsm.html</filename>
    <class kind="class">rcppsw::patterns::fsm::base_fsm</class>
    <class kind="class">rcppsw::patterns::fsm::event_data</class>
    <class kind="class">rcppsw::patterns::fsm::event_signal</class>
    <class kind="class">rcppsw::patterns::fsm::event_type</class>
    <class kind="class">rcppsw::patterns::fsm::hfsm</class>
    <class kind="class">rcppsw::patterns::fsm::hfsm_state</class>
    <class kind="class">rcppsw::patterns::fsm::hfsm_state_action0</class>
    <class kind="class">rcppsw::patterns::fsm::hfsm_state_action1</class>
    <class kind="class">rcppsw::patterns::fsm::no_event_data</class>
    <class kind="class">rcppsw::patterns::fsm::state</class>
    <class kind="class">rcppsw::patterns::fsm::state_action0</class>
    <class kind="class">rcppsw::patterns::fsm::state_action1</class>
    <class kind="class">rcppsw::patterns::fsm::state_entry</class>
    <class kind="class">rcppsw::patterns::fsm::state_entry_action0</class>
    <class kind="class">rcppsw::patterns::fsm::state_entry_action1</class>
    <class kind="class">rcppsw::patterns::fsm::state_exit</class>
    <class kind="class">rcppsw::patterns::fsm::state_exit_action</class>
    <class kind="class">rcppsw::patterns::fsm::state_guard</class>
    <class kind="class">rcppsw::patterns::fsm::state_guard_condition0</class>
    <class kind="class">rcppsw::patterns::fsm::state_guard_condition1</class>
    <class kind="class">rcppsw::patterns::fsm::state_map_ex_row</class>
    <class kind="class">rcppsw::patterns::fsm::state_map_row</class>
    <member kind="typedef">
      <type>base_fsm</type>
      <name>simple_fsm</name>
      <anchorfile>namespacercppsw_1_1patterns_1_1fsm.html</anchorfile>
      <anchor>af9a95d8b12a4275318c36b763fce11c9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns::pimpl</name>
    <filename>namespacercppsw_1_1patterns_1_1pimpl.html</filename>
    <class kind="class">rcppsw::patterns::pimpl::pimpl</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns::prototype</name>
    <filename>namespacercppsw_1_1patterns_1_1prototype.html</filename>
    <class kind="class">rcppsw::patterns::prototype::caching_factory</class>
    <class kind="class">rcppsw::patterns::prototype::clonable</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns::singleton</name>
    <filename>namespacercppsw_1_1patterns_1_1singleton.html</filename>
    <class kind="class">rcppsw::patterns::singleton::singleton</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns::visitor</name>
    <filename>namespacercppsw_1_1patterns_1_1visitor.html</filename>
    <namespace>rcppsw::patterns::visitor::detail</namespace>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::patterns::visitor::detail</name>
    <filename>namespacercppsw_1_1patterns_1_1visitor_1_1detail.html</filename>
    <class kind="class">rcppsw::patterns::visitor::detail::polymorphic_accept_set_helper</class>
    <class kind="class">rcppsw::patterns::visitor::detail::visit_set_helper</class>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::types</name>
    <filename>namespacercppsw_1_1types.html</filename>
    <class kind="class">rcppsw::types::distance_measure</class>
    <class kind="class">rcppsw::types::manhattan_dist</class>
    <class kind="class">rcppsw::types::named_type</class>
    <class kind="class">rcppsw::types::spatial_dist</class>
    <class kind="class">rcppsw::types::timestep</class>
    <member kind="typedef">
      <type>named_type&lt; double, struct discretize_ratio_tag &gt;</type>
      <name>discretize_ratio</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ae7dfad2612de94a0c90840e1e872dfa0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>math::range&lt; types::spatial_dist &gt;</type>
      <name>spatial_range</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ab416cfd1a6af16a3dec61d9ae8f5ce6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator*</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>aef760b91a956f697f983d4cb76adcc90</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator+</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ae02d68adeec2cc3ab1bc30dd738f0730</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator+</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>a27802aa16293b7b518133955db138a4b</anchor>
      <arglist>(int lhs, const manhattan_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator-</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ac6dd93090803a932374969b7a697bad0</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>manhattan_dist</type>
      <name>operator-</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>a3f4858fc7f1c09ed8666732797def584</anchor>
      <arglist>(int lhs, const manhattan_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>spatial_dist</type>
      <name>operator/</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ac584d6f672ae57b8a27cb5ddf7fbca7b</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>a606bae202ce4cf5a0697a4b72ced5b6f</anchor>
      <arglist>(double lhs, const spatial_dist &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespacercppsw_1_1types.html</anchorfile>
      <anchor>ac22882e200d1ff6bc2933e156640e01d</anchor>
      <arglist>(int lhs, const manhattan_dist &amp;rhs)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>rcppsw::utils</name>
    <filename>namespacercppsw_1_1utils.html</filename>
    <class kind="class">rcppsw::utils::base_cli</class>
    <class kind="class">rcppsw::utils::color</class>
    <class kind="class">rcppsw::utils::file_parser</class>
    <class kind="class">rcppsw::utils::line_parser</class>
    <member kind="function">
      <type>bool</type>
      <name>parse_values</name>
      <anchorfile>namespacercppsw_1_1utils.html</anchorfile>
      <anchor>a24de48f591600b86f2163575d342cfe3</anchor>
      <arglist>(std::istream &amp;is, size_t n_fields, T *buf, char delim=&apos;\n&apos;)</arglist>
    </member>
  </compound>
</tagfile>
